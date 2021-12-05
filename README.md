# Finding Snack
<br/>
<strong>
by 12조, 손영진(20200768), 박현민(20202905)

</strong>
<hr/>
<br/>

## 게임 설명 동영상 

https://youtu.be/f25FUGJf2PQ

<hr/>
<br/>


## 게임 설명 

![gif2](https://user-images.githubusercontent.com/68492498/144746517-2c0475ad-0c15-4da6-ac17-03661da4dcac.gif)


<h3> 푸앙이는 햄버거를 너무 좋아합니다.<br/><br/>다이어트 중에도 자꾸만 햄버거를 먹어요.<br/><br/>결국 트레이너는 푸앙이의 다이어트를 위해 햄버거를 숨기기로 결심합니다.<br/><br/>푸앙이가 트레이너 몰래 햄버거를 찾아서 먹을 수 있게 도와주세요!<br/><br/></h3>

<hr/>
<br/>


## 게임 방법

<h3> 곳곳에 숨어있는 무서운 트레이너에게 걸리지 않고 햄버거를 찾으면 됩니다. </h3>

<h3> 트레이너에게 들킨 장면</h3>

![gif1](https://user-images.githubusercontent.com/68492498/144746187-5af3896f-8503-4b6b-96ba-17ec5f33185d.gif)

<h3> 트레이너에게 걸리지 않고 햄버거를 찾은 장면 </h3>

![gif3](https://user-images.githubusercontent.com/68492498/144746815-309603f5-fe06-40ee-8717-d66f670e9fe7.gif)

<hr/>
<br/>

## 게임 공략법 

[stage1 공략](https://github.com/HMP4287/finding-snack/blob/master/Stage1.txt),
[stage2 공략](https://github.com/HMP4287/finding-snack/blob/master/Stage2.txt),
[stage3 공략](https://github.com/HMP4287/finding-snack/blob/master/Stage3.txt),
[stage4 공략](https://github.com/HMP4287/finding-snack/blob/master/Stage4.txt),
[stage5 공략](https://github.com/HMP4287/finding-snack/blob/master/Stage5.txt),
[stage6 공략](https://github.com/HMP4287/finding-snack/blob/master/Stage6.txt),
[stage7 공략](https://github.com/HMP4287/finding-snack/blob/master/Stage7.txt),
[stage8 공략](https://github.com/HMP4287/finding-snack/blob/master/Stage8.txt),
[stage9 공략](https://github.com/HMP4287/finding-snack/blob/master/Stage9.txt),
[stage10 공략](https://github.com/HMP4287/finding-snack/blob/master/Stage10.txt).


<hr/>
<br/>


## 프로젝트 구조 

    
<h3>FindingSnack 추상 클래스</h3> <br/>

- virtual 함수인 enter(), update(), exit(), event(), draw()를 선언함.<br/>

- 프로그램의 부품 역할을 하는 Component들을 저장할 변수 선언함. <br/>예시 코드) FindingSnack * mainMenuComponent;  즉, mainMenuComponent 는 메인메뉴 화면을 구성하며 메인메뉴와 관련된 로직등을 수행함. <br/>

<br/>

<h3>FindingSnackObject 클래스</h3><br/>

- FindingSnack 클래스를 상속함.

- 주요한 Scene과 Object는 protected이며 FindingSnackObject의 필드로 선언되어 있음. 하위 클래스에서 getter, setter를 통해 주요 필드에 접근함. 

<br/>

<h3>Component 클래스 </h3><br/>

- FindingSnackObject를 상속함.

- 중요 장면(메인메뉴, 스테이지 선택화면, 스테이지1,2,3.. 등)을 앞서 상속 받은 virtual 함수들을 활용하여 Component클래스에서 구현함.

- Component는 필드에 공통된 FindingSnackObject 객체 주소를 가짐.  

<hr/>
<br/>



