#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define STAGE_MAX 10

#include <bangtal>
class FindingSnack {
public:

    FindingSnack* mainMenuComponent;
    FindingSnack* stageSelectComponent;
    FindingSnack* stageComponent;
    FindingSnack* introComponent;



	FindingSnack() {};
	~FindingSnack() {};



    // virtual 이 아닌 overriding한 것으로 오류 생기는 지 지속적인 확인 필요 
    virtual void enter() = 0;
    virtual void exit() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void event() = 0;


    //
    //virtual void makeStage(int stageNum) = 0;


};
