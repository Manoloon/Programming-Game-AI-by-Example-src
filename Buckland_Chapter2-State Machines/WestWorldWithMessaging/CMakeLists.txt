cmake_minimum_required(VERSION 3.25.0)
project(WestWorldWithMessaging VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the main source directory for clarity
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/")

# List of source files
set(SOURCES
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/BaseGameEntity.cpp
    ${SOURCE_DIR}/Miner.cpp
    ${SOURCE_DIR}/MinerOwnedStates.cpp
    ${SOURCE_DIR}/MinersWife.cpp
    ${SOURCE_DIR}/MinersWifeOwnedStates.cpp
    ${SOURCE_DIR}/MessageDispatcher.cpp
    ${SOURCE_DIR}/EntityManager.cpp
)

# Add the executable target
add_executable(WestWorldWithMessaging ${SOURCES})

# Add include directories associated with the target
target_include_directories(WestWorldWithMessaging PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Common/misc"
    "${CMAKE_CURRENT_SOURCE_DIR}/Common/FSM"
    "${CMAKE_CURRENT_SOURCE_DIR}/Common/Messaging"
    "${CMAKE_CURRENT_SOURCE_DIR}/Common/Time"
)
