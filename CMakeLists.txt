# CMakeList.txt : CMake project for cpp_playground, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

# if(NOT LINUX) should work, too, if you need that
if(LINUX) 
    message(STATUS ">>> Linux")
    
    file(GLOB SRC_FILES
        "main.cpp"
        "spladi_*.cpp"
        "spladi_*.h"
        "linux_*.cpp"
        "linux_*.h"
    )

    add_executable(cpp_playground ${SRC_FILES})
    # linux stuff here
else()
    message(STATUS ">>> Not Linux")
    # stuff that should happen not on Linux 
    # Add source to this project's executable.
    file(GLOB SRC_FILES
        "main.cpp"
        "spladi_*.cpp"
        "spladi_*.h"
        "win32_*.cpp"
        "win32_*.h"
    )

    add_executable(cpp_playground WIN32 ${SRC_FILES})
    target_link_libraries(${PROJECT_NAME} "user32.lib")
    
    
    if (CMAKE_VERSION VERSION_GREATER 3.12)
      set_property(TARGET main PROPERTY CXX_STANDARD 20)
    endif()
endif()

project("cpp_playground")
