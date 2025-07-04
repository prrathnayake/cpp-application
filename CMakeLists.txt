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
    utils
    error
    algorithms
    blockchain
    database
)

set(h3_DEPENDENCIES
     app_h3::app_h3
     h3::h3
)
set(kafka_DEPENDENCIES
     app_kafka::app_kafka
     app_utils::app_utils
)
set(rabbitMQ_DEPENDENCIES
     app_rabbitmq::app_rabbitmq
     app_utils::app_utils
)
set(utils_DEPENDENCIES
     app_utils::app_utils
)
set(error_DEPENDENCIES
     app_utils::app_utils
)
set(algorithms_DEPENDENCIES
     app_algorithms::app_algorithms
)
set(blockchain_DEPENDENCIES
     app_blockchain::app_blockchain
)
set(database_DEPENDENCIES
     app_database::app_database
)

find_package(app_utils CONFIG REQUIRED)
find_package(app_kafka CONFIG REQUIRED)
find_package(app_rabbitmq CONFIG REQUIRED)
find_package(app_h3 CONFIG REQUIRED)
find_package(h3 CONFIG REQUIRED)
find_package(app_algorithms CONFIG REQUIRED)
find_package(app_blockchain CONFIG REQUIRED)
find_package(app_database CONFIG REQUIRED)

foreach(name ${EXAMPLES})
     add_executable(${name} "./src/${name}.cpp")
     foreach(dep ${${name}_DEPENDENCIES})
          target_link_libraries(${name} ${dep})
     endforeach()   
endforeach()