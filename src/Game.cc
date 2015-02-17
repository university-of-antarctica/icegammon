class Game{

public:
	Color turn = WHITE; //TODO: roll for initiative

	void passTurn(){
		if(turn==WHITE){
			turn=BLACK;
		}
		else{
			turn=WHITE;
		}
	}


};