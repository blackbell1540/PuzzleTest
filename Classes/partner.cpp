#include "partner.h"
#include "DataSetting.h"

partner::partner(Vec2 position, Size size, int number, Node* Scene)
{
	//set puzzle number
	partnerNumebr = number;

	//sprite create
	partnerPuzzle = Sprite::create("Grobot_03_01_bg.jpg");
	partnerPuzzle->setPosition(position);
	partnerPuzzle->setContentSize(size);
	Scene->addChild(partnerPuzzle, PARTNER_Z);

}


partner::~partner(void)
{
}
