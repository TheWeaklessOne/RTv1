cmake_minimum_required(VERSION 3.16)
project(RTv1 C)

set(CMAKE_C_STANDARD 11)

include_directories(Includes)

add_executable(RTv1
    Includes/conf.h
    Includes/list.h
    Includes/rt.h
    Includes/shapes.h
    Includes/vec3f.h
    Sources/Conf_reader/check_file.c
    Sources/Conf_reader/check_uniq.c
    Sources/Conf_reader/conf.c
    Sources/Conf_reader/conf_help.c
    Sources/Conf_reader/conf_reload.c
    Sources/Conf_reader/create.c
    Sources/Conf_reader/create_2.c
    Sources/Conf_reader/create_light.c
    Sources/Conf_reader/ft_strsplit.c
    Sources/Conf_reader/get_nl.c
    Sources/Conf_reader/str.c
    Sources/Conf_reader/create_object.c
    Sources/Shapes/plane.c
    Sources/Shapes/sphere.c
    Sources/Vec3f/vec3f_1.c
    Sources/Vec3f/vec3f_2.c
    Sources/Vec3f/vec3f_dtr.c
    Sources/ft.c
    Sources/ft_2.c
    Sources/get_object.c
    Sources/list.c
    Sources/list_2.c
    Sources/main.c
    Sources/rt.c
    Sources/sdl.c
    Sources/sdl_init.c
    Sources/trace_ray.c Sources/Conf_reader/check_object_by_type.c)

target_link_libraries(RTv1 SDL2 SDL2_image)
