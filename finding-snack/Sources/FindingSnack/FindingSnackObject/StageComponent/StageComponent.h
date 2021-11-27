#pragma once
#include "../FindingSnackObject.h"

// Component
class StageComponent : public FindingSnackObject
{
public:
    FindingSnackObject* root;

    // Stage elements
    // 스테이지 진입시 제일 처음화면 room == stageScene
    ScenePtr room;
    ScenePtr roomSide;
    
    ObjectPtr window[4]; // 좌우 닫힌거, 좌 열린거, 우열린거, 다열린거 // 창문열린것도 추가해야할 수있음 


    StageComponent(FindingSnackObject* r);
    ~StageComponent();

    // 객체가 생성될때 변수 초기화 및 초기 셋팅등 생성자 역할을 하게 된다.
    void enter();

    // 객체가 삭제/제거될때 메모리 삭제 등 소멸자 역할을 하게 된다.
    void exit();

    // 객체의 주 행동들을 작성하는 곳으로 특정 시간마다 변하는 애니메이션이나 타이밍을 체크 하며 다음과 같이 작성 할 수 있다.
    void update();

    // 화면에 그려질 부분을 컨트롤 하는 부분이다. 랜더링을 담당한다.
    void draw();

    // 사용자의 조작에 어떤반응을 할것인지를 컨트롤 할 수 있는 부분이다.
    void event();


    // 만들어 놓은 함수들을 가지고 로직 수행
    void construct();

    
    void makeStage(int stageNum);


    void makeStage1();

};

