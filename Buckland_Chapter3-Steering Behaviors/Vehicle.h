#ifndef VEHICLE_H
#define VEHICLE_H
//------------------------------------------------------------------------
//
//  Name:   Vehicle.h
//
//  Desc:   Definition of a simple vehicle that uses steering behaviors
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "../Game/MovingEntity.h"
#include "../2d/Vector2D.h"
#include "../misc/Smoother.h"

#include <vector>
#include <list>
#include <string>
#include <memory>

class GameWorld;
class SteeringBehavior;

class Vehicle : public MovingEntity
{

private:

  //a pointer to the world data. So a vehicle can access any obstacle,
  //path, wall or agent data
  std::unique_ptr<GameWorld>   m_pWorld;

  //the steering behavior class
  std::unique_ptr<SteeringBehavior>  m_pSteering;

  //some steering behaviors give jerky looking movement. The
  //following members are used to smooth the vehicle's heading
  std::unique_ptr<Smoother<Vector2D>>  m_pHeadingSmoother;

  //this vector represents the average of the vehicle's heading
  //vector smoothed over the last few frames
  Vector2D             m_vSmoothedHeading;

  //when true, smoothing is active
  bool                  m_bSmoothingOn;
  

  //keeps a track of the most recent update time. (some of the
  //steering behaviors make use of this - see Wander)
  double                m_dTimeElapsed;


  //buffer for the vehicle shape
  std::vector<Vector2D> m_vecVehicleVB;

  //fills the buffer with vertex data
  void InitializeBuffer();

  //disallow the copying of Vehicle types
  Vehicle(const Vehicle&);
  Vehicle& operator=(const Vehicle&);


public:

  Vehicle(std::unique_ptr<GameWorld> world,
         Vector2D  position,
         double    rotation,
         Vector2D  velocity,
         double    mass,
         double    max_force,
         double    max_speed,
         double    max_turn_rate,
         double    scale);

  //updates the vehicle's position and orientation
  void        Update(double time_elapsed) override;

  void        Render() override;
                                                                          
  //-------------------------------------------accessor methods
  std::unique_ptr<SteeringBehavior> Steering() {return std::move(m_pSteering);}
  std::unique_ptr<GameWorld>  World() {return std::move(m_pWorld);} 
  
  Vector2D    SmoothedHeading()const{return m_vSmoothedHeading;}

  bool        isSmoothingOn()const{return m_bSmoothingOn;}
  void        SmoothingOn(){m_bSmoothingOn = true;}
  void        SmoothingOff(){m_bSmoothingOn = false;}
  void        ToggleSmoothing(){m_bSmoothingOn = !m_bSmoothingOn;}
  
  double      TimeElapsed()const{return m_dTimeElapsed;}
 
};

#endif