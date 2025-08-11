add_executable(ascendancy_tests
    test_determinism.cpp
    test_pathfinding.cpp
    test_combat.cpp
)
target_include_directories(ascendancy_tests PRIVATE ../)
target_link_libraries(ascendancy_tests PRIVATE m pthread)
