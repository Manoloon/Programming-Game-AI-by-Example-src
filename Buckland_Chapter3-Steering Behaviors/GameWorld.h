#ifndef GameWorld_H
#define GameWorld_H
//#pragma warning (disable:4786)
//------------------------------------------------------------------------
//
//  Name:   GameWorld.h
//
//  Desc:   All the environment data and methods for the Steering
//          Behavior projects. This class is the root of the project's
//          update and render calls (excluding main of course)
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include <windows.h>
#include <vector>
#include <memory>
#include "../2d/Vector2D.h"
#include "../time/PrecisionTimer.h"
#include "../misc/CellSpacePartition.h"
#include "../Game/BaseGameEntity.h"
#include "../Game/EntityFunctionTemplates.h"
#include "vehicle.h"

class Obstacle;
class Wall2D;
class Path;

typedef std::vector<BaseGameEntity*>::iterator  ObIt;

class GameWorld
{ 
private:

  //a container of all the moving entities
  std::vector<std::shared_ptr<Vehicle>>   m_Vehicles;

  //any obstacles
  std::vector<std::shared_ptr<BaseGameEntity>>  m_Obstacles;

  //container containing any walls in the environment
  std::vector<Wall2D>           m_Walls;

  std::unique_ptr<CellSpacePartition<std::shared_ptr<Vehicle>>> m_pCellSpace;

  //local copy of client window dimensions
  int                           m_cxClient;
  int                           m_cyClient;
  //set true to pause the motion
  bool                          m_bPaused;
  //the position of the crosshair
  Vector2D                      m_vCrosshair;
  
  //flags to turn aids and obstacles etc on/off
  bool                          m_bShowWalls;
  bool                          m_bShowObstacles;
  bool                          m_bShowPath;
  bool                          m_bShowWanderCircle;
  bool                          m_bShowSteeringForce;
  bool                          m_bShowFeelers;
  bool                          m_bShowDetectionBox;
  bool                          m_bShowFPS;
  bool                          m_bRenderNeighbors;
  bool                          m_bViewKeys;
  bool                          m_bShowCellSpaceInfo; 

  //keeps track of the average FPS
  double                         m_dAvFrameTime;
  //any path we may create for the vehicles to follow
  std::unique_ptr<Path>         m_pPath;

  void CreateObstacles();

  void CreateWalls();

public:
  
  GameWorld(int cx, int cy);

  void  Update(double time_elapsed);

  void  Render();

  void Restart(int cx,int cy);

  void  NonPenetrationContraint(std::shared_ptr<Vehicle> v){EnforceNonPenetrationConstraint(v, m_Vehicles);}

  void  TagVehiclesWithinViewRange(std::shared_ptr<Vehicle> pVehicle, double range)
  {
    TagNeighbors(pVehicle, m_Vehicles, range);
  }

  void  TagObstaclesWithinViewRange(std::shared_ptr<Vehicle> pVehicle, double range)
  {
    TagNeighbors(pVehicle, m_Obstacles, range);
  }

  const std::vector<Wall2D>&          Walls(){return m_Walls;}                          
  std::unique_ptr<CellSpacePartition<std::shared_ptr<Vehicle>>>  CellSpace(){return std::move(m_pCellSpace);}
  std::vector<std::shared_ptr<BaseGameEntity>> Obstacles() {return m_Obstacles;}
  std::vector<std::shared_ptr<Vehicle>>  Agents() {return m_Vehicles;}

  //handle WM_COMMAND messages
  void        HandleKeyPresses(WPARAM wParam);
  void        HandleMenuItems(WPARAM wParam, HWND hwnd);
  
  void        TogglePause(){m_bPaused = !m_bPaused;}
  bool        Paused()const{return m_bPaused;}

  Vector2D    Crosshair()const{return m_vCrosshair;}
  void        SetCrosshair(POINTS p);
  void        SetCrosshair(Vector2D v){m_vCrosshair=v;}

  int   cxClient()const{return m_cxClient;}
  int   cyClient()const{return m_cyClient;}
 
  bool  RenderWalls()const{return m_bShowWalls;}
  bool  RenderObstacles()const{return m_bShowObstacles;}
  bool  RenderPath()const{return m_bShowPath;}
  bool  RenderDetectionBox()const{return m_bShowDetectionBox;}
  bool  RenderWanderCircle()const{return m_bShowWanderCircle;}
  bool  RenderFeelers()const{return m_bShowFeelers;}
  bool  RenderSteeringForce()const{return m_bShowSteeringForce;}

  bool  RenderFPS()const{return m_bShowFPS;}
  void  ToggleShowFPS(){m_bShowFPS = !m_bShowFPS;}
  
  void  ToggleRenderNeighbors(){m_bRenderNeighbors = !m_bRenderNeighbors;}
  bool  RenderNeighbors()const{return m_bRenderNeighbors;}
  
  void  ToggleViewKeys(){m_bViewKeys = !m_bViewKeys;}
  bool  ViewKeys()const{return m_bViewKeys;}

};

#endif