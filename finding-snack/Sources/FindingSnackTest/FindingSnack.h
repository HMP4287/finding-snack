#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <bangtal>

using namespace bangtal;
// Product
class FindingSnack
{
private:
    //std::string dough;
    //std::string sauce;
    //std::string topping;
    ScenePtr mainMenuScene;
    ScenePtr stageSelectScene;
    ScenePtr stagesScene[30];

public:
    FindingSnack() { }
    ~FindingSnack() { }

    void setMainMenuScene(ScenePtr mm) { mainMenuScene = mm; };
    void setStageSelectScene(ScenePtr ss) { stageSelectScene = ss; };
    void SetStages(ScenePtr s[30]) { for (int i = 0; i < 30; i++) stagesScene[i] = s[i];  } // 30 »ó¼öÈ­ 

    //void ShowPizza()
    //{
    //    std::cout << " Yummy !!!" << std::endl
    //        << "Pizza with Dough as " << dough
    //        << ", Sauce as " << sauce
    //        << " and Topping as " << topping
    //        << " !!! " << std::endl;
    //}
    void start() {
        startGame(mainMenuScene);
    }


};
