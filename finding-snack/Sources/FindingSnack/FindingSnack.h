#pragma once


#include <bangtal> 
#include <stdio.h> // 출력 확인 용 

#include "MainMenu/MainMenu.h"
#include "Stage/Stage.h"
#include "SelectStage/SelectStage.h"


using namespace bangtal;
class FindingSnack
{

public:

	MainMenu * mainMenu;
	SelectStage * selectStage;
	Stage * stages; 

	//ScenePtr scenes[30];

	// 생성자 
	//FindingSnack(MainMenu main) : mainMenu(main) {};

	


	// 오버라이딩할 함수들 
	/*
	start();
	Enter();
	Exit();
	Update(int dt);
	Draw();
	Event(void event);
	getScene();*/


};

