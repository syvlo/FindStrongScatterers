cmake_minimum_required (VERSION 2.8)

project (FindStrongScatterers)

set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -Wall -Werror -g -ggdb " )
set ( SRC_DIR "src" )
set ( BIN_DIR "bin" )

find_package( OpenCV REQUIRED )
include_directories(/cal/homes/lobry/Programs/include/)

add_executable(${BIN_DIR}/findStrongS
  ${SRC_DIR}/main.cc
)

target_link_libraries (${BIN_DIR}/findStrongS
  ${OpenCV_LIBS} SAR
)
