add_library(Time STATIC CrudeTimer.cpp PrecisionTimer.cpp)

# Link against the Windows Multimedia library
target_link_libraries(Time winmm)