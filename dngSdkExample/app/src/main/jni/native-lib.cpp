#include <string>
#include <jni.h>

extern "C"
JNIEXPORT void JNICALL
Java_com_example_myapplication_MainActivity_00024Companion_helloJni(JNIEnv* env, jobject thiz) {
// TODO: implement helloJni()

    std::string test = "testing...";

    return env->NewStringUTF(test.c_str());
}
extern "C"
JNIEXPORT jobject