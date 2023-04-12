cmake_minimum_required(VERSION 3.25.2)

set(CMAKE_CXX_STANDARD 11)

project(cpp_application)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB files
     "*.h"
     "*.cpp"
)

find_package(app_utils CONFIG REQUIRED)
find_package(app_kafka CONFIG REQUIRED)
find_package(app_rabbitmq CONFIG REQUIRED)

add_executable(${PROJECT_NAME} ${files})

target_link_libraries(${PROJECT_NAME}
     app_utils::app_utils
     app_kafka::app_kafka
     app_rabbitmq::app_rabbitmq
)