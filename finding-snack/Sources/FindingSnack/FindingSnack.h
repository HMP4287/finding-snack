#pragma once


#include <bangtal> 
#include <stdio.h> // ��� Ȯ�� �� 

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

	// ������ 
	//FindingSnack(MainMenu main) : mainMenu(main) {};

	


	// �������̵��� �Լ��� 
	/*
	start();
	Enter();
	Exit();
	Update(int dt);
	Draw();
	Event(void event);
	getScene();*/


};

