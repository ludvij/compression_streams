cmake_minimum_required(VERSION 3.31)

project(compression_streams)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

SET(ZLIB_USE_STATIC_LIBS ON)
SET(ZLIB_BUILD_EXAMPLES OFF)


SET(ZLIB_COMPAT ON)
SET(ZLIB_ENABLE_TESTS OFF)
SET(WITH_GTEST OFF)
SET(BUILD_SHARED_LIBS FALSE)

include(FetchContent)
FetchContent_Declare(
	zlib_ng
	GIT_REPOSITORY https://github.com/zlib-ng/zlib-ng.git
	GIT_TAG        2.2.5
	EXCLUDE_FROM_ALL
)
if(MSVC)
	FetchContent_MakeAvailable(zlib_ng)
else()
	add_compile_options(-Wno-type-limits)
	FetchContent_MakeAvailable(zlib_ng)
	add_compile_options(-Wtype-limits)
endif()



add_library(${PROJECT_NAME} STATIC)


set(SOURCES
	include/compression_streams/deflate_stream.hpp
	include/compression_streams/inflate_stream.hpp
	include/compression_streams/Options.hpp

	src/deflate_stream.cpp
	src/inflate_stream.cpp
)


target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

target_include_directories(${PROJECT_NAME}
	PUBLIC  ${CMAKE_CURRENT_LIST_DIR}/include
	PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src
	PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include/compression_streams
)

target_link_libraries(${PROJECT_NAME} 
	PRIVATE ludutils
	PRIVATE zlibstatic
)


