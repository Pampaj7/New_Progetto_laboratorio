cmake_minimum_required(VERSION 3.20)
project(New_Progetto_laboratorio)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(test)
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

set(SOURCE_FILES  ToDo.cpp ToDo.h Activities.cpp Activities.h Diary.cpp Diary.h Date.cpp Date.h)
add_executable(New_Progetto_laboratorio main.cpp)
ADD_LIBRARY(core ${SOURCE_FILES})
target_link_libraries(New_Progetto_laboratorio core ${wxWidgets_LIBRARIES})
