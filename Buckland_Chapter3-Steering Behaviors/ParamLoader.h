#ifndef PARAMLOADER_H
#define PARAMLOADER_H
//-----------------------------------------------------------------------------
//
//  Name:   ParamLoader.h
//
//  Author: Mat Buckland (www.ai-junkie.com)
//
//  Desc:   class to parse a parameter file for the steering behavior project
//-----------------------------------------------------------------------------
#include "constants.h"
#include <stdexcept>
#include <string>
#include "../Misc/iniFileLoaderBase.h"
#include "../Misc/utils.h"

#define Prm (*ParamLoader::Instance())

class ParamLoader : public iniFileLoaderBase
{
private:
    static const wchar_t* const params;// = L"params.ini"; 

public:
  ParamLoader();
  static ParamLoader* Instance();

  int	NumAgents;
  int	NumObstacles;
  double MinObstacleRadius;
  double MaxObstacleRadius;

  //number of horizontal cells used for spatial partitioning
  int   NumCellsX;
  //number of vertical cells used for spatial partitioning
  int   NumCellsY;

  //how many samples the smoother will use to average a value
  int   NumSamplesForSmoothing;

  //used to tweak the combined steering force (simply altering the MaxSteeringForce
  //will NOT work!This tweaker affects all the steering force multipliers
  //too).
  double SteeringForceTweaker;

  double MaxSteeringForce;
  double MaxSpeed;
  double VehicleMass;

  double VehicleScale;
  double MaxTurnRatePerSecond;

  double SeparationWeight;
  double AlignmentWeight ;
  double CohesionWeight  ;
  double ObstacleAvoidanceWeight;
  double WallAvoidanceWeight;
  double WanderWeight    ;
  double SeekWeight      ;
  double FleeWeight      ;
  double ArriveWeight    ;
  double PursuitWeight   ;
  double OffsetPursuitWeight;
  double InterposeWeight ;
  double HideWeight      ;
  double EvadeWeight     ;
  double FollowPathWeight;

  //how close a neighbour must be before an agent perceives it (considers it
  //to be within its neighborhood)
  double ViewDistance;

  //used in obstacle avoidance
  double MinDetectionBoxLength;

  //used in wall avoidance
  double WallDetectionFeelerLength;

  //these are the probabilities that a steering behavior will be used
  //when the prioritized dither calculate method is used
  double prWallAvoidance;
  double prObstacleAvoidance;
  double prSeparation;
  double prAlignment;
  double prCohesion;
  double prWander;
  double prSeek;
  double prFlee;
  double prEvade;
  double prHide;
  double prArrive;
};

#endif