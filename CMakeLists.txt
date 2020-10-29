cmake_minimum_required (VERSION 2.8)

project (PublisherDDS)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Boost 1.54 REQUIRED)
include_directories(${Boost_INCLUDE_DIR} include)
include_directories(
  $ENV{ROQME_ROOT}/roqmeDDS/include
  $ENV{ROQME_ROOT}/roqmeDDS/cpp/idl
  $ENV{OSPL_HOME}/include/dcps/C++/isocpp2
  $ENV{OSPL_HOME}/include/sys
  $ENV{OSPL_HOME}/include
  $ENV{OSPL_HOME}/include/dcps/C++/SACPP
)

link_directories($ENV{OSPL_HOME}/lib)
link_directories($ENV{ROQME_ROOT}/roqmeDDS/lib)
add_executable(PublisherDDS PublisherDDS.cpp)
target_link_libraries(${PROJECT_NAME} -lzmq -pthread -ldcpsgapi -ldcpsgapi -lddsdatabase -lddsos -lddskernel -ldcpsisocpp2 -lroqmedds )
