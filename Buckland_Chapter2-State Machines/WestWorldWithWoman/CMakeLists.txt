cmake_minimum_required(VERSION 3.25.0)
project(WestWorldWithWoman VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# fetch the dependencies needed
include_directories("../misc")

# These tests can use the Catch2-provided main
add_executable(WestWorldWithWoman main.cpp BaseGameEntity.cpp Miner.cpp MinerOwnedStates.cpp MinersWife.cpp MinersWifeOwnedStates.cpp)
