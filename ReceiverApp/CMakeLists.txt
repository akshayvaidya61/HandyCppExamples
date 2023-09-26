cmake_minimum_required(VERSION 3.12)

project(ReceiverApp)

file(GLOB SRC_FILES ./src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ./inc
    ../common/inc
)