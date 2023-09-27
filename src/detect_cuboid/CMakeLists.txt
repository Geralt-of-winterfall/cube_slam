cmake_minimum_required(VERSION 3.0.0)
SET(CMAKE_BUILD_TYPE Release)
project(detect_cuboid)
set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

#find_package(Eigen3 REQUIRED)
include_directories("usr/include/eigen3")
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(CUBOID_SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/object_3d_util.cpp
    ${PROJECT_SOURCE_DIR}/matrix_utils.cpp
    ${PROJECT_SOURCE_DIR}/box_proposal_detail.cpp
)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(include)

add_library(${PROJECT_NAME} SHARED ${CUBOID_SOURCE_FILES})
add_library(line_lsd_lib SHARED
  libs/binary_descriptor.cpp libs/binary_descriptor_matcher.cpp libs/LSDDetector.cpp  libs/lsd.cpp libs/bitarray.hpp  
  libs/bitops.hpp libs/draw.cpp libs/precomp.hpp libs/types.hpp  class/line_lbd_allclass.cpp
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_include_directories(${PROJECT_NAME} PRIVATE
                           ${PROJECT_SOURCE_DIR}
                           ${Eigen_INCLUDE_DIRS}
                           ${OpenCV_INCLUDE_DIRS}  
)
target_link_libraries(${PROJECT_NAME}
                      ${OpenCV_LIBRARIES}
                      line_lsd_lib
)
