#include <iostream>
#include "FindingSnack/FindingSnack.h"


int main()
{

    // 파일의 생성을 순서대로 생각해봤을 때 상속을 포기하거나, (MainMenu가 생성 할 때 FindingSnack은 컴퓨터에 아무런 정보가 없는 상태) 
    // 다른파일로 분리하는 것을 포기하던가. 
    // 따라서 -> 상속을 포기하고, 기존 목적인 객체지향적 설계에서 가독성을 위한 설계로 변경 
    // MainMenu 클래스와 findingSnack클래스에서 서로에게 접근할 수 있어야 하기 때문에 아래와 같이 설계. 
    // 더 나은 방안이 있을 수 있음 





    // 아래 방식의 설계 불가능
    //FindingSnack findingSnackGame;
    
    //MainMenu ma(&findingSnackGame);
    //SelectStage se(&findingSnackGame);
    //Stage st(&findingSnackGame);
    //MainMenu ma;
    //SelectStage se;
    //Stage st;

    //다른클래스들도 생성 후 마지막에 setData(a, b, c, d해서 findingSnakeGame에 넣어주기)
    //findingSnackGame.setObjects(&ma, &se, &st);

    // 클래스 필드에 값 주입하는 과정 생성자로도 가능, Setter로 넣어야 될듯 함  
    //findingSnackGame.setMainMenu(MainMenu main);
    //findingSnackGame.setMainMenu(MainMenu main);
    //findingSnackGame.setMainMenu(MainMenu main);
    //findingSnackGame.start();

    return 0; 
}
