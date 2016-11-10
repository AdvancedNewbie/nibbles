#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include </usr/include/ncurses.h>
#include <string>
#include <ctime>
#include "SnakeFunctions.h"
#include <unistd.h>
#include <math.h>
#include <typeinfo>

using namespace std;

int x = 3;
int y = 3;
string direction = "right";
int snakelength = 3;
int snakelengthcount = 0;
int yxarray[100][102] = {
						{3, 3}
						};

int GameRunning = 1;
int LevelNum = 1;

void ClearScreen() {
cout << string( 100, '\n' );
}


void init_curses() {
initscr();
keypad(stdscr, TRUE);
nonl();
cbreak();
noecho();
halfdelay(1);
}

void checkArray() {
		if (chararray[y][x] == 'X') {
		//GameRunning = 0;
		}		
		
}

void newApple() {

	while (chararray[appley][applex] != ' ') {
		int randomnum = 100;
		while (randomnum > 34 || abs(appley - randomnum) < 10){
		randomnum = 3 + (2 * rand ()) %34;
		}
		
		appley = randomnum;
		
		randomnum = 101;
		while (randomnum > 100 || abs(applex - randomnum) < 10){
			randomnum = 3 + (2 * rand ()) %102;
		}
		applex = randomnum;
	}
	PrintLevel(LevelNum, false);
}

void SetupLevel(){
	
	x = 3;
	y = 3;
	//direction = "right";

	holdery[1] = 3;
	holderx[1] = 3;
	
	holdery[2] = 3;
	holderx[2] = 5;
	
	holdery[3] = 3;
	holderx[3] = 7;
	
	snakelength = 3;
		
	//ClearScreen();
	//clearCharArray();
	borderCharArray();
	PrintLevel(LevelNum, true);
	printCharArray(LevelNum, snakelength);
	
	newApple();
	
	GameRunning = 1;
}

int main(int argc, char** argv) {
	int ch;

	ClearScreen();
	
	cout << "Snake C++ v0.1 - Warren Parsons" << endl;
	
	//std::cout << "Have " << argc << " arguments:" << std::endl;
	for (int i = 0; i < argc; ++i) {
        string arg = argv[i];
	    //cout << arg << endl;
	    //cout << "Type: " << typeid(arg).name() << endl;
		if ( arg == "--level" ) {
			//cout << "TRUE!" << endl;
			int tempLevelNum = LevelNum = atoi(argv[i+1]);
			if (isnan(tempLevelNum) == 0) {
				LevelNum = tempLevelNum;
				cout << "Jumping to level: " << LevelNum << " (You cheater...)" << endl;
			} else {
				cout << "Error:  Level number entered was not a number.";
				return 0;
			}
		}
	
		if ( arg == "--help" ) {
			ClearScreen();
			cout << "Snake C++ v0.1 - Warren Parsons" << endl;
			cout << endl;
			cout << "	--help					Display this help message." << endl;
			cout << "	--level <num>				Jump to a level number." << endl;
			cout << string( 5, '\n' );
			return 1;
		}
    }
	cout << string( 30, '\n' );
	sleep(2);

	//borderCharArray();
	//PrintLevel(LevelNum);
	//printCharArray();


	int c;
	int i;

	SetupLevel();

	while (GameRunning == 1){

		init_curses();
		c = getch();
		endwin();


			//Process active keystroke
			if (c == 119 || c == 259){ //w or up-arrow
				direction = "up";
				//y = y - 1;
				//x = x + 1;			
			} else if (c == 97 || c == 260) {//a or left-arrow
				direction = "left";
				//x = x - 1;
			} else if (c == 115 || c == 258) {//s or down-arrow
				direction = "down";
				//y = y + 1;
				//x = x - 1;
			} else if (c == 100 || c == 261) {//d or right-arrow
				direction = "right";
				//x = x + 1;
			}
	
	
			int i = 1;
			while (i < (snakelength + 1)) {		
			holdery[i-1] = holdery[i];
			holderx[i-1] = holderx[i];
			i++;
			}
	
		
			if (direction == "up") {
				y = y - 1;
				x = x + 1;
				holder = chararray[y][x];
				chararray[y][x] = '0';
				checkArray();
				//yxarray[
			} else if (direction == "left") {
				x = x - 2;
				holder = chararray[y][x];
				chararray[y][x] = '0';
				checkArray();
			} else if (direction == "down") {
				y = y + 1;
				x = x - 1;
				holder = chararray[y][x];
				chararray[y][x] = '0';
				checkArray();
			} else if (direction == "right") {
				x = x + 2;
				holder = chararray[y][x];
				chararray[y][x] = '0';
				checkArray();
			}
	
			holdery[snakelength] = y;
			holderx[snakelength] = x;
	
			if (holder == 'X' || holder == '0'){
				GameRunning = 0;
			}
	
			chararray[appley][applex] = '@';
	
			if (holder == '@'){
				chararray[appley][applex] = '0';
				newApple();
				snakelength++;
			}
	
			chararray[holdery[0]][holderx[0]] = ' ';
	

		
		//(void)getch();
		//endwin();
		ClearScreen();
		printCharArray(LevelNum, snakelength);
	
		if (GameRunning == 0 && snakelength < 20) {
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
				cout << "X                                                                                                    X\n";
				cout << "X                       Y   Y    O O   U   U       S S   U   U    C C   K    K  !!                   X\n";
				cout << "X                        Y Y    O   O  U   U      S      U   U  C       K   K   !!                   X\n";
				cout << "X                         Y     O   O  U   U       S S   U   U  C       K K     !!                   X\n";
				cout << "X                         Y     O   O  U   U          S  U   U  C       K   K                        X\n";
				cout << "X                         Y      O O    U U        S S    U U     C C   K    K  !!                   X\n";
				cout << "X                                                                                                    X\n";
				cout << "X                                       (Snake Length < 10)                                          X\n";
				cout << "X                                      Your Snake Length: " << snakelength << "                                          X\n";
				cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		} else if (GameRunning == 0 && snakelength > 19) { 
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
				cout << "X                                                                                                     X\n";
				cout << "X                       Y   Y    O O   U   U      L       O O     S S   EEEEE                         X\n";
				cout << "X                        Y Y    O   O  U   U      L      O   O   S      E                             X\n";
				cout << "X                         Y     O   O  U   U      L      O   O    S S   EEEEE                         X\n";
				cout << "X                         Y     O   O  U   U      L      O   O       S  E                             X\n";
				cout << "X                         Y      O O    U U       LLLL    O O     S S   EEEEE                         X\n";
				cout << "X                                                                                                     X\n";
				cout << "X                                       (Snake Length < 10)                                           X\n";
				cout << "X                                     Your Snake Length: " << snakelength << "                                          X\n";
				cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			} else if (GameRunning == 1 && snakelength > 19) {
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
				cout << "X                                                                                                    X\n";
				cout << "X                     Y   Y    O O   U   U      W         W  IIIIIII  N     N                        X\n";
				cout << "X                      Y Y    O   O  U   U      W    W    W     I     N N   N                        X\n";
				cout << "X                       Y     O   O  U   U       W   W   W      I     N  N  N                        X\n";
				cout << "X                       Y     O   O  U   U       W  W W  W      I     N   N N                        X\n";
				cout << "X                       Y      O O    U U          W   W     IIIIIII  N     N                        X\n";
				cout << "X                                                                                                    X\n";
				cout << "X                                      (Snake Length = 10)                                           X\n";
	//			cout << "X                                     Your Snake Length: " << snakelength << "                                          X\n";
				cout << "X                                                                                                    X\n";
				cout << "X                                Press the Space Bar to Continue                                     X\n";
				cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				LevelNum++;
				while (c != 32){
					init_curses();
					c = getch();
					endwin();
				}
		
				GameRunning = 0;
					
				SetupLevel();
		}	
	
		if (GameRunning == 1){
			if (snakelength < 10) {
				cout << "Snake Length: " << snakelength;
				cout << "                                                                              ";
				cout << "Level: " << LevelNum;
			}
			if (snakelength > 10) {
				cout << "Snake Length: " << snakelength;
				cout << "                                                                             ";
				cout << "Level: " << LevelNum;
			}
		}
		//cout << "\n\n" << holder << "\n\n\n" << c << "\n\n\n" << holdery[1] << " - " <<holderx[1];
		//sleep(1000);}

	//return 0;
		}
}
