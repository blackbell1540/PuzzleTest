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

void puzzle::addEvent(){
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(puzzle::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(puzzle::onTouchMoved, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, spritePuzzle);
}

bool puzzle::onTouchBegan(Touch *touch, Event *unused_event){
	
	return true;
}
void puzzle::onTouchMoved(Touch *touch, Event *unused_event){
	puzzlePosition = touch->getLocation();
	MoveTo *pAction = MoveTo::create(1.0f, puzzlePosition);
		spritePuzzle->runAction(pAction);
}
void puzzle::onTouchEnded(Touch *touch, Event *unused_event){
}
void puzzle::onTouchCancelled(Touch *touch, Event *unused_event){
}