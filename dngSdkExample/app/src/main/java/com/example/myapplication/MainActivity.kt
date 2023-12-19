package com.example.myapplication

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.example.myapplication.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var viewBinding : ActivityMainBinding

    companion object{
        private external fun helloJni()

    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        viewBinding = ActivityMainBinding.inflate(layoutInflater)

        val checkBtn = viewBinding.checkBtn
        val rgbText = viewBinding.RGBTxt

        val testText = helloJni()
        rgbText.text = testText
    }
}