cmake_minimum_required(VERSION 3.12)

project(CommunicationManager)

file(GLOB SRC_FILES ./src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE
    
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ./inc
    ../common/inc
)
