cmake_minimum_required(VERSION 3.25.0)
project(SteeringBehaviors VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the main source directory for clarity
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/")

# Add the subdirectories containing the libraries
add_subdirectory(Common/Messaging)
add_subdirectory(Common/Time)
add_subdirectory(Common/Game)
add_subdirectory(Common/Misc)
add_subdirectory(Common/2D)

# List of source files
set(SOURCES
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/GameWorld.cpp
    ${SOURCE_DIR}/Obstacle.cpp
    ${SOURCE_DIR}/ParamLoader.cpp
    ${SOURCE_DIR}/Path.cpp
    ${SOURCE_DIR}/SteeringBehaviors.cpp
    ${SOURCE_DIR}/Vehicle.cpp
)

# Add the executable target
add_executable(SteeringBehaviors ${SOURCES})

# Add include directories associated with the target
target_include_directories(SteeringBehaviors PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Common/Misc"
    "${CMAKE_CURRENT_SOURCE_DIR}/Common/FSM"
    "${CMAKE_CURRENT_SOURCE_DIR}/Common/Messaging"
    "${CMAKE_CURRENT_SOURCE_DIR}/Common/Time"
    "${CMAKE_CURRENT_SOURCE_DIR}/Common/2D"
)

# Link the static libraries to the executable
target_link_libraries(SteeringBehaviors PRIVATE
    Messaging
    Time
    Game 
    Misc
    2D
)
