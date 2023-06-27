cmake_minimum_required(VERSION 3.23)

project(ra2l1_standalone_test LANGUAGES CXX C ASM)

add_subdirectory(common)
add_subdirectory(external) # Contains all external dependencies
add_subdirectory(ra2l1) # Contains the components for the platform

add_executable(test_app
    src/main.cpp
)

target_link_libraries(test_app common ra2l1 SEGGER_RTT)
target_link_options(test_app
    PRIVATE LINKER:-Map=$<TARGET_FILE_BASE_NAME:test_app>.map
)

target_compile_features(test_app PUBLIC cxx_std_20)
