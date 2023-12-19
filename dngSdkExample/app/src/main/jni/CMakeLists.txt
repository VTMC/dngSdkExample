cmake_minimum_required(VERSION 3.4.1)

#네이티브 라이브러리 생성
add_library(native-lib SHARED src/main/jni/native-lib.cpp)

#타겟 링크
target_link_libraries(native-lib log)

#라이브러리 이름 설정
set_target_properties(native-lib PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}")