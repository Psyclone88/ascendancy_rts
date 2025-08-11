# Engine Architecture

**Pattern:** ECS + data-oriented hot loops. Sim runs fixed-step at 15 Hz; rendering interpolates to display refresh.

## Modules

- `engine/core`: memory arenas, logging, profiler HUD, job system (work-stealing thread pool)
- `engine/platform`: Android bridge (JNI hooks for vibration, storage), file IO
- `engine/gfx`: Renderer on Raylib + GLES 3.0, instancing, batched sprites/meshes, optional shadow quality tier, postfx toggle
- `engine/audio`: miniaudio-backed mixer + Raylib helpers, distance attenuation
- `engine/math`: SIMD-friendly math (where available), noise, bounds, frustum
- `engine/ecs`: sparse-set + archetype hybrid for cache-friendly iteration
- `engine/path`: HPA*, flow fields, RVO-lite
- `engine/ui`: immediate-mode GUI, widgets, gestures, virtual gamepad, context wheel
- `engine/sim`: deterministic tick, fixed RNG, fog of war
- `engine/save`: binary saves, deterministic replays from command log
- `engine/net`: deterministic lockstep (local stub at 1.0)

**Determinism:** All game state mutates only during fixed ticks; network time and input commands are recorded and can be replayed. Float ops are isolated; fixed-point is used in combat and economy calculations.

