#ifndef __PUZZLE_CONTROLLER_H__
#define __PUZZLE_CONTROLLER_H__

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class puzzleController
{
public:
	//puzzle info
	int number;
	Vec2 currentPosition;
	Vec2 createPosition;

    //constructor
	puzzleController();
	~puzzleController();

	//pick up puzzle - get puzzle info
	void pickup(int number, Vec2 position);

	//pick out puzzle - cotroller null, call not correct
	void pickout();

	//drag - move to touchPoint
	//call chkBound
	void movePuzzle(Vec2 touchPoint);

	//check bound
	//call chkPartner
	void chkBound();

	//check partner
	//1 : call correct //0: call chkRelease
	bool chkPartner();
	
	//check release
	//1 : call notCorrect //0: none action
	bool chkRelease();

	//set result - controller null
	//correct - set puzzlePosition = partnerPosition
	void correct();
	//not correct - set puzzlePosition = createPosition
	void notCorrect();
    


};

#endif // __PUZZLE_CONTROLLER_H__
