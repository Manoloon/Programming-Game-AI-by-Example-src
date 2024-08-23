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
#include "../2D/Vector2D.h"
#include "../Time/PrecisionTimer.h"
#include "../Misc/CellSpacePartition.h"
#include "../Game/BaseGameEntity.h"
#include "../Game/EntityFunctionTemplates.h"
#include "Vehicle.h"

class Obstacle;
class Wall2D;
class Path;

using ObIt = std::vector<BaseGameEntity*>::iterator;

class GameWorld
{ 
private:

  //a container of all the moving entities
  std::vector<Vehicle*>         m_Vehicles;

  //any obstacles
  std::vector<BaseGameEntity*>  m_Obstacles;

  //container containing any walls in the environment
  std::vector<Wall2D>           m_Walls;

  std::unique_ptr<CellSpacePartition<Vehicle*>> m_pCellSpace;

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

  ~GameWorld();

  void  Update(double time_elapsed);

  void  Render();

  void  NonPenetrationContraint(Vehicle* v) const {EnforceNonPenetrationConstraint(v, m_Vehicles);}

  void  TagVehiclesWithinViewRange(BaseGameEntity* pVehicle, double range)
  {
    TagNeighbors(pVehicle, m_Vehicles, range);
  }

  void  TagObstaclesWithinViewRange(BaseGameEntity* pVehicle, double range)
  {
    TagNeighbors(pVehicle, m_Obstacles, range);
  }

  const std::vector<Wall2D>&          Walls() const {return m_Walls;}                          
  std::unique_ptr<CellSpacePartition<Vehicle*>>  CellSpace(){return std::move(m_pCellSpace);}
  const std::vector<BaseGameEntity*>& Obstacles()const{return m_Obstacles;}
  const std::vector<Vehicle*>&        Agents() const {return m_Vehicles;}


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
  void  ToggleShowPath() {m_bShowPath = !m_bShowPath;}
  bool  RenderPath()const{return m_bShowPath;}
  
  void  ToggleDetectionBox() {m_bShowDetectionBox = !m_bShowDetectionBox; }
  bool  RenderDetectionBox()const{return m_bShowDetectionBox;}

  void  ToggleWanderCircle() {m_bShowWanderCircle = !m_bShowWanderCircle;}
  bool  RenderWanderCircle()const{return m_bShowWanderCircle;}

  void  ToggleFeelers() {m_bShowFeelers = !m_bShowFeelers;}
  bool  RenderFeelers()const{return m_bShowFeelers;}

  void  ToggleSteeringForce() { m_bShowSteeringForce = !m_bShowSteeringForce;}
  bool  RenderSteeringForce()const{return m_bShowSteeringForce;}

  void  ToggleShowFPS(){m_bShowFPS = !m_bShowFPS;}
  bool  RenderFPS()const{return m_bShowFPS;}
  
  void  ToggleRenderNeighbors(){m_bRenderNeighbors = !m_bRenderNeighbors;}
  bool  RenderNeighbors()const{return m_bRenderNeighbors;}
  
  void  ToggleViewKeys(){m_bViewKeys = !m_bViewKeys;}
  bool  ViewKeys()const{return m_bViewKeys;}

  void ToggleCellSpaceInfo() {m_bShowCellSpaceInfo = m_bShowCellSpaceInfo;}
};

#endif