cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x -g")

include_directories(
     src
     src-gen
     ../CommonAPI-3.1.3/include
     ../CommonAPI-SomeIP-3.1.3/include
     ../vSomeIP-1.3.0/interface
)

link_directories(
     ../../CommonAPI-3.1.3/build
     ../../CommonAPI-SomeIP-3.1.3/build
     ../../vSomeIP-1.3.0/build
)

add_executable(sum-client
    src/sumClient.cpp
    src/mytime.cpp
    src-gen/v1_0/math/sum/sum_ifSomeIPProxy.cpp
    src-gen/v1_0/math/sum/sum_ifSomeIPDeployment.cpp
)
target_link_libraries(sum-client CommonAPI CommonAPI-SomeIP vsomeip)

add_executable(sum
    src/sum.cpp
    src/mytime.cpp
    src/sum_ifStubImpl.cpp
    src-gen/v1_0/math/sum/sum_ifSomeIPStubAdapter.cpp
    src-gen/v1_0/math/sum/sum_ifSomeIPDeployment.cpp
    src-gen/v1_0/math/sum/sum_ifStubDefault.cpp
)
target_link_libraries(sum CommonAPI CommonAPI-SomeIP vsomeip) 

add_library(mytime SHARED src/mytime.cpp)