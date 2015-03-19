#include "../include/Phase.h"
  // enum class PhaseType{ 
  //   // Start
  //   BeginGame,
  //   OpeningRollOne,
  //   OpeningRollTwo,
  //   FirstMove,
  //   // Normal turns
  //   BeginningOfTurn,
  //   Roll,
  //   Move,
  //   // Finish
  //   EndGame,
  // };
  // class Phase{
  //   public:
  //     Phase(Phase other) = 0;
  //     std::string toString() = 0;
  //   private:
  //     PhaseType part_of_turn_;
  //     Player    player_on_turn_;
  //     uint      turn_number_;

  // };

  // class BeginGamePhase : public Phase {
  //   public:
  //     BeginGamePhase();
  //     BeginGamePhase(Phase prevPhase);
  //     std::string toString();
  // };
  Phase::Phase(){
    turn_number_ = kFirstTurnNumber;
    player_on_turn_ = Player(kFirstColorOnTurn);
    part_of_turn_ = PhaseType::BeginGame;
  }

  std::string Phase::toString(){
    return "Nonsense phase";
  }


  BeginGamePhase::BeginGamePhase(){
    this->turn_number_ = kFirstTurnNumber;
    this->player_on_turn_ = Player(kFirstColorOnTurn);
    this->part_of_turn_ = PhaseType::BeginGame;

    // set_turn_number(kFirstTurnNumber);
    // set_player_on_turn_(Player(kDFirstColorOnTurn));
    // set_part_of_turn_(PhaseType::BeginGame)
  }

  std::string BeginGamePhase::toString(){
    return player_on_turn_.toString() + " is beginning the game";
  }


  OpeningRollOnePhase::OpeningRollOnePhase(BeginGamePhase prevPhase){
    turn_number_ = prevPhase.turn_number();
    player_on_turn_ = prevPhase.player_on_turn();
    part_of_turn_ = PhaseType::OpeningRollOne;
  }

  std::string OpeningRollOnePhase::toString(){
    return player_on_turn_.toString() + " is rolling for initiative";
  }


  // BeginGamePhase::BeginGamePhase(Phase prevPhase){
  //   return OpeningRollOnePhase(player_on_turn);
  // }


/*


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
  /*
  
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