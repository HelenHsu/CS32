/////////////these are different test case for CS32 proj1
///files include Robot.cpp Arena.cpp Player.cpp History.cpp Game.cpp
///utilities.cpp 

/*
#include <iostream>
using namespace std;

int  main()
{
 cout << "char A is "<< int('A')<<endl;
 cout << "char 1 is "<< int ('1')<<endl;
 cout << "the shift is " <<int ('A'-'1')<<endl;
 cout << "turn 2 into " << char('2' +int('A'-'1'))<<endl;
}

/////////////test history
#include "History.h"
int main()
{
	History h(2,2);
	h.record(1,1);
	h.display();
}



///////////test robot
#include "Robot.h"
int main()
{
	Robot r(nullptr,1,1);
}



//////////test Player
#include "Player.h"
int main()
{
	Player p(nullptr,1,1);
}

////////test Arena
#include "Arena.h"
int main()
{
	Arena a(10,18);
	a.addPlayer(2,2);
}


#include "Arena.h"
#include "Player.h"
int main()
{
	Arena a(10,20);
	Player p(&a,2,3);
}

#include "globals.h"
#include "Player.h"
#include "Arena.h"
int main()
{
	Arena a(10,20);
	Player p(&a,2,3);
}

/////////test Arena.history()
#include "Arena.h"
#include "History.h"
#include "Player.h"
#include "globals.h"
int main()
{
	Arena a(4,4);
	a.addPlayer(2,4);
	a.addRobot(3,2);
	a.addRobot(2,3);
	a.addRobot(1,4);
	a.player() -> moveOrAttack(LEFT);
	a.player() -> moveOrAttack(UP);
	a.player() -> moveOrAttack(LEFT);
	a.player() -> moveOrAttack(LEFT);
	a.player() -> moveOrAttack(DOWN);
	a.player() -> moveOrAttack(DOWN);
	a.player() -> moveOrAttack(LEFT);
	a.player() -> moveOrAttack(UP);
	a.player() -> moveOrAttack(UP);
	a.player() -> moveOrAttack(UP);
//	a.display();
	a.history().display();
}


/////////this shouldnt complie
#include "Player.h"
#include "Arena.h"
int main()
{
	Arena a(10,20);
	Player p(&a,2,3);
	Robot r(&a,1,1);
}



//////// shouldnt complie either
#include "globals.h"
#include "Robot.h"
#include "Player.h"
int main()
{
	Arena a(10,10);
}

*/
/////////wrong either
#include"History.h"
int main()
{
	History h;
}

