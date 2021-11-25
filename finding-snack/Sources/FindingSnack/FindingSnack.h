#pragma once
#include <bangtal>

using namespace bangtal;
// Product
class FindingSnack
{
// private or protected (MainMenu���� �� �����ϴ��� Ȯ�� �ʿ�)
protected:
    // ������ �޼ҵ� Scene������� ����������, �ƴ� getter setter ���� �������� ���������� 
    // => �ϴ� Scene ��� 

    // getter setter �� �ʿ��Ѱ� ??? reset �� ???
    // �ʵ带 protected || private�� �θ� �ʿ��ҵ��ϴ�. �ٷ� ���� �Ұ��� 
    // => �ٸ����� �ʿ������ ����� ��� Ȯ�� �غ��� 


    // getter setter �� ���� �ʿ��Ұ�.
    // ���ʿ��� ������ ����� ���� �ɰ�.


    // �������� ��𿡼� �ʱ�ȭ �� ���ΰ�. 
    // Component �ȿ��� ? || FindingSnack ���� ? 
    // => Component �ȿ���. 



    // �������� �� 30�� (30�� ���?ȭ)


    // MainMenuData 
    ScenePtr mainMenuScene;
    ObjectPtr startBtn; 

    // MainMenuData 

    // StageSelectData
    ScenePtr stageSelectScene;

    const int STAGE_MAX = 30;
    // isClear[30];
    // 

    // 
    ScenePtr stagesScene[30];

public:
    // Constructor 
    FindingSnack() {
        //mainMenuScene = Scene::create("MainMenuScene", "Images/Background/startScene.PNG");

        //stageSelectScene = NULL;
        //for (int i = 0; i < 30; i++) stagesScene[i] = NULL;
    }
    ~FindingSnack() {}
    // Constructor 





    // MainMenuMethod

    // setter 
    void setMainMenuScene(ScenePtr s) { mainMenuScene = s; };
    void setMainMenuStartBtn(ObjectPtr o) { startBtn = o; }; 

    // getter 
    ScenePtr getMainMenuScene() { return mainMenuScene; };
    ObjectPtr getMainMenuStartBtn() { return startBtn; };


    // reset 
    void resetMainMenu() { mainMenuScene = Scene::create("MainMenuScene", "Images/Background/startScene.png"); }; // �ʱ�ȭ & ���� �Լ�
   
    // MainMenuMethod 










    void setStageSelectScene(ScenePtr ss) { stageSelectScene = ss; };
    // 30 -> STAGE_MAX
    void SetStages(ScenePtr s[30]) { for (int i = 0; i < 30; i++) stagesScene[i] = s[i]; };




    // err: ���ܰ� �߻��� 
    void start() { startGame(mainMenuScene); };

    // virtual �� �ƴ� overriding�� ������ ���� ����� �� �������� Ȯ�� �ʿ� 
    void enter();
    void exit();
    void update();
    void draw();
    void event();

};
