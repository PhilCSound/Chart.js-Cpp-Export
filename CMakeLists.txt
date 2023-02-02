cmake_minimum_required(VERSION 3.15)

project(ChartJsForCpp)

include_directories( ${CMAKE_SOURCE_DIR}/include/cjs )

set(SOURCE_FILES
    main.cpp
    src/cjs/Color.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION .)