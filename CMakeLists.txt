cmake_minimum_required(VERSION 3.16.2)

project(cmake_package_manager)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CXX_STANDARD_REQUIRED ON)

set(CROSS_COMPILE_FOR_RPI True)

if(CROSS_COMPILE_FOR_RPI)
    set(CMAKE_SIZEOF_VOID_P 4)
    set(CMAKE_CXX_COMPILER_ARCHITECTURE_ID "ARM")
    set(Boost_USE_MULTITHREADED ON)
    set(Boost_COMPILER "gcc")

    set(CMAKE_SYSTEM_NAME Linux)
    set(CMAKE_SYSTEM_PROCESSOR arm)

    set(cross_compile_toolchain_path 
        $ENV{HOME}/.local/x-tools/armv8-rpi3-linux-gnueabihf)
    set(CMAKE_SYSROOT 
        ${cross_compile_toolchain_path}/armv8-rpi3-linux-gnueabihf/sysroot)
    set(CMAKE_C_COMPILER
        ${cross_compile_toolchain_path}/bin/armv8-rpi3-linux-gnueabihf-gcc)
    set(CMAKE_CXX_COMPILER
        ${cross_compile_toolchain_path}/bin/armv8-rpi3-linux-gnueabihf-g++)

    set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
    set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
    set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
endif()

add_subdirectory(unit_tests)

if(CROSS_COMPILE_FOR_RPI)
    set(CPACK_PACKAGE_NAME "cmake_package_manager-rpi3")
    set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "armhf")
else()
    set(CPACK_PACKAGE_NAME "cmake_package_manager")
endif()

set(CPACK_PACKAGE_DESCRIPTION "cmake_package_manager.")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "cmake_package_manager.")

if(UNIX)
    set(CPACK_GENERATOR "DEB")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "arjmandi")
endif()

include(CPack)