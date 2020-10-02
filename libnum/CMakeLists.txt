cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD  90)
set(CMAKE_C_STANDARD_REQUIRED True)

# set the project name
project(num)

#file(GLOB SOURCES "src/*.c")

# find src -type f -name '*.c' | sed 'N;N;s/\n/ /g' |  sed '$s/\\\\\\//' | column -t
set(${PROJECT_NAME}_SOURCES
		src/convert/vec2to3.c  src/convert/vec3to2.c  src/num/num__1.c
		src/num/num__2.c       src/vec2/vec2__1.c     src/vec2/vec2__2.c
		src/vec2/vec2__3.c     src/vec2/vec2__4.c     src/vec2/vec2__5.c
		src/vec2/vec2__6.c     src/vec2/vec2__7.c     src/vec3/vec3__1.c
		src/vec3/vec3__2.c     src/vec3/vec3__3.c     src/vec3/vec3__4.c
		src/vec3/vec3__5.c     src/vec3/vec3__6.c     src/vec3/vec3__7.c
		)

#target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include )
include_directories(${PROJECT_SOURCE_DIR}/include )

add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})
