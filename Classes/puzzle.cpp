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

	createPosition = Vec2(puzzleX,puzzleY);
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
	listener->onTouchEnded = CC_CALLBACK_2(puzzle::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(puzzle::onTouchCancelled, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, spritePuzzle);
}

bool puzzle::compareLocation(Vec2 onTouchBeginLocation){
	Vec2 location = onTouchBeginLocation;
	Rect rect = spritePuzzle->getBoundingBox();
	if(rect.containsPoint(location))
	{ return true; }
	return false;
}

bool puzzle::onTouchBegan(Touch *touch, Event *unused_event){
	if(compareLocation(touch->getLocation()))
	{ touched = true; return true; }
	return false;
}
void puzzle::onTouchMoved(Touch *touch, Event *unused_event){
	if(touched){
		puzzlePosition = touch->getLocation();
		MoveTo *pAction = MoveTo::create(3.0f, puzzlePosition);
		spritePuzzle->runAction(pAction);
	}else{
		spritePuzzle->setPosition(puzzlePosition);
	}
}
void puzzle::onTouchEnded(Touch *touch, Event *unused_event){
	spritePuzzle->setPosition(createPosition);
	touched = false;
}
void puzzle::onTouchCancelled(Touch *touch, Event *unused_event){
	spritePuzzle->setPosition(createPosition);
}