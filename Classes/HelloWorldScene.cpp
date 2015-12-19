#include "HelloWorldScene.h"

//puzzle classes
#include "puzzle.h"
#include "partner.h"
#include "puzzleController.h"
#include "DataSetting.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
   auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	/*background image*/
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Sprite* backgroundSprite = Sprite::create("background.jpg");

    // position the sprite on the center of the screen
	backgroundSprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    // add the sprite as a child to this layer
	this->addChild(backgroundSprite, BACKGROUND_Z);
    
	puzzle* pz1 = new puzzle(1, 200.0f, 200.0f, 500.0f, 500.0f, "left_leg.png");
	pz1->addEvent();
	Sprite* spz1 = pz1->getPuzzle(); 
	Sprite* ppz1 = pz1->getPartnerPuzzle();
	this->addChild(spz1);
	this->addChild(ppz1);

	puzzle* pz2 = new puzzle(2, 300.0f, 300.0f, 800.0f, 800.0f, "right_leg.png");
	pz2->addEvent();
	Sprite* spz2 = pz2->getPuzzle(); 
	Sprite* ppz2 = pz2->getPartnerPuzzle();
	this->addChild(spz2);
	this->addChild(ppz2);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
