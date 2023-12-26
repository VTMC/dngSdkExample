#include <jni.h>
#include <string>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <android/imagedecoder.h>
#include <android/bitmap.h>
#include <android/log.h>

#define LOG_TAG "KSM"
#define LOGUNK(...) __android_log_print(ANDROID_LOG_UNKNOWN, LOG_TAG, __VA_ARGS__)
#define LOGDEF(...) __android_log_print(ANDROID_LOG_DEFAULT, LOG_TAG, __VA_ARGS__)
#define  LOGV(...)  __android_log_print(ANDROID_LOG_VERBOSE,LOG_TAG,__VA_ARGS__)
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define  LOGF(...)  __android_log_print(ANDROID_FATAL_ERROR,LOG_TAG,__VA_ARGS__)
#define  LOGS(...)  __android_log_print(ANDROID_SILENT_ERROR,LOG_TAG,__VA_ARGS__)

extern "C"
JNIEXPORT jstring JNICALL
Java_com_vtmc_dngSdkExample2_MainActivity_00024Companion_helloJni(JNIEnv *env, jobject thiz) {
    // TODO: implement helloJni()

    std::string test = "testing...";

    return env->NewStringUTF(test.c_str());
}


extern "C"
JNIEXPORT jobject JNICALL
Java_com_vtmc_dngSdkExample2_MainActivity_00024Companion_AImageDecoder_1Jni(JNIEnv *env,
                                                                            jobject thiz,
                                                                            jstring path,
                                                                            jobject jassets) {
    // TODO: implement AImageDecoder_Jni()

    AAssetManager* nativeManager = AAssetManager_fromJava(env, jassets);
    const char* file = env ->GetStringUTFChars(path, 0);
    AAsset* asset = AAssetManager_open(nativeManager, file, AASSET_MODE_STREAMING);
    AImageDecoder* decoder;
    int result = AImageDecoder_createFromAAsset(asset, &decoder);
    if(result != ANDROID_IMAGE_DECODER_SUCCESS){
        LOGE("[NATIVE] AImageDecoder_Jni : Asset으로 이미지 불러오기 실패");
    }else{
        LOGI("[NATIVE] AImageDecoder_Jni : Asset으로 이미지 불러옴");
    }

    const AImageDecoderHeaderInfo* info = AImageDecoder_getHeaderInfo(decoder);
    int32_t image_W = AImageDecoderHeaderInfo_getWidth(info);
    int32_t image_H = AImageDecoderHeaderInfo_getHeight(info);
    AndroidBitmapFormat format = (AndroidBitmapFormat) AImageDecoderHeaderInfo_getAndroidBitmapFormat(info);
    size_t stride = AImageDecoder_getMinimumStride(decoder);
    size_t size = image_H*stride;
    void* pixels = malloc(size);

    result = AImageDecoder_decodeImage(decoder, pixels, stride, size);
    if(result != ANDROID_IMAGE_DECODER_SUCCESS){
        LOGE("[NATIVE] AImageDecoder_Jni : 이미지 디코딩 실패");
    }else{
        LOGI("[NATIVE] AImageDecoder_Jni : 이미지 디코딩 성공");
    }

    AImageDecoder_delete(decoder);
    AAsset_close(asset);



    free(pixels);
}