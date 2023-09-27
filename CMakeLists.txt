cmake_minimum_required(VERSION 3.0.0)
SET(CMAKE_BUILD_TYPE Release)
project(cube_slam)

set(CMAKE_CXX_STANDARD 17)

ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/src/orb_object_slam)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/cube_slam.cc)
target_include_directories(${PROJECT_NAME} PRIVATE 
                           ${PROJECT_SOURCE_DIR}/src
                           ${PROJECT_SOURCE_DIR}/thirdparty/DBoW2
)
target_link_libraries(${PROJECT_NAME} orb_and_object_slam multi_settings)
