#include "ParamLoader.h"

const wchar_t* const ParamLoader::params = L"params.ini";

ParamLoader* ParamLoader::Instance()
{
  static ParamLoader instance;
  return &instance;
}

 ParamLoader::ParamLoader():iniFileLoaderBase(params)
  {
    try
    {
    NumAgents               = GetNextParameterInt();
    NumObstacles            = GetNextParameterInt();
    MinObstacleRadius       = GetNextParameterFloat();
    MaxObstacleRadius       = GetNextParameterFloat();

    NumCellsX               = GetNextParameterInt();
    NumCellsY               = GetNextParameterInt();

    NumSamplesForSmoothing  = GetNextParameterInt();

    SteeringForceTweaker    = GetNextParameterFloat();
    MaxSteeringForce        = GetNextParameterFloat() * SteeringForceTweaker;
    MaxSpeed                = GetNextParameterFloat();
    VehicleMass             = GetNextParameterFloat();
    VehicleScale            = GetNextParameterFloat();

    SeparationWeight        = GetNextParameterFloat() * SteeringForceTweaker;
    AlignmentWeight         = GetNextParameterFloat() * SteeringForceTweaker;
    CohesionWeight          = GetNextParameterFloat() * SteeringForceTweaker;
    ObstacleAvoidanceWeight = GetNextParameterFloat() * SteeringForceTweaker;
    WallAvoidanceWeight     = GetNextParameterFloat() * SteeringForceTweaker;
    WanderWeight            = GetNextParameterFloat() * SteeringForceTweaker;
    SeekWeight              = GetNextParameterFloat() * SteeringForceTweaker;
    FleeWeight              = GetNextParameterFloat() * SteeringForceTweaker;
    ArriveWeight            = GetNextParameterFloat() * SteeringForceTweaker;
    PursuitWeight           = GetNextParameterFloat() * SteeringForceTweaker;
    OffsetPursuitWeight     = GetNextParameterFloat() * SteeringForceTweaker;
    InterposeWeight         = GetNextParameterFloat() * SteeringForceTweaker;
    HideWeight              = GetNextParameterFloat() * SteeringForceTweaker;
    EvadeWeight             = GetNextParameterFloat() * SteeringForceTweaker;
    FollowPathWeight        = GetNextParameterFloat() * SteeringForceTweaker;

    ViewDistance            = GetNextParameterFloat();
    MinDetectionBoxLength   = GetNextParameterFloat();
    WallDetectionFeelerLength=GetNextParameterFloat();

    prWallAvoidance         = GetNextParameterFloat();
    prObstacleAvoidance     = GetNextParameterFloat();  
    prSeparation            = GetNextParameterFloat();
    prAlignment             = GetNextParameterFloat();
    prCohesion              = GetNextParameterFloat();
    prWander                = GetNextParameterFloat();
    prSeek                  = GetNextParameterFloat();
    prFlee                  = GetNextParameterFloat();
    prEvade                 = GetNextParameterFloat();
    prHide                  = GetNextParameterFloat();
    prArrive                = GetNextParameterFloat();

    CreateWalls             = GetNextParameterBool();
    CreateObstacles         = GetNextParameterBool();

    MaxTurnRatePerSecond    = Pi;
    } catch (const std::exception& e)
    {
      // Handle exceptions (e.g., log the error or rethrow)
            throw std::runtime_error(std::string("ParamLoader initialization error: ") + e.what());
    }
  }