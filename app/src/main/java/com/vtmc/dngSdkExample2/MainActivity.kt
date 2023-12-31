package com.vtmc.dngSdkExample2

import android.content.Intent
import android.content.res.AssetManager
import android.graphics.BitmapFactory
import android.os.Bundle
import android.util.Log
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.vtmc.dngSdkExample2.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var viewBinding : ActivityMainBinding

    companion object{
        private const val REQUEST_CODE=0
        init{
            System.loadLibrary("native-lib")
        }

        external fun helloJni() : String
        external fun AImageDecoder_Jni(path : String, asset: AssetManager) : Void
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        viewBinding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(viewBinding.root)

        val checkBtn = viewBinding.checkBtn
        val rgbText = viewBinding.RGBTxt
        val imageSelectBtn = viewBinding.imageSelectBtn

        val testText = helloJni()
        rgbText.text = "R:$testText\nG:$testText\nB:$testText"

        checkBtn.setOnClickListener {
            val x_val = viewBinding.xValueTxt.text
            val y_val = viewBinding.yValueTxt.text

            viewBinding.XYTxt.text = "X:${x_val} / Y:${y_val}"
        }

        imageSelectBtn.setOnClickListener {
            val intent = Intent()
            intent.setType("image/x-adobe-dng")
            intent.setAction(Intent.ACTION_GET_CONTENT)
            startActivityForResult(intent, REQUEST_CODE)
        }

    }
    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        super.onActivityResult(requestCode, resultCode, data)

        if(requestCode == REQUEST_CODE){
            if(resultCode == RESULT_OK){
                try{
                    val image_IS = contentResolver.openInputStream(data!!.data!!)

                    val image_path = data!!.data!!.path

//                    val assets = this.assets
//                    AImageDecoder_Jni(image_path!!, assets)

                    val bmp_img = BitmapFactory.decodeStream(image_IS)
                    image_IS!!.close()

                    val img_width = bmp_img.width
                    val img_height = bmp_img.height
                    viewBinding.imageSizeTxt.text = "w : ${img_width} / h : ${img_height}"

                    viewBinding.XYTxt.text = "X : ${img_width/2} / Y : ${img_height / 2}"

                    viewBinding.selectedImageView.setImageBitmap(bmp_img)
                }catch(e : Exception){
                    Log.e("KSM", "Loading Image Error!!!", e)
                }
            }else if(resultCode == RESULT_CANCELED){
                Toast.makeText(this, "사진 선택 취소", Toast.LENGTH_LONG).show()
            }
        }
    }
}