cmake_minimum_required(VERSION 3.4.1)
project("dngSdkExample")

#프로젝트 위치 설정
#set(pathPROJECT "${CMAKE_CURRENT_SOURCE_DIR}/../../../..")
#message("project Path : ${pathPROJECT}")

#set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")


#네이티브 라이브러리 생성
set(CPP_FILES native-lib.cpp)
#add_library(dngSdkExample2 SHARED native-lib.cpp)
add_library(dngSdkExample SHARED ${CPP_FILES})

#DNG_SDK Path 설정
#set(LOCAL_PATH "${pathPROJECT}/app/src/main/jni/dng_sdk-c70264282305351abbec9b967333db4d896583b9")
#set(CMAKE_CXX_FLAGS "-DANDROID_ABI=arm64-v8a -DLIBRAW_NOTHREADS -fexceptions -D_FILE_OFFSET_BITS=64 -D__USE_FILE_OFFSET64 -DLIBRAW_OWN_SWAB -D_LIBCPP_HAS_NO_OFF_T_FUNCTIONS -DANDROID_PLATFORM=android-33") #-D_LARGEFILE_SOURCE -fno-rtti
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/src/main/libs/${ANDROID_ABI})
#set(LOCAL_SRC_FILES ${LOCAL_PATH}/source/dng_1d_function.cpp
#        ${LOCAL_PATH}/source/dng_1d_table.cpp
#        ${LOCAL_PATH}/source/dng_abort_sniffer.cpp
#        ${LOCAL_PATH}/source/dng_area_task.cpp
#        ${LOCAL_PATH}/source/dng_bad_pixels.cpp
#        ${LOCAL_PATH}/source/dng_bottlenecks.cpp
#        ${LOCAL_PATH}/source/dng_camera_profile.cpp
#        ${LOCAL_PATH}/source/dng_color_space.cpp
#        ${LOCAL_PATH}/source/dng_color_spec.cpp
#        ${LOCAL_PATH}/source/dng_date_time.cpp
#        ${LOCAL_PATH}/source/dng_exceptions.cpp
#        ${LOCAL_PATH}/source/dng_exif.cpp
#        ${LOCAL_PATH}/source/dng_file_stream.cpp
#        ${LOCAL_PATH}/source/dng_filter_task.cpp
#        ${LOCAL_PATH}/source/dng_fingerprint.cpp
#        ${LOCAL_PATH}/source/dng_gain_map.cpp
#        ${LOCAL_PATH}/source/dng_globals.cpp
#        ${LOCAL_PATH}/source/dng_host.cpp
#        ${LOCAL_PATH}/source/dng_hue_sat_map.cpp
#        ${LOCAL_PATH}/source/dng_ifd.cpp
#        ${LOCAL_PATH}/source/dng_image.cpp
#        ${LOCAL_PATH}/source/dng_image_writer.cpp
#        ${LOCAL_PATH}/source/dng_info.cpp
#        ${LOCAL_PATH}/source/dng_iptc.cpp
#        ${LOCAL_PATH}/source/dng_jpeg_image.cpp
#        ${LOCAL_PATH}/source/dng_jpeg_memory_source.cpp
#        ${LOCAL_PATH}/source/dng_lens_correction.cpp
#        ${LOCAL_PATH}/source/dng_linearization_info.cpp
#        ${LOCAL_PATH}/source/dng_lossless_jpeg.cpp
#        ${LOCAL_PATH}/source/dng_matrix.cpp
#        ${LOCAL_PATH}/source/dng_memory.cpp
#        ${LOCAL_PATH}/source/dng_memory_stream.cpp
#        ${LOCAL_PATH}/source/dng_misc_opcodes.cpp
#        ${LOCAL_PATH}/source/dng_mosaic_info.cpp
#        ${LOCAL_PATH}/source/dng_mutex.cpp
#        ${LOCAL_PATH}/source/dng_negative.cpp
#        ${LOCAL_PATH}/source/dng_opcode_list.cpp
#        ${LOCAL_PATH}/source/dng_opcodes.cpp
#        ${LOCAL_PATH}/source/dng_orientation.cpp
#        ${LOCAL_PATH}/source/dng_parse_utils.cpp
#        ${LOCAL_PATH}/source/dng_pixel_buffer.cpp
#        ${LOCAL_PATH}/source/dng_point.cpp
#        ${LOCAL_PATH}/source/dng_preview.cpp
#        ${LOCAL_PATH}/source/dng_pthread.cpp
#        ${LOCAL_PATH}/source/dng_rational.cpp
#        ${LOCAL_PATH}/source/dng_read_image.cpp
#        ${LOCAL_PATH}/source/dng_rect.cpp
#        ${LOCAL_PATH}/source/dng_ref_counted_block.cpp
#        ${LOCAL_PATH}/source/dng_reference.cpp
#        ${LOCAL_PATH}/source/dng_render.cpp
#        ${LOCAL_PATH}/source/dng_resample.cpp
#        ${LOCAL_PATH}/source/dng_safe_arithmetic.cpp
#        ${LOCAL_PATH}/source/dng_shared.cpp
#        ${LOCAL_PATH}/source/dng_simple_image.cpp
#        ${LOCAL_PATH}/source/dng_spline.cpp
#        ${LOCAL_PATH}/source/dng_stream.cpp
#        ${LOCAL_PATH}/source/dng_string.cpp
#        ${LOCAL_PATH}/source/dng_string_list.cpp
#        ${LOCAL_PATH}/source/dng_tag_types.cpp
#        ${LOCAL_PATH}/source/dng_temperature.cpp
#        ${LOCAL_PATH}/source/dng_tile_iterator.cpp
#        ${LOCAL_PATH}/source/dng_tone_curve.cpp
#        ${LOCAL_PATH}/source/dng_utils.cpp
#        ${LOCAL_PATH}/source/dng_xy_coord.cpp
#        ${LOCAL_PATH}/source/dng_xmp.cpp
#        )

#add_library(dng_sdk SHARED ${LOCAL_SRC_FILES})

# Set compiler flags
#target_compile_options(dng_sdk PRIVATE
#        -DUNIX_ENV=1 -DqDNGBigEndian=0 -DqDNGThreadSafe=1
#        -DqDNGUseLibJPEG=1 -DqDNGUseXMP=0 -DqDNGValidate=0
#        -DqDNGValidateTarget=1 -DqAndroid=1
#        -Wsign-compare -Wno-reorder -Wframe-larger-than=20000
#        )


#타겟 링크
#target_link_libraries(dngSdkExample ${log-lib} android)
#target_include_directories(dng_sdk PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source)
#target_link_libraries(dng_sdk PRIVATE ${JPEG_LIBRARIES})

find_library(log-lib log)

#타겟 링크
#target_link_libraries(dngSdkExample PRIVATE dng_sdk ${log-lib} android)
target_link_libraries(dngSdkExample ${log-lib} android)