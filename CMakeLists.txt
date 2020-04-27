cmake_minimum_required(VERSION 3.15)
project(RTv1 C)

set(CMAKE_C_STANDARD 99)

include_directories(Includes)

add_executable(RTv1 Includes/rt.h Sources/ft.c Sources/list.c Sources/list_2.c Includes/list.h Sources/main.c Sources/sdl.c Includes/shapes.h Sources/Shapes/sphere.c Sources/Vec3f/vec3f_1.c Includes/vec3f.h Sources/Vec3f/vec3f_2.c Sources/Vec3f/vec3f_dtr.c Sources/rt.c Sources/sdl_init.c Includes/structures.h Sources/ft_2.c)

target_link_libraries(RTv1 m SDL2 SDL2_image)