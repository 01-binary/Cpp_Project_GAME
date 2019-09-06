![심프](https://user-images.githubusercontent.com/15652602/64159918-efbac100-ce75-11e9-9b28-4efbe1b51284.png)
본 게임의 목적인 적이 쏘는 총을 피해 최대한 오래 살아남는 것이다.<br>
주인공은 맵 1층에서 화살표 오른쪽, 왼쪽, 아래를 입력으로 움직일 수 있으며, 마우스 왼쪽버튼으로 총을 쏠 수 있다. 적들은 임의로 맵 1,2,3층의 왼쪽, 오른쪽에서 등장하며,
특정확률에 따라 주인공에게 총을 쏜다.<br> 총을 머리에 맞으면, 주인공의 Energy는 10씩 감소하게 된다. 기존버전에서 빨간색 적을 추가했는데, 이 적은 Energy를 100가지고 있으며, 검은색 총알을 발사하며, 주인공이 맞으면 Energy가 20이 감소하게 된다.<br>
주인공의 Energy가 0이 되면 게임이 종료된다. 마찬가지로 주인공이 쏜 총을 적이 맞으면, 검은 색 적은 바로 죽으며, 빨간 적은 체력이 0이 되면 죽는다.<br>
<h1>구현 함수 중 중요한 함수 설명<br>
<h3>WalkingPerson.h -> class Main</h3>

게임의 주인공을 만들기 위한 class로 WalkingPerson.h를 상속받았다.
Void draw함수를 오버라이딩하여, 주인공의 색을 적과 구분할 수 있고, 주인공만 Energy
바를 발아래에 출력할 수 있다.<br> 마지막으로 엎드리기를 구현하여, 화살표 아래방향키가 입력될 경우 OTL모양으로 엎드리는 Motion를 취할 수 있게 하였다.
- 추가사항 엎드린 채로 좌우로 방향 전환가능, 강한 적 추가<br>
<h3>DrawFucntion.cpp -> void drawMymap, void drawLine</h3>

drawMymap함수는 위의 그림처럼 맵 1층, 2층, 3층을 표현하기 위해 정의한 함수로,
setLineWidth함수와 drawLine함수를 이용하였다.<br>
drawLine함수는 기존에 있는 drawLine함수에서 주인공의 체력 게이지를 표현하기위해,
오버로딩한 함수이다.<br>
<h3>Main.cpp -> class Random, class Mygame</h3><br>

Class Random은 적이 어느 위치에 나타날 지, 적 출현 좌표를 Random으로 정해주는
vec2 random()함수, 
적의 움직임을 무작위로 움직일 수 있게 해주는 int random_move()함수,
적이 맵 상에 나타날 수 있을 지 결정하는 int enemyshow()함수,
마지막으로, 맵 상에 나타난 적이 공격할지 결정하는 int setrandom(int n) 함수로 구성되어 있다.<br> 확률에 대한 방식은 강의에서 교수님이 설명하신, random lib에 random_device와, uniform_int_distribution를 사용하였다.

Class Mygame은 게임을 진행하기 위한 가장 주된 Class로, Walkingperson, Mybullet, Random, Main등 직접 구현 모든 Class를 가상 상속받고 있다.<br>
Class Mygame에는 소리와, 적, 총알 등 게임에서 필요한 객체, 변수 등을 초기화하는 함수와 총알이 맵의 특정 좌표를 넘어가면, nullptr를 할당함으로써, Memory leak를 막아준다. <br>
또한 drawenemy함수에서는 적의 움직임을 사용자의 조작없이 임의로 움직이게 하기위해 if- else문의 통해, Random class에서 특정 int값을 가져오고, 만족한다면, 적에게 움직임을 부여한다. <br>
총알이 주인공이나 적에게 닿았는 지 확인하기 위한 충돌감지 함수 또한 총알과 주인공, 적의 vector 차를 이용하여, 구현하였다.<br>
마지막으로 update() 함수에서는 Game2D class의 update함수가 오버라이딩된 함수로,
계속해서 호출되는 함수로, 게임을 실행하기위한 가장 주된 함수라고 할 수 있다.<br>
사용자의 입력을 받아, 수행하는 기능, Random class에서 값을 받아 확률적으로 적이 나타날지, 적이 공격할 지 등등의 게임에 필요한 대부분의 함수는 update함수에서 호출된다.<br> 사용자가 마우스 왼쪽키를 눌렀을 때 소리를 출력하며, 총알의 마우스 커서 방향으로 발사하는 기능, 적이 공격을 한다면, 적과 주인공의 벡터 차를 이용하여, 적이 총알을 발사하는 기능 등등이 있다.<br>
- 추가 사항 이미지를 Background에 출력, 물리친 적을 나타내는 Score 추가, 생존 시간을 나타내는 Time of Survival 추가, 주인공이 죽었을 시 다시 시작하는 키, 게임을 종료하는 키를 이미지로 출력하며, 사용자에게 정보 제공가능
