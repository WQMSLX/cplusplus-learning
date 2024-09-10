cmake_minimum_required(VERSION 3.20)
message(-------CMake 学习案例 start------)
set( VAR $ENV{PATH})
message(${VAR})
# 获取长度
list(LENGTH VAR len)
message(${len})

set(test t1 t2 t3 t4)
# 获取长度
list(LENGTH test len1)
message(${len1})
#获取索引
list(FIND test t1 index)
message(${index})

list(APPEND port p1 p2 p3)
message(${port})
#移除
list(REMOVE_ITEM  port p1)
message(${VAR})
#拼接
list(APPEND port p5)
message(${port})
#插入
list(INSERT port 2 a9)
message(${port})
#反转
list(REVERSE port)
message(${port})
#排序
list(SORT port)
message("-> the value of port  is: ${port}" )

function(InFuc)


endfunction()
message(-------CMake 学习案例 end------)
project(cplusplus)
add_executable(oatpp-test src/main.cpp)
set(CMAKE_CXX_STANDARD 11)

find_package(oatpp CONFIG REQUIRED)

target_link_libraries(oatpp-test PRIVATE oatpp::oatpp oatpp::oatpp-test)
message(构建成功)
