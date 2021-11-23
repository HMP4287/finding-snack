#pragma once


#include <bangtal> 
#include <stdio.h> // 출력 확인 용 

#include "MainMenu/MainMenu.h"

using namespace bangtal;
class FindingSnack
{

public:

	MainMenu mainMenu;
	//SelectStage selectStage;
	//Stage stages; // 클래스이름을 복수로할지 단수로할지.

	//ScenePtr scenes[30];

	// 생성자 
	FindingSnack(MainMenu main) : mainMenu(main) {};

	


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

