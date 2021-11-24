#pragma once

class MainMenu {
public: 
	FindingSnack* findingSnackGame;
	ScenePtr MainMenuScene; 

	MainMenu(FindingSnack * findingSnack) {
		findingSnackGame = findingSnack;
	};

	// 모든 함수에서 공통적으로 사용할 함수들 
/*
start();
Enter();
Exit();
Update(int dt);
Draw();
Event(void event);
getScene();*/


	
};
