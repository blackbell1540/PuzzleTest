#ifndef __PUZZLE_H__
#define __PUZZLE_H__

#include "cocos2d.h"
#include <string>

using namespace std;
using namespace cocos2d;

class puzzle
{
public:
	//puzzle Sprite
	Sprite* spritePuzzle;

	//puzzle Number
	int puzzleNumber;

	//create puzzle position
	Vec2 puzzlePosition;

	//create partner position
	Vec2 partnerPosition;

	////////////////////////////////////////////////////////////////////////////////

	//constructor(puzzle number, puzzle position, partner position)
    puzzle(int puzzleNumber, float puzzleX, float puzzleY, float partnerX, float partnerY, string image);
	
	void createPartner(Vec2 partnerPosition, int partnerNumber);

	~puzzle();
    
};

#endif // __PUZZLE_H__
