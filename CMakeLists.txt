# CMakeList.txt : CMake project for cpp_playground, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project("cpp_playground")

# Add source to this project's executable.
add_executable(cpp_playground WIN32 "cpp_playground.cpp" "cpp_playground.h")

target_link_libraries(${PROJECT_NAME} "user32.lib")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET cpp_playground PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
