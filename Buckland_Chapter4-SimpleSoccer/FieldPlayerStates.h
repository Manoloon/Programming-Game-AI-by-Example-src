#ifndef FIELDPLAYERSTATES_H
#define FIELDPLAYERSTATES_H
//------------------------------------------------------------------------
//
//  Name: FieldPlayerStates.h
//
//  Desc: States for the field players of Simple Soccer. See my book
//        for detailed descriptions
//
//  Author: Mat Buckland 2003 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------

#include <string>

#include "../FSM/State.h"
#include "../Messaging/Telegram.h"
#include "constants.h"


class FieldPlayer;
class SoccerPitch;


//------------------------------------------------------------------------
class GlobalPlayerState : public State<FieldPlayer>
{
private:
  
  GlobalPlayerState()=default;

public:

  //this is a singleton
  static GlobalPlayerState* Instance();

  void Enter([[maybe_unused]] FieldPlayer* player) override {}

  void Execute(FieldPlayer* player) override;

  void Exit([[maybe_unused]] FieldPlayer* player) override {}

  bool OnMessage(FieldPlayer*, const Telegram&) override;
};

//------------------------------------------------------------------------
class ChaseBall : public State<FieldPlayer>
{
private:
  
  ChaseBall()=default;

public:

  //this is a singleton
  static ChaseBall* Instance();

  void Enter(FieldPlayer* player);

  void Execute(FieldPlayer* player);

  void Exit(FieldPlayer* player);

  bool OnMessage(FieldPlayer*, const Telegram&){return false;}
};

//------------------------------------------------------------------------
class Dribble : public State<FieldPlayer>
{
private:
  
  Dribble()=default;

public:

  //this is a singleton
  static Dribble* Instance();

  void Enter(FieldPlayer* player) override;

  void Execute(FieldPlayer* player) override;

  void Exit([[maybe_unused]] FieldPlayer* player) override {}

  bool OnMessage(FieldPlayer*, const Telegram&) override {return false;}
};


//------------------------------------------------------------------------
class ReturnToHomeRegion: public State<FieldPlayer>
{
private:
  
  ReturnToHomeRegion()=default;

public:

  //this is a singleton
  static ReturnToHomeRegion* Instance();

  void Enter(FieldPlayer* player) override;

  void Execute(FieldPlayer* player) override;

  void Exit(FieldPlayer* player) override;

  bool OnMessage(FieldPlayer*, const Telegram&) override {return false;}
};

//------------------------------------------------------------------------
class Wait: public State<FieldPlayer>
{
private:
  
  Wait()=default;

public:

  //this is a singleton
  static Wait* Instance();

  void Enter(FieldPlayer* player) override;

  void Execute(FieldPlayer* player) override;

  void Exit(FieldPlayer* player) override;

  bool OnMessage(FieldPlayer*, const Telegram&) override {return false;}
};

//------------------------------------------------------------------------
class KickBall: public State<FieldPlayer>
{
private:
  
  KickBall()=default;

public:

  //this is a singleton
  static KickBall* Instance();

  void Enter(FieldPlayer* player) override;

  void Execute(FieldPlayer* player) override;

  void Exit([[maybe_unused]] FieldPlayer* player) override {}

  bool OnMessage(FieldPlayer*, const Telegram&) override {return false;}
};

//------------------------------------------------------------------------
class ReceiveBall: public State<FieldPlayer>
{
private:
  
  ReceiveBall()=default;

public:

  //this is a singleton
  static ReceiveBall* Instance();

  void Enter(FieldPlayer* player) override;

  void Execute(FieldPlayer* player) override;

  void Exit(FieldPlayer* player) override;

  bool OnMessage(FieldPlayer*, const Telegram&) override {return false;}
};


//------------------------------------------------------------------------
class SupportAttacker: public State<FieldPlayer>
{
private:
  
  SupportAttacker()=default;

public:

  //this is a singleton
  static SupportAttacker* Instance();

  void Enter(FieldPlayer* player) override;

  void Execute(FieldPlayer* player) override;

  void Exit(FieldPlayer* player) override;

  bool OnMessage(FieldPlayer*, const Telegram&) override {return false;}
};

#endif