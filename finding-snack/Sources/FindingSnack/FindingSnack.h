#pragma once
#include <bangtal> 
#include <stdio.h> // ��� Ȯ�� �� 

//#include "MainComponent.h" // �̰��� ������ ���. �̰��� �ؼ����ڸ� Main��finding��  ����ϴµ� �׻���������� �ҷ�����
// �׷��� �׻���������� �� �Ʒ��� �ִ� 
// ���� Ʋ�� 
using namespace bangtal;

class FindingSnack
{
public:
	//FindingSnack* pSelf;
	ScenePtr mainMenu;
	ScenePtr stageSelection;
	ScenePtr stage;

	ObjectPtr btn; 

	FindingSnack() {

		//MainComponent mainComponent;
		//mainMenu = mainComponent.getScene();



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

