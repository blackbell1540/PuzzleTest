#include "puzzle.h"
#include "partner.h"

puzzle::puzzle(int puzzleNumber, float puzzleX, float puzzleY,
	float partnerX, float partnerY, string imageURI, Node* _scene)
{
	//set baseScene 
	scene = _scene;
	//set puzzleNumber
	this->puzzleNumber = puzzleNumber;
	//create spritePuzzle
	//addChild spritePuzzle to scene
	spritePuzzle = Sprite::create(imageURI);
	spritePuzzle->setPosition(Vec2(puzzleX, puzzleY));
	spritePuzzle->setZOrder(1);//PUZZLE_Z
	spritePuzzle->setTag(puzzleNumber);
	scene->addChild(spritePuzzle);

	createPartner(Vec2(partnerX, partnerY), puzzleNumber);

}
puzzle::~puzzle()
{
	
}

void puzzle::createPartner(Vec2 partnerPosition, int partnerNumber)
{
	Size spriteSize = spritePuzzle->getContentSize();
	partner(partnerPosition, spriteSize, partnerNumber, scene);
}
