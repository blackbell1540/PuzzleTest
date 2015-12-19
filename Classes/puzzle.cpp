#include "puzzle.h"
#include "partner.h"
#include "DataSetting.h"

puzzle::puzzle(int puzzleNumber, float puzzleX, float puzzleY,
	float partnerX, float partnerY, string imageURI)
{
	corrected = false;

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

//add touch event listener
void puzzle::addEvent(){
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(puzzle::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(puzzle::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(puzzle::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(puzzle::onTouchCancelled, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, spritePuzzle);
}

//compare touch location with puzzle
bool puzzle::compareLocation(Vec2 onTouchBeginLocation){
	Vec2 location = onTouchBeginLocation;
	if(puzzleRect.containsPoint(location))
	{ return true; }
	return false;
}

//touch start - compare
bool puzzle::onTouchBegan(Touch *touch, Event *unused_event){
	puzzleRect = spritePuzzle->getBoundingBox();
	partnerRect = pt->getPartner()->getBoundingBox();
	if(compareLocation(touch->getLocation()))
	{ touched = true; return true; }
	return false;
}
//touch move(drag) - move to current touch location
void puzzle::onTouchMoved(Touch *touch, Event *unused_event){
	if(touched){
		spritePuzzle->setPosition(touch->getLocation());
		puzzleRect = spritePuzzle->getBoundingBox();
		partnerRect = pt->getPartner()->getBoundingBox();
		if(puzzleRect.intersectsRect(partnerRect)){
			corrected = true;
			spritePuzzle->setPosition(pt->getPartner()->getPosition());
		}
	}else{
		spritePuzzle->setPosition(puzzlePosition);
	}
}
//touch end - return to created location
void puzzle::onTouchEnded(Touch *touch, Event *unused_event){
	if (false == corrected)	{
		spritePuzzle->setPosition(createPosition);
	}	
	touched = false;
}

void puzzle::onTouchCancelled(Touch *touch, Event *unused_event){
	if (false == corrected)	{
		spritePuzzle->setPosition(createPosition);
	}
	touched = false;
}