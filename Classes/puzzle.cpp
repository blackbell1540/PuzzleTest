#include "puzzle.h"
#include "partner.h"
#include "DataSetting.h"

puzzle::puzzle(int puzzleNumber, float puzzleX, float puzzleY,
	float partnerX, float partnerY, string imageURI)
{
	//set puzzleNumber
	this->puzzleNumber = puzzleNumber;

	//create spritePuzzle
	spritePuzzle = Sprite::create(imageURI);
	spritePuzzle->setPosition(Vec2(puzzleX, puzzleY));
	spritePuzzle->setZOrder(PUZZLE_Z);//PUZZLE_Z
	spritePuzzle->setTag(puzzleNumber);

	//create spritePartner
	createPartner(Vec2(partnerX, partnerY), puzzleNumber);

}
puzzle::~puzzle()
{
	
}

void puzzle::createPartner(Vec2 partnerPosition, int partnerNumber)
{
	Size spriteSize = spritePuzzle->getContentSize();
	pt = new partner(partnerPosition, spriteSize, partnerNumber);
}

Sprite* puzzle::getPuzzle(){
	return spritePuzzle;
}

Sprite* puzzle::getPartnerPuzzle(){
	return pt->getPartner();
}