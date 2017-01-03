set(TARGET_NAME ml)
project(${TARGET_NAME})

#search folders for source files
file(GLOB_RECURSE APPLICATION_BASE_SOURCES src/application-base *.cpp)
file(GLOB_RECURSE APPLICATION_D3D11_SOURCES src/application-d3d11 *.cpp)

file(GLOB_RECURSE CORE_BASE_SOURCES src/core-base/*.cpp)
file(GLOB_RECURSE CORE_GRAPHICS_SOURCES src/core-graphics/*.cpp)
file(GLOB_RECURSE CORE_MATH_SOURCES src/core-math/*.cpp)
file(GLOB_RECURSE CORE_MESH_SOURCES src/core-mesh/*.cpp)
file(GLOB_RECURSE CORE_MULTITHREADING_SOURCES src/core-multithreading/*.cpp)
file(GLOB_RECURSE CORE_UTIL_SOURCES src/core-util/*.cpp)
file(GLOB_RECURSE EXT_LODEPNG_SOURCES src/ext-lodepng/*.cpp)

#cross-platform sources
set(${TARGET_NAME}_SOURCE_FILES
        ${CORE_BASE_SOURCES}
        ${CORE_GRAPHICS_SOURCES}
        ${CORE_MATH_SOURCES}
        ${CORE_MESH_SOURCES}
        ${CORE_MULTITHREADING_SOURCES}
        ${CORE_UTIL_SOURCES}
        ${EXT_LODEPNG_SOURCES}
)

#Add DX11 source files on Windows platforms
if(WIN32)
    set(${TARGET_NAME}_SOURCE_FILES ${${TARGET_NAME}_SOURCE_FILES} APPLICATION_BASE_SOURCES APPLICATION_D3D11_SOURCES)
    source_group("ApplicationBase" FILES ${APPLICATION_BASE_SOURCES})
    source_group("ApplicationD3D11" FILES ${APPLICATION_D3D11_SOURCES})
endif()

source_group("CoreBase" FILES ${CORE_BASE_SOURCES})
source_group("CoreGraphics" FILES ${CORE_GRAPHICS_SOURCES})
source_group("CoreMath" FILES ${CORE_MATH_SOURCES})
source_group("CoreMesh" FILES ${CORE_MESH_SOURCES})
source_group("CoreMultithreading" FILES ${CORE_MULTITHREADING_SOURCES})
source_group("CoreUtil" FILES ${CORE_UTIL_SOURCES})
source_group("ExtLodepng" FILES ${EXT_LODEPNG_SOURCES})



add_library(${TARGET_NAME} ${${TARGET_NAME}_SOURCE_FILES})
target_include_directories(${TARGET_NAME} PUBLIC include)

find_package(Eigen3 REQUIRED)
target_include_directories(${TARGET_NAME} PRIVATE ${EIGEN3_INCLUDE_DIR})