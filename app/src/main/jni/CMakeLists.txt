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
#set(LOCAL_PATH "${pathPROJECT}/app/src/main/jni/dngSdk")
#set(CMAKE_CXX_FLAGS "-DANDROID_ABI=arm64-v8a -DLIBRAW_NOTHREADS -fexceptions -D_FILE_OFFSET_BITS=64 -D__USE_FILE_OFFSET64 -DLIBRAW_OWN_SWAB -D_LIBCPP_HAS_NO_OFF_T_FUNCTIONS -DANDROID_PLATFORM=android-33") #-D_LARGEFILE_SOURCE -fno-rtti
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/src/main/libs/${ANDROID_ABI})
#set(LOCAL_SRC_FILES ${LOCAL_PATH}/dng_1d_function.cpp ${LOCAL_PATH}/dng_1d_table.cpp ${LOCAL_PATH}/dng_abort_sniffer.cpp ${LOCAL_PATH}/dng_area_task.cpp
#        ${LOCAL_PATH}/dng_bad_pixels.cpp ${LOCAL_PATH}/dng_big_table.cpp ${LOCAL_PATH}/dng_bmff.cpp ${LOCAL_PATH}/dng_bottlenecks.cpp ${LOCAL_PATH}/dng_camera_profile.cpp
#        ${LOCAL_PATH}/dng_color_space.cpp ${LOCAL_PATH}/dng_color_spec.cpp ${LOCAL_PATH}/dng_date_time.cpp ${LOCAL_PATH}/dng_exceptions.cpp ${LOCAL_PATH}/dng_exif.cpp
#        ${LOCAL_PATH}/dng_file_stream.cpp ${LOCAL_PATH}/dng_filter_task.cpp ${LOCAL_PATH}/dng_fingerprint.cpp ${LOCAL_PATH}/dng_gain_map.cpp ${LOCAL_PATH}/dng_globals.cpp
#        ${LOCAL_PATH}/dng_host.cpp ${LOCAL_PATH}/dng_hue_sat_map.cpp ${LOCAL_PATH}/dng_ifd.cpp ${LOCAL_PATH}/dng_image.cpp ${LOCAL_PATH}/dng_image_writer.cpp
#        ${LOCAL_PATH}/dng_info.cpp ${LOCAL_PATH}/dng_iptc.cpp ${LOCAL_PATH}/dng_jpeg_image.cpp ${LOCAL_PATH}/dng_jpeg_memory_source.cpp ${LOCAL_PATH}/dng_jxl.cpp
#        ${LOCAL_PATH}/dng_lens_correction.cpp ${LOCAL_PATH}/dng_linearization_info.cpp ${LOCAL_PATH}/dng_local_string.cpp ${LOCAL_PATH}/dng_lossless_jpeg.cpp
#        ${LOCAL_PATH}/dng_lossless_jpeg_shared.cpp ${LOCAL_PATH}/dng_matrix.cpp ${LOCAL_PATH}/dng_memory.cpp ${LOCAL_PATH}/dng_memory_stream.cpp ${LOCAL_PATH}/dng_misc_opcodes.cpp
#        ${LOCAL_PATH}/dng_mosaic_info.cpp ${LOCAL_PATH}/dng_mutex.cpp ${LOCAL_PATH}/dng_negative.cpp ${LOCAL_PATH}/dng_opcode_list.cpp ${LOCAL_PATH}/dng_opcodes.cpp
#        ${LOCAL_PATH}/dng_orientation.cpp ${LOCAL_PATH}/dng_parse_utils.cpp ${LOCAL_PATH}/dng_pixel_buffer.cpp ${LOCAL_PATH}/dng_point.cpp ${LOCAL_PATH}/dng_preview.cpp
#        ${LOCAL_PATH}/dng_pthread.cpp ${LOCAL_PATH}/dng_rational.cpp ${LOCAL_PATH}/dng_read_image.cpp ${LOCAL_PATH}/dng_rect.cpp ${LOCAL_PATH}/dng_ref_counted_block.cpp
#        ${LOCAL_PATH}/dng_reference.cpp ${LOCAL_PATH}/dng_render.cpp ${LOCAL_PATH}/dng_resample.cpp ${LOCAL_PATH}/dng_safe_arithmetic.cpp ${LOCAL_PATH}/dng_shared.cpp
#        ${LOCAL_PATH}/dng_simple_image.cpp ${LOCAL_PATH}/dng_spline.cpp ${LOCAL_PATH}/dng_stream.cpp ${LOCAL_PATH}/dng_string.cpp ${LOCAL_PATH}/dng_string_list.cpp
#        ${LOCAL_PATH}/dng_tag_types.cpp ${LOCAL_PATH}/dng_temperature.cpp ${LOCAL_PATH}/dng_tile_iterator.cpp ${LOCAL_PATH}/dng_tone_curve.cpp ${LOCAL_PATH}/dng_update_meta.cpp
#        ${LOCAL_PATH}/dng_utils.cpp ${LOCAL_PATH}/dng_validate.cpp ${LOCAL_PATH}/dng_xmp.cpp ${LOCAL_PATH}/dng_xmp_sdk.cpp ${LOCAL_PATH}/dng_xy_coord.cpp)
#
#add_library(dng_sdk SHARED ${LOCAL_SRC_FILES})

find_library(log-lib log)

#타겟 링크
#target_link_libraries(dngSdkExample dng_sdk ${log-lib})

#타겟 링크
target_link_libraries(dngSdkExample ${log-lib} android)