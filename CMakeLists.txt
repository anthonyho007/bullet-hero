cmake_minimum_required(VERSION 2.6)
project(p2pshoot)

# Use our modified FindSDL2* modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${p2pshoot_SOURCE_DIR}/cmake")
# Set an output directory for our binaries
set(BIN_DIR ${p2pshoot_SOURCE_DIR}/bin)

# Bump up warning levels appropriately for clang, gcc & msvc
# Also set debug/optimization flags depending on the build type. IDE users choose this when
# selecting the build mode in their IDE
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
endif()

# set up SDL2pp library
set(SDL2PP_WITH_IMAGE TRUE)
set(SDL2PP_WITH_TTF TRUE)
add_subdirectory(SDL2pp)

find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)

include_directories(${SDL2PP_INCLUDE_DIRS} ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})

include_directories("${PROJECT_SOURCE_DIR}/src")
include_directories("./json/src")

file (GLOB p2pshoot_SOURCES src/*.cpp)

add_executable(p2pshoot ${p2pshoot_SOURCES})
target_link_libraries(p2pshoot ${SDL2PP_LIBRARIES})
install(TARGETS p2pshoot RUNTIME DESTINATION ${BIN_DIR})
