#include "partner.h"
#include "DataSetting.h"

partner::partner(Vec2 position, Size size)
{
	//sprite create
	partnerPuzzle = Sprite::create("none.png");
	partnerPuzzle->setPosition(position);
	partnerPuzzle->setContentSize(size);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	float x = size.width/visibleSize.width;
	float y = size.height/visibleSize.height;
	partnerPuzzle->setScaleX(x);
	partnerPuzzle->setScaleY(y);
	partnerPuzzle->setZOrder(PARTNER_Z);

}


partner::~partner(void)
{
}

Sprite* partner::getPartner(){
	return partnerPuzzle;
}
