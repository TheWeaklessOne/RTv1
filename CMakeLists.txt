cmake_minimum_required(VERSION 3.15)
project(RTv1 C)

set(CMAKE_C_STANDARD 99)

include_directories(Includes ~/Library/Frameworks/SDL2.framework/Headers ~/Library/Frameworks/SDL2_ttf.framework/Headers ~/Library/Frameworks/SDL2_image.framework/Headers)

add_executable(RTv1 Includes/rt.h Sources/main.c Sources/ft.c Sources/sdl.c Includes/shapes.h Sources/Shapes/sphere.c Sources/Vec3f/vec3f_1.c Includes/vec3f.h Sources/Vec3f/vec3f_2.c Sources/Vec3f/vec3f_dtr.c Sources/rt.c)

target_link_libraries(RTv1 "-framework SDL2")
target_link_libraries(RTv1 "-framework SDL2_image")
target_link_libraries(RTv1 "-framework SDL2_ttf")

set_target_properties(RTv1 PROPERTIES LINK_FLAGS "-F /Users/$ENV{USER}/Library/Frameworks")