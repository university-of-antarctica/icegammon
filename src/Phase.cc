#include "../include/Phase.h"
 #include <string>
#include <sstream>

// const Color kFirstColorOnTurn = Color::WHITE;
// const uint kFirstTurnNumber = 1;
// RollPhase roll = RollPhase();
// const PhaseType& kFirstPhaseType = roll;

  Phase::Phase(){
    turn_number_ = 1;//kFirstTurnNumber;
    player_on_turn_ = Player(Color::WHITE);
    RollPhase* roll = new RollPhase();
    part_of_turn_ = roll;
  }

  std::string Phase::toString(){
    std::ostringstream oss;
    oss << player_on_turn_.toString() << " is in phase " << part_of_turn_->ToString() << " on turn " << turn_number_ << std::endl ;
    return oss.str();
    //return "Nonsense phase";
  }

  void Phase::SwitchPlayer(){
    if(player_on_turn_.color() == Color::WHITE){
      player_on_turn_ = Player(Color::BLACK);
    } else {
      player_on_turn_ = Player(Color::WHITE);
    }
  }





/*
  BeginGamePhase::BeginGamePhase(){
    this->turn_number_ = kFirstTurnNumber;
    this->player_on_turn_ = Player(kFirstColorOnTurn);
    this->part_of_turn_ = PhaseType::BeginGame;

    // set_turn_number(kFirstTurnNumber);
    // set_player_on_turn_(Player(kDFirstColorOnTurn));
    // set_part_of_turn_(PhaseType::BeginGame)
  }

  Phase BeginGamePhase::to(OpeningRollOnePhase &nextPhase){
    nextPhase.set_turn_number(1);
    nextPhase.set_player_on_turn(player_on_turn_);
    return nextPhase;
  }

  std::string BeginGamePhase::toString(){
    // return player_on_turn_.toString() + " is beginning the game on turn " + std::string(turn_number_) + ".";
    std::cout << player_on_turn_.toString() << " is beginning the game on turn " << turn_number_ << "." << std::endl;
    return "phase string";
  }


  OpeningRollOnePhase::OpeningRollOnePhase(){
    part_of_turn_ = PhaseType::OpeningRollOne;
  }

  Phase OpeningRollOnePhase::to(BeginGamePhase &nextPhase){
    // start over
    nextPhase.IncrementTurn();
    return nextPhase;
  }
  Phase OpeningRollOnePhase::to(OpeningRollOnePhase &nextPhase){
    nextPhase.set_player_on_turn(player_on_turn_);
    nextPhase.PassTurn();
    nextPhase.set_turn_number(turn_number_);
    nextPhase.IncrementTurn();
    return nextPhase;
    // redo openingrollone
  }

  std::string OpeningRollOnePhase::toString(){
    // return player_on_turn_.toString() + " is rolling for initiative on turn " + std::string(turn_number_) + ".";
    std::cout << player_on_turn_.toString() << " is rolling for initiative on turn " << turn_number_ << "." << std::endl;
    return "phase string";
  }


  // BeginGamePhase::BeginGamePhase(Phase prevPhase){
  //   return OpeningRollOnePhase(player_on_turn);
  // }


 


  OpeningRollOnePhase::OpeningRollOnePhase(Player firstToRoll){
    player_on_turn = firstToRoll;
    part_of_turn = PhaseType::OpeningRollOne;
    turn_number_ = kFirstTurnNumber;
  }

  std::string OpeningRollOnePhase::toString(){
    return player_on_turn.toString() + " is performing the first roll";
  }
  Phase OpeningRollOnePhase::to(PhaseType nextPhaseType){
    return OpeningRollTwoPhase(player_on_turn);
  }


  class OpeningRollOnePhase : public Phase {
    public:
      OpeningRollOnePhase();
      Phase to(PhaseType nextPhaseType);
  };

  class OpeningRollTwoPhase : public Phase {
    public:
      OpeningRollTwoPhase();
      Phase to(PhaseType nextPhaseType);
  };

  class FirstMovePhase : public Phase {
    public:
      FirstMovePhase();
      Phase to(PhaseType nextPhaseType);
  };
  
  
  class BeginTurnPhase : public Phase {
    public:
      BeginTurnPhase(Phase previousPhase);
  };

  class MovePhase : public Phase {
    public:
      MovePhase(Phase previousPhase);
  };
  
  class RollPhase : public Phase {
    public:
      RollPhase(Phase previousPhase);
  };

  class EndGamePhase : public Phase {
    public:
      EndGamePhase(Phase previousPhase);
  };
  */