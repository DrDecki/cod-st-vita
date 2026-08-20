cmake_minimum_required(VERSION 3.10)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

project(codst C CXX)

include("${VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "Call of Duty Sierra")
set(VITA_TITLEID "CODST0001")

add_definitions(
  -D__PSVITA__
  -D__VITA__
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-deprecated-declarations -Wno-write-strings -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations -Wno-write-strings -O2")

include_directories(
  ${CMAKE_SOURCE_DIR}/main
  ${CMAKE_SOURCE_DIR}/main/falsojni
  ${CMAKE_SOURCE_DIR}/main/so_util
)

file(GLOB_RECURSE SOURCES
  "main/*.c"
  "main/*.cpp"
)

add_executable(codst ${SOURCES})
set_target_properties(codst PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(codst
  vitaGL mathneon
  SceShaccCg_stub
  SceGxm_stub
  SceDisplay_stub
  SceCtrl_stub
  SceAudio_stub
  SceAudioIn_stub
  SceSysmodule_stub
  SceTouch_stub
  SceMotion_stub
  SceAppMgr_stub
  SceAppUtil_stub
  ScePgf_stub
  SceCommonDialog_stub
  ScePower_stub
  m
  c
)

vita_create_vpk(codst.vpk ${VITA_TITLEID} codst
  VERSION "01.00"
  NAME ${VITA_APP_NAME}
)
