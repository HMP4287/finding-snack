#pragma once
#include <bangtal> 
#include <stdio.h> // 출력 확인 용 

using namespace bangtal;

class FindingSnack
{
public:
	//FindingSnack* pSelf;
	ScenePtr mainMenu;
	ScenePtr stageSelection;
	ScenePtr stage;

	ObjectPtr btn; 
public:
	FindingSnack() {
		//pSelf = this;

	}
	virtual ~FindingSnack();

	virtual void enter() = 0;
	virtual void exit() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void event() = 0;


	virtual ScenePtr getScene() = 0;


};

