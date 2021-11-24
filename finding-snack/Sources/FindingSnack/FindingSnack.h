#pragma once
#include <bangtal> 
#include <stdio.h> // 출력 확인 용 

//#include "MainComponent.h" // 이것이 에러가 뜬다. 이것을 해석하자면 Main은finding을  상속하는데 그상속한파일을 불러오라
// 그러나 그상속한파일은 이 아래에 있다 
// 순서 틀림 
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

