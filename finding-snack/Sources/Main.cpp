#include "FindingSnack/FindingSnack.h"

// FindingSnack을 개발하기 위해서 필요한 Components 들 (부품 느낌)
#include "FindingSnack/MainMenuComponent/MainMenuComponent.h"


int main()
{

    FindingSnack findingSnackGame;

    // FindingSnackGame을 개발하기 위해 필요한 씬들을 각각 Components 안에서 생성하여 findingSnackGame 최종적으로 개발.
    // 저장은 안해도 될 듯함. 안되면 1. main함수에서 처리 -> 2. 저장할 곳 생각하기. (상호참조 되지 않게 고려 필요)

    MainMenuComponent mainMenuSceneBuilder(&findingSnackGame);

    findingSnackGame.start();
    
    return 0; 
}
