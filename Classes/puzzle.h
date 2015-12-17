#ifndef __PUZZLE_H__
#define __PUZZLE_H__

#include "cocos2d.h"
#include "partner.h"
#include <string>

using namespace std;
using namespace cocos2d;

class puzzle
{
private:
	partner* pt;

	//puzzle Sprite
	Sprite* spritePuzzle;

	//puzzle Number
	int puzzleNumber;

	//create puzzle position
	Vec2 puzzlePosition;

	//create partner position
	Vec2 partnerPosition;

	//baseScene
	//Node* scene;

public:
	//constructor(puzzle number, puzzle position, partner position)
    puzzle(int puzzleNumber, float puzzleX, float puzzleY,
		float partnerX, float partnerY, string imageURI);

	//create partner
	void createPartner(Vec2 partnerPosition, int partnerNumber);

	//get puzzle
	Sprite* getPuzzle();
	Sprite* getPartnerPuzzle();

	~puzzle();
};

#endif // __PUZZLE_H__
