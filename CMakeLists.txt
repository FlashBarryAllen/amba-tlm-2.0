cmake_minimum_required(VERSION 3.16)

project(TrafficExample)

add_executable(TrafficExample 
    ${CMAKE_SOURCE_DIR}/examples/amba_tlm/TrafficExample.cpp
    ${CMAKE_SOURCE_DIR}/examples/amba_tlm/Memory.cpp
    ${CMAKE_SOURCE_DIR}/examples/amba_tlm/Monitor.cpp
    ${CMAKE_SOURCE_DIR}/examples/amba_tlm/TrafficGenerator.cpp
    ${CMAKE_SOURCE_DIR}/src/libarmaxi4.cpp
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

target_link_libraries(TrafficExample PUBLIC systemc)  

target_include_directories(TrafficExample PUBLIC
                          "${CMAKE_SOURCE_DIR}/examples/amba_tlm/"
                          "${CMAKE_SOURCE_DIR}/include/"
                          )

target_compile_options(TrafficExample PRIVATE "-g")                          