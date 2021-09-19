cmake_minimum_required(VERSION 3.0.0)
project(simple-term-emulator VERSION 0.1.0)
include(CTest)
enable_testing()

find_package(X11 REQUIRED)

add_executable(simple-term-emulator main.c)
target_include_directories(simple-term-emulator PUBLIC ${X11_INCLUDE_DIR})
target_link_libraries(simple-term-emulator ${X11_LIBRARIES})
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
