#pragma once

class MainMenu {
public: 
	FindingSnack* findingSnackGame;
	ScenePtr MainMenuScene; 

	MainMenu(FindingSnack * findingSnack) {
		findingSnackGame = findingSnack;
	};

	// ��� �Լ����� ���������� ����� �Լ��� 
/*
start();
Enter();
Exit();
Update(int dt);
Draw();
Event(void event);
getScene();*/


	
};
