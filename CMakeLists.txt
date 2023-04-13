cmake_minimum_required(VERSION 3.25.2)

set(CMAKE_CXX_STANDARD 11)

project(cpp_application)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(EXAMPLES
    h3
    kafka
    rabbitMQ
)

find_package(app_utils CONFIG REQUIRED)
find_package(app_kafka CONFIG REQUIRED)
find_package(app_rabbitmq CONFIG REQUIRED)
find_package(app_h3 CONFIG REQUIRED)
find_package(h3 CONFIG REQUIRED)

foreach(name ${EXAMPLES})
     if(${name} STREQUAL "h3")
          add_executable(${name} "${name}.cpp")
          target_link_libraries(${name}
               app_h3::app_h3
               h3::h3
          )
     elseif(${name} STREQUAL "kafka")
          add_executable(${name} "${name}.cpp")
          target_link_libraries(${name}
               app_kafka::app_kafka
               app_utils::app_utils
          )
     elseif(${name} STREQUAL "rabbitMQ")
          add_executable(${name} "${name}.cpp")
          target_link_libraries(${name}
               app_rabbitmq::app_rabbitmq
               app_utils::app_utils
          )
     endif()
endforeach()

