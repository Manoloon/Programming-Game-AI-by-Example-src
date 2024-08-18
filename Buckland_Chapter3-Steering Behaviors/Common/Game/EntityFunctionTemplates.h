#ifndef GAME_ENTITY_FUNCTION_TEMPLATES
#define GAME_ENTITY_FUNCTION_TEMPLATES

#include "BaseGameEntity.h"
#include <memory>
#include "../2d/geometry.h"


//////////////////////////////////////////////////////////////////////////
//
//  Some useful template functions
//
//////////////////////////////////////////////////////////////////////////

//------------------------- Overlapped -----------------------------------
//
//  tests to see if an entity is overlapping any of a number of entities
//  stored in a std container
//------------------------------------------------------------------------
template <class T, class conT>
bool Overlapped(const std::shared_ptr<T>& ob, const conT& conOb, double MinDistBetweenObstacles = 40.0)
{
    for(const auto& currentObj : conOb)
    {
      if (TwoCirclesOverlapped(ob->Pos(),ob->BRadius()+MinDistBetweenObstacles,                             
                             currentObj->Pos(),currentObj->BRadius()))
      {
        return true;
      }
    }
   return false;
  }

//----------------------- TagNeighbors ----------------------------------
//
//  tags any entities contained in a std container that are within the
//  radius of the single entity parameter
//------------------------------------------------------------------------
template <class T, class conT>
void TagNeighbors(const std::shared_ptr<T>& entity, conT& others, const double radius)
{
  for(const auto& other : others)
  //iterate through all entities checking for range
  {
    if(other == entity) return;
    //first clear any current tag
    other->UnTag();

    //work in distance squared to avoid sqrts
    Vector2D to = other->Pos() - entity->Pos();
    double distanceSq = to.LengthSq();
    //the bounding radius of the other is taken into account by adding it 
    //to the range
    double effectiveRange = (radius + other->BRadius()) * (radius + other->BRadius());

    //if entity within range, tag for further consideration
    if (distanceSq < effectiveRange)
    {
      other->Tag();
    }
  }//next entity
}

//------------------- EnforceNonPenetrationConstraint ---------------------
//
//  Given a pointer to an entity and a std container of pointers to nearby
//  entities, this function checks to see if there is an overlap between
//  entities. If there is, then the entities are moved away from each
//  other
//------------------------------------------------------------------------
template <class T, class conT>
void EnforceNonPenetrationConstraint(const std::shared_ptr<T>& entity, const conT& others)
{
   //iterate through all entities checking for any overlap of bounding
  //radii
  for(const auto& other : others)
  {
    //make sure we don't check against this entity
    if (other == entity) continue;

    //calculate the distance between the positions of the entities
    Vector2D ToEntity = entity->Pos() - other->Pos();

    double DistFromEachOther = ToEntity.Length();

    //if this distance is smaller than the sum of their radii then this
    //entity must be moved away in the direction parallel to the
    //ToEntity vector   
    double AmountOfOverLap = other->BRadius() + entity->BRadius() -
                             DistFromEachOther;

    if (AmountOfOverLap >= 0)
    {
      //move the entity a distance away equivalent to the amount of overlap.
      entity->SetPos(entity->Pos() + (ToEntity/DistFromEachOther) *
                     AmountOfOverLap);
    }
  }//next entity
}

#endif