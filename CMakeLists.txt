cmake_minimum_required(VERSION 3.2)

project(ip_filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost REQUIRED)

find_package(GTest REQUIRED)

add_executable(ip_filter ip_filter.cpp)

add_library(ip_class ip_class.cpp)

add_library(filters filters.cpp)

add_executable(test_ip_class test_ip_class.cpp)

add_executable(test_filters test_filters.cpp)

set_target_properties(ip_filter ip_class filters test_ip_class test_filters PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_link_libraries(ip_filter 
    ip_class
    filters
)

target_link_libraries(filters 
    ip_class
)

target_link_libraries(ip_class
    ${Boodt_LIBRARIES}
)

target_link_libraries(test_ip_class
    GTest::GTest
    GTest::Main
)

target_link_libraries(test_filters
    GTest::GTest
    GTest::Main
    ip_class
)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT nazdryuhin@gmail.com)

include(CPack)

enable_testing()

add_test(test_ip_class test_ip_class)
add_test(test_filters test_filters)
