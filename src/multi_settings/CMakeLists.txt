cmake_minimum_required(VERSION 3.0.0)
SET(CMAKE_BUILD_TYPE Release)
project(multi_settings)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

find_package(OpenCV REQUIRED)

set(SETT_SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/value.cpp
    ${PROJECT_SOURCE_DIR}/structured_settings.cpp
    ${PROJECT_SOURCE_DIR}/cli_settings.cpp
    ${PROJECT_SOURCE_DIR}/multi_settings.cpp
)

add_library(${PROJECT_NAME} SHARED ${SETT_SOURCE_FILES})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_include_directories(${PROJECT_NAME} PRIVATE
                           ${OpenCV_INCLUDE_DIRS}  
                           ${PROJECT_SOURCE_DIR}
)
target_link_libraries(${PROJECT_NAME}
                      ${OpenCV_LIBRARIES}
)
