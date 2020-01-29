include(Util)

find_or_get(GMock)
find_or_get(GTest)
find_or_get(Threads)
find_or_get(Boost COMPONENTS system program_options)

add_executable(unit_tests main.cpp)
target_include_directories(unit_tests PUBLIC 
    ${GMOCK_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS})
target_precompile_headers(unit_tests PUBLIC pch.h)
target_link_libraries(unit_tests 
    Threads::Threads
    Boost::system
    Boost::program_options
    ${GMOCK_BOTH_LIBRARIES}
    ${GTEST_BOTH_LIBRARIES})
set_property(TARGET unit_tests PROPERTY CXX_STANDARD 17)

if(UNIX)
    get_target_property(
        BOOST_PROGRAM_OPTIONS_LIB 
        Boost::program_options 
        LOCATION)

    get_target_property(
        BOOST_SYSTEM_LIB 
        Boost::system 
        LOCATION)

    include(GNUInstallDirs)
    install(TARGETS unit_tests TYPE RUNTIME)
    install(FILES 
        ${BOOST_PROGRAM_OPTIONS_LIB} 
        ${BOOST_SYSTEM_LIB} 
        TYPE LIB)
endif()