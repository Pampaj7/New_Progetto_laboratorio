cmake_minimum_required(VERSION 3.20)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

set(SOURCE_FILES runAllTests.cpp ActivitiesFixture.cpp DateFixture.cpp ToDoFixture.cpp DiaryFixture.cpp)
add_executable(RunEngagementsTests ${SOURCE_FILES})
target_link_libraries(RunEngagementsTests gtest gtest_main core ${wxWidgets_LIBRARIES})