cmake_minimum_required(VERSION 3.18)
project(ascendancy_rts C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)

add_definitions(-DPLATFORM_DESKTOP)

# Desktop build (Linux) target for quick tests (uses system OpenGL, SDL not required since raylib handles)
add_executable(ascendancy_desktop
    engine/core/arena.cpp
    engine/core/log.cpp
    engine/core/profile.cpp
    engine/core/jobs.cpp
    engine/platform/platform_android.cpp
    engine/math/noise.cpp
    engine/ecs/ecs.cpp
    engine/gfx/gfx.cpp
    engine/gfx/material.cpp
    engine/audio/audio.cpp
    engine/ui/ui.cpp
    engine/path/path.cpp
    engine/sim/sim.cpp
    engine/save/save.cpp
    engine/net/lockstep.cpp
    game/game.cpp
    game/tech.cpp
    game/ai.cpp
    game/mapgen.cpp
    game/combat.cpp
    game/input.cpp
    game/ui_hud.cpp
)

target_include_directories(ascendancy_desktop PRIVATE . third_party third_party/stb third_party/dr_libs third_party/tinygltf)

# Expect raylib to be present after setup script
add_subdirectory(third_party/raylib EXCLUDE_FROM_ALL)
target_link_libraries(ascendancy_desktop PRIVATE raylib m pthread dl)
