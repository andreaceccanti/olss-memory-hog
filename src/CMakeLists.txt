cmake_minimum_required(VERSION 3.13)
project (memory_hog CXX)

find_package(Threads)
find_package(ZLIB)
find_package(OpenSSL)
find_package( Boost 1.70 COMPONENTS system thread REQUIRED )

if(OPENSSL_FOUND)
    include_directories(${OPENSSL_INCLUDE_DIR})
endif()

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()

include_directories(${Boost_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INSTALL_PREFIX /usr/local)

add_executable(memory_hog memory_hog.cpp)
target_link_libraries(memory_hog ${Boost_LIBRARIES})
target_link_libraries(memory_hog ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS memory_hog RUNTIME DESTINATION bin)
install(
  DIRECTORY ${CMAKE_INSTALL_PREFIX}/lib
  DESTINATION .
  FILES_MATCHING
  PATTERN "libgrpc++_reflection.so*"
  PATTERN "libprotobuf.so*"
  PATTERN "libgrpc++_reflection.so.*"
  PATTERN "libboost_log.so.*"
  PATTERN "libgrpc++.so.*"
  PATTERN "libgrpc.so.*"
  PATTERN "libboost_log_setup.so.*"
  PATTERN "libboost_filesystem.so.*"
  PATTERN "libboost_thread.so.*"
  PATTERN "libboost_date_time.so.*"
  PATTERN "libboost_regex.so.*"
  PATTERN "libboost_chrono.so.*"
  PATTERN "libboost_system.so.*"
  PATTERN "libboost_atomic.so.*"
  PATTERN "libboost_program_options.so.*"
  PATTERN "libgpr.so.*"
  PATTERN "libyaml-cpp.so.*"
  PATTERN "libcares.so.*"
)

set(CPACK_GENERATOR "TGZ")
set(CPACK_PACKAGING_INSTALL_PREFIX "/usr/local")
set(CPACK_PACKAGE_VERSION "0.1")
include(CPack)
