cmake_minimum_required(VERSION 3.0)
project(fast_mass_spring)

file(GLOB VENDORS_SOURCES           ../vendor/glad/src/glad.c
                                    ../vendor/imgui/backends/imgui_demo.cpp
                                    ../vendor/stb/stb_image.cpp
                                    )
file(GLOB PROJECT_HEADERS           *.h
                                    )
file(GLOB PROJECT_SOURCES           *.cpp
                                    )

add_definitions(-DGLFW_INCLUDE_NONE
                -DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\")

add_executable(${PROJECT_NAME} 
                                ${PROJECT_SOURCES} 
                                ${PROJECT_HEADERS}
                                ${VENDORS_SOURCES}
            )
if(MSVC)
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES
                COMPILE_FLAGS "-DGU_PLATFORM_WINDOWS")
elseif(APPLE)
add_definitions(-DGU_PLATFORM_MACOS)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
                                ../vendor/glad/include/
                                ../vendor/glfw/include/
                                ../vendor/glm/
                                ../vendor/imgui/
                                ../vendor/stb
             )

target_link_libraries(${PROJECT_NAME} PUBLIC
                                ${GLFW_LIBRARIES} 
                                ${GLAD_LIBRARIES}
                      )