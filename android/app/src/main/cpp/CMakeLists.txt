cmake_minimum_required(VERSION 3.22)
project(ascendancy_android C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)

add_library(ascendancy SHARED
    ../../../engine/core/arena.cpp
    ../../../engine/core/log.cpp
    ../../../engine/core/profile.cpp
    ../../../engine/core/jobs.cpp
    ../../../engine/platform/platform_android.cpp
    ../../../engine/math/noise.cpp
    ../../../engine/ecs/ecs.cpp
    ../../../engine/gfx/gfx.cpp
    ../../../engine/gfx/material.cpp
    ../../../engine/audio/audio.cpp
    ../../../engine/ui/ui.cpp
    ../../../engine/path/path.cpp
    ../../../engine/sim/sim.cpp
    ../../../engine/save/save.cpp
    ../../../engine/net/lockstep.cpp
    ../../../game/game.cpp
    ../../../game/tech.cpp
    ../../../game/ai.cpp
    ../../../game/mapgen.cpp
    ../../../game/combat.cpp
    ../../../game/input.cpp
    ../../../game/ui_hud.cpp
    android_bridge.cpp
    game_entry_android.cpp
)

# Raylib
set(RAYLIB_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/../../../../third_party/raylib/src)
add_library(raylib STATIC
    ${RAYLIB_SRC_DIR}/rcore.c
    ${RAYLIB_SRC_DIR}/rtextures.c
    ${RAYLIB_SRC_DIR}/rshapes.c
    ${RAYLIB_SRC_DIR}/rmodels.c
    ${RAYLIB_SRC_DIR}/raudio.c
    ${RAYLIB_SRC_DIR}/utils.c
    ${RAYLIB_SRC_DIR}/rglfw.c
)
target_include_directories(raylib PUBLIC ${RAYLIB_SRC_DIR} ${RAYLIB_SRC_DIR}/external)

target_include_directories(ascendancy PRIVATE
    ../../../
    ${RAYLIB_SRC_DIR}
    ${RAYLIB_SRC_DIR}/external
    ../../../third_party
    ../../../third_party/stb
    ../../../third_party/dr_libs
    ../../../third_party/tinygltf
)

find_library(log-lib log)
find_library(android-lib android)
find_library(egl-lib EGL)
find_library(gles-lib GLESv3)
find_library(openal-lib OpenSLES)

target_link_libraries(ascendancy PRIVATE raylib ${log-lib} ${android-lib} ${egl-lib} ${gles-lib} ${openal-lib})
