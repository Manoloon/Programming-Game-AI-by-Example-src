cmake_minimum_required(VERSION 3.25.0)
project(SimpleSoccer VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the main source directory for clarity
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/")

if(CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang)")
    add_compile_options(-Wall -Wextra -Wpedantic -Wshadow)
endif()

# Add the subdirectories containing the libraries
add_subdirectory(Common/Messaging)
add_subdirectory(Common/Time)
add_subdirectory(Common/Game)
add_subdirectory(Common/Misc)
add_subdirectory(Common/2D)
add_subdirectory(Common/Debug)

# List of source files
set(SOURCES
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/FieldPlayer.cpp
    ${SOURCE_DIR}/FieldPlayerStates.cpp
    ${SOURCE_DIR}/ParamLoader.cpp
    ${SOURCE_DIR}/Goal.cpp
    ${SOURCE_DIR}/SteeringBehaviors.cpp
    ${SOURCE_DIR}/GoalKeeper.cpp
    ${SOURCE_DIR}/GoalKeeperStates.cpp
    ${SOURCE_DIR}/PlayerBase.cpp
    ${SOURCE_DIR}/SoccerBall.cpp
    ${SOURCE_DIR}/SoccerMessages.cpp
    ${SOURCE_DIR}/SoccerPitch.cpp
    ${SOURCE_DIR}/SoccerTeam.cpp
    ${SOURCE_DIR}/SupportSpotCalculator.cpp
    ${SOURCE_DIR}/TeamStates.cpp
)

# Add the executable target
add_executable(SimpleSoccer ${SOURCES})

# Add include directories associated with the target
target_include_directories(SimpleSoccer PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Common/Misc"
    "${CMAKE_CURRENT_SOURCE_DIR}/Common/FSM"
    "${CMAKE_CURRENT_SOURCE_DIR}/Common/Messaging"
    "${CMAKE_CURRENT_SOURCE_DIR}/Common/Time"
    "${CMAKE_CURRENT_SOURCE_DIR}/Common/2D"
    "${CMAKE_CURRENT_SOURCE_DIR}/Common/Debug"
)

# Link the static libraries to the executable
target_link_libraries(SimpleSoccer PRIVATE
    Messaging
    Time
    Game 
    Misc
    2D
    Debug
    winmm
)
