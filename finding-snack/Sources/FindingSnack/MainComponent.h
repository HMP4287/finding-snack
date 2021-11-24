#pragma once
#include "FindingSnack.h"

class MainComponent : FindingSnack {
public:

	MainComponent() {};
	//mainMenu = createScene();
	//stage = createScene(); 

	virtual ~MainComponent() {};
	void enter() {};
	void exit() {};
	void update() {};
	void draw() {};
	void event() {};


	ScenePtr getScene() {
		return mainMenu;
	};


};
