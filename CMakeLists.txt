cmake_minimum_required(VERSION 3.10)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK env var to point to your SDK path.")
  endif()
endif()

project(codst)
include("${VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "Call of Duty: Strike Team")
set(VITA_TITLEID "CODST0001")
set(VITA_VERSION "01.00")

add_definitions(-DNO_DBGMEM)

add_executable(codst
  main/main.c
  main/so_util/so_util.c
  main/falsojni/FalsoJNI.c
)

target_include_directories(codst PRIVATE
  main
  main/so_util
  main/falsojni
)

target_link_libraries(codst PRIVATE
  SceAppMgr_stub
  SceDisplay_stub
  SceGxm_stub
  SceCtrl_stub
  SceTouch_stub
  SceMotion_stub
  SceSysmodule_stub
  SceKernelDmacMgr_stub
  SceCommonDialog_stub
)

vita_create_vpk(codst.vpk ${VITA_TITLEID} codst
  NAME ${VITA_APP_NAME}
  VERSION ${VITA_VERSION}
)
