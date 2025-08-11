
## DESIGN.md
```markdown
# Game Design

## Core Loop
Scout → expand → tech → raid → siege → counterplay, under fog of war. Economy management (Food, Wood, Stone, Metal, Energy from Industrial onward), population cap, and build times balance snowballing.

## Epochs
1. Stone
2. Bronze
3. Iron
4. Medieval
5. Industrial
6. Modern
7. Digital

Each epoch unlocks new units, buildings, and upgrades. Earlier epochs remain viable via cost and role tuning; no instant obsolescence.

## Units & Counters (examples)
- Worker (economic backbone)
- Scout (vision, harassment)
- Spearman (counters Cavalry)
- Archer (counters Infantry)
- Swordsman (frontline melee)
- Cavalry (flanks, vulnerable to Spear/Pike)
- Siege (Ram/Catapult, splash vs buildings)
- Musketeer, Cannon (gunpowder)
- Tank (late ground dominance)
- Helicopter / Drone (air; countered by AA/modern ranged)

## Buildings
Town Center, House, Barracks, Archery Range, Stable, Workshop, Foundry, University, Farm, Mill, Mine, Tower, Wall/Gate, Dock (if water map enabled).

## Tech Tree
Epoch-gated upgrades for attack/armor/speed/vision/economy. Clean UI via tabbed pages with clear prerequisites.

## AI
- **Easy:** conservative economy, visible intent, retreats late
- **Normal:** fair information (no cheating), standard build orders
- **Hard:** mild info advantage (faster scouting fog reveal), sharper timing

## Pathfinding
Hierarchical A* on a multi-resolution grid. Units follow flow fields for group movement; local avoidance via RVO-lite using simple velocity obstacles.

## Combat
Formations (line/wedge/box), focus fire, splash for siege, armor classes, ballistic projectiles with prediction. Deterministic resolution to support replays.

## Maps
Procedural seeded generation with 4 biomes: Temperate, Desert, Snow, Jungle. Map JSON seeds and settings stored in `assets/data/map_settings.json`.

## UX (Touch First)
- Tap select, drag box select
- Two-finger pan, pinch zoom, two-finger rotate (optional)
- Long-press context wheel (Move/Attack/Stop/Patrol/Build)
- Edge scroll optional
- Minimap tap-to-jump
- Group hot-slots (touch bar), scalable UI, colorblind palette, vibration toggle, Lefty mode

## Performance Targets
- 60 FPS on mid devices with 300–600 units
- < 800 MB memory
- Battery-aware tick throttling when minimized

