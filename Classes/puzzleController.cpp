#include "puzzleController.h"

puzzleController::puzzleController(){
	
}
puzzleController::~puzzleController(){
	
}

//pick up puzzle - get puzzle info
void puzzleController::pickup(int number, Vec2 position){
}

//pick out puzzle - cotroller null, call not correct
void puzzleController::pickout(){
}

//drag - move to touchPoint
//call chkBound
void puzzleController::movePuzzle(Vec2 touchPoint){
}

//check bound
//call chkPartner
void puzzleController::chkBound(){
}

//check partner
//1 : call correct //0: call chkRelease
bool puzzleController::chkPartner(){
	return 1;
}
	
//check release
//1 : call notCorrect //0: none action
bool puzzleController::chkRelease(){
	return 1;
}

//set result - controller null
//correct - set puzzlePosition = partnerPosition
void puzzleController::correct(){
}
//not correct - set puzzlePosition = createPosition
void puzzleController::notCorrect(){
}