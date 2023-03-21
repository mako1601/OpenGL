cmake_minimum_required(VERSION 3.25)

set(PROJECT_NAME OpenGL)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
	src/main.cpp
	src/Camera.h
	src/Camera.cpp
	src/ShaderProgram.h
	src/ShaderProgram.cpp
	src/stb_image.h
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)

add_subdirectory(external/glm)
target_link_libraries(${PROJECT_NAME} glm)