cmake_minimum_required(VERSION 3.25)

set(ENGINE_PROJECT_NAME Core)

set(ENGINE_PUBLIC_INCLUDES
	includes/Core/Application.h
	includes/Core/Log.h
	includes/Core/Event.h
	includes/Core/Camera.h
)

set(ENGINE_PRIVATE_INCLUDES
	src/Core/Window.h
	src/Core/Rendering/OpenGL/ShaderProgram.h
	src/Core/Rendering/OpenGL/VertexBuffer.h
	src/Core/Rendering/OpenGL/VertexArray.h
	src/Core/Rendering/OpenGL/IndexBuffer.h
)

set(ENGINE_PRIVATE_SOURCES
	src/Core/Application.cpp
	src/Core/Window.cpp
	src/Core/Camera.cpp
	src/Core/Rendering/OpenGL/ShaderProgram.cpp
	src/Core/Rendering/OpenGL/VertexBuffer.cpp
	src/Core/Rendering/OpenGL/VertexArray.cpp
	src/Core/Rendering/OpenGL/IndexBuffer.cpp
)

set(ENGINE_ALL_SOURCES
	${ENGINE_PUBLIC_INCLUDES}
	${ENGINE_PRIVATE_INCLUDES}
	${ENGINE_PRIVATE_SOURCES}
)

add_library(${ENGINE_PROJECT_NAME} STATIC
	${ENGINE_ALL_SOURCES}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES
	${ENGINE_ALL_SOURCES}
)

target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC includes)
target_include_directories(${ENGINE_PROJECT_NAME} PRIVATE src)
target_compile_features(${ENGINE_PROJECT_NAME} PUBLIC cxx_std_17)

add_subdirectory(../external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glfw)

add_subdirectory(../external/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE spdlog)

add_subdirectory(../external/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glad)

add_subdirectory(../external/glm ${CMAKE_CURRENT_BINARY_DIR}/glm)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glm)

set(IMGUI_INCLUDES
	../external/imgui/imgui.h
	../external/imgui/backends/imgui_impl_glfw.h
	../external/imgui/backends/imgui_impl_opengl3.h
)

set(IMGUI_SOURCES
	../external/imgui/imgui.cpp
	../external/imgui/backends/imgui_impl_glfw.cpp
	../external/imgui/backends/imgui_impl_opengl3.cpp
	../external/imgui/imgui_draw.cpp
	../external/imgui/imgui_tables.cpp
	../external/imgui/imgui_widgets.cpp
	../external/imgui/imgui_demo.cpp
)

add_library(imgui STATIC
	${IMGUI_INCLUDES}
	${IMGUI_SOURCES}
)

target_include_directories(imgui PUBLIC ../external)
target_include_directories(imgui PUBLIC ../external/imgui)

target_link_libraries(imgui PRIVATE glad glfw)

target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE imgui)