cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

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

add_executable(avg
    src/avg.cpp
    src/mytime.cpp
    src-gen/v1_0/ipc_math/add_apiSomeIPProxy.cpp
    src-gen/v1_0/ipc_math/add_apiSomeIPDeployment.cpp
)
target_link_libraries(avg CommonAPI CommonAPI-SomeIP vsomeip)

add_executable(sum
    src/sum.cpp
    src/mytime.cpp
    src/add_apiStubImpl.cpp
    src-gen/v1_0/ipc_math/add_apiSomeIPStubAdapter.cpp
    src-gen/v1_0/ipc_math/add_apiStubDefault.cpp
    src-gen/v1_0/ipc_math/add_apiSomeIPDeployment.cpp
)
target_link_libraries(sum CommonAPI CommonAPI-SomeIP vsomeip) 
