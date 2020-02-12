cmake_minimum_required(VERSION 3.15)
project(GUImp C)

set(CMAKE_C_STANDARD 99)

include_directories(~/Library/Frameworks/SDL2.framework/Headers ~/Library/Frameworks/SDL2_ttf.framework/Headers ~/Library/Frameworks/SDL2_image.framework/Headers Includes)

add_executable(GUImp Sources/main.c Includes/guimp.h Sources/sdl_utill.c Utils/ft_1.c Includes/structures.h)

target_link_libraries(GUImp "-framework SDL2")
target_link_libraries(GUImp "-framework SDL2_image")
target_link_libraries(GUImp "-framework SDL2_ttf")
target_link_libraries(GUImp "-framework SDL2_ttf")

set_target_properties(GUImp PROPERTIES LINK_FLAGS "-F /Users/$ENV{USER}/Library/Frameworks")