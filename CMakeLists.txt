cmake_minimum_required(VERSION 3.20)

project(cplusplus)
add_executable(oatpp-test src/main.cpp)
set(CMAKE_CXX_STANDARD 11)

find_package(oatpp CONFIG REQUIRED)

target_link_libraries(oatpp-test PRIVATE oatpp::oatpp oatpp::oatpp-test)
