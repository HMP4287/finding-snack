#pragma once
#include <bangtal>

// enum class �� ��ü �ǿ� 
#define STAGE_MAX 20

using namespace bangtal;
// Product
class FindingSnack
{
//enum class FindingSnackNumbers : unsigned int {
//STAGE_MAX = 30
//};

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


    // MainMenuData 
    ScenePtr mainMenuScene;
    ObjectPtr startBtn; 
    // MainMenuData 

    // StageSelectData
    ScenePtr stageSelectScene;

    // StageSelectDate  


    // StagesData  
    ScenePtr stagesScene[STAGE_MAX];
    // StagesDate 

public:
    // Constructor 
    FindingSnack() {}
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

    // StageSelectMethod
    void setStageSelectScene(ScenePtr ss) { stageSelectScene = ss; };


    // StageSelectMethod 
    void SetStages(ScenePtr s[STAGE_MAX]) { for (int i = 0; i < STAGE_MAX; i++) stagesScene[i] = s[i]; };




    // err: ���ܰ� �߻��� 
    void start() { startGame(mainMenuScene); };

    // virtual �� �ƴ� overriding�� ������ ���� ����� �� �������� Ȯ�� �ʿ� 
    void enter();
    void exit();
    void update();
    void draw();
    void event();

};
