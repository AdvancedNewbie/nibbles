#include <iostream>
#include </usr/include/stdio.h>
#include </usr/include/ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <sstream>

using namespace std;
extern char chararray[31][102];
extern string direction;

void LevelOne(bool newLevel);
void LevelTwo(bool newLevel);
void LevelThree(bool newLevel);
void LevelFour(bool newLevel);
void LevelFive(bool newLevel);

//char chararray[][100]={
//			  	   	 {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
//			  	   	 {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
//			  	   	 {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}
//			  	     };

//char chararray[31][101];

void drawTitleSrn() {
		//Draw Top Border
	cout.width(102);
	cout.fill('X');
	cout << "\n";
	
	//Draw Left and Right Borders
	for (int i=0;i<30;i++) {
	cout << "X";
			for (int i=0;i<100;i++) {
			cout << " ";
			}
	cout << "X\n";
	}
	
	//Draw Bottom Border
	for (int i=0;i<102;i++) {
	cout << "X";
	}
	cout << "\n";
}

void printCharArray(int LevelNum, int snakelength) {
	string Title = "Snake C++ v0.1";
	cout << string((102/2) - (Title.length()/2), ' ') << Title << endl;
	for(int y = 1; y <= 30; y++) {
		
		if (y > 1) {
			cout << "\n";
//			printw("\n");
		}
		
		for (int x = 1; x <= 102; x++) {
			cout << chararray[y][x];
		}
		
	}
	cout << "\n";
	std::ostringstream RightAligned; 
	RightAligned << "Level: " << LevelNum << "    Snake Length: " << snakelength << "    Goal: 20";
	int lengthRightAligned = RightAligned.tellp();
	cout << "Warren Parsons" << string(88 - RightAligned.tellp(), ' ') << RightAligned.str() << endl;
//	printw("\n");
}

void clearCharArray() {
	
	for(int y = 1; y <= 30; y++) {
		
		for (int x = 1; x <= 102; x++) {
				chararray[y][x] = ' ';
		}
		
	}
	
}

void borderCharArray() {
	
	for(int y = 1; y <= 30; y++) {
		
		for (int x = 1; x <= 102; x++) {
			
			if (x == 1){
				chararray[y][1] = 'X';
			}
			if (y == 1){
				chararray[1][x] = 'X';
			}
			if (x == 102){
				chararray[y][102] = 'X';
				//cout << "!";
			}
			if (y == 30) {
				chararray[30][x] = 'X';
			}
			if (y != 1 && x != 1 && y != 30 && x != 102) {
				chararray[y][x] = ' ';
				//cout << "(Y: " << y << ", X: " << x << ") ";
			}
		}
		
	}
	
}

void PrintLevel(int LevelNum, bool newLevel = false){
	if (LevelNum > 5) {
		//cout << string( 100, '\n' );
		cout << "You have won the game!" << endl;
		cout << "(Well, there were no more levels made.  Maybe you should make some more?)" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "	   _________         _________" << endl;
		cout << "	  /         \\       /         \\    		Warren" << endl;
 		cout << "	 /  /~~~~~\\  \\     /  /~~~~~\\  \\   		  Parsons" << endl;
 		cout << "	 |  |     |  |     |  |     |  |   			Originally made in 2012" << endl;
 		cout << "	 |  |     |  |     |  |     |  |   			Last Updated:09/09/2014" << endl;
 		cout << "	 |  |     |  |     |  |     |  |         /" << endl;
 		cout << "	 |  |     |  |     |  |     |  |       //" << endl;
		cout << "	(o  o)    \\  \\_____/  /     \\  \\_____/ /" << endl;
 		cout << "	 \\__/      \\         /       \\        /" << endl;
  		cout << "	   |         ~~~~~~~~~         ~~~~~~~~" << endl;
  		cout << "	   ^   Thanks for playing!" << endl;
		cout << string( 14, '\n' );
		std::exit(1);
	}
	switch(LevelNum){
		
		case 1:
		LevelOne(newLevel);
		break;
		
		case 2:
		LevelTwo(newLevel);
		break;
		
		case 3:
		LevelThree(newLevel);
		break;
		
		case 4:
		LevelFour(newLevel);
		break;
		
		case 5:
		LevelFive(newLevel);
		break;
	}
	
}

void LevelOne(bool newLevel){
	if (newLevel == true){
		direction = "right";
	}
		for(int y = 1; y <= 30; y++) {
		
			for (int x = 1; x <= 102; x++) {
			
				if (x == 32 && y >= 8 && y <= 22){
				chararray[y][32] = 'X';
				}
				if (x == 68 && y >= 8 && y <= 22){
				chararray[y][68] = 'X';
				}
		}
		
	}
}

void LevelTwo(bool newLevel){
	if (newLevel == true){
		direction = "right";
	}
		for(int y = 1; y <= 30; y++) {
		
			for (int x = 1; x <= 102; x++) {
			
				if (x == 32 && y >= 8 && y <= 22){
				chararray[y][32] = 'X';
				}
				if (x == 68 && y >= 8 && y <= 22){
				chararray[y][68] = 'X';
				}
				if (x >= 16 && x <= 84 && y == 15){
				chararray[y][x] = 'X';	
				}
				chararray[15][50] = ' ';
				
		}
		
	}
}

void LevelThree(bool newLevel){
	if (newLevel == true){
		direction = "down";
	}
		for(int y = 1; y <= 30; y++) {
		
			for (int x = 1; x <= 102; x++) {
			

				if (x == 32 && y >= 0 && y <= 12){
				chararray[y][x] = 'X';
				}
				
				if (x == 68 && y >= 0 && y <= 12){
				chararray[y][x] = 'X';
				}
				

				if (x == 32 && y >= 18 && y <= 30){
				chararray[y][x] = 'X';
				}

				if (x == 68 && y >= 18 && y <= 30){
				chararray[y][x] = 'X';	
				}
				
		}
		
	}
}

void LevelFour(bool newLevel){
	if (newLevel == true){
		direction = "down";
	}
		for(int y = 1; y <= 30; y++) {
		
			for (int x = 1; x <= 102; x++) {
			
				if (x == 22 && y >= 0 && y <= 12){
				chararray[y][x] = 'X';
				}
				if (x == 42 && y >= 0 && y <= 12){
				chararray[y][x] = 'X';
				}
				if (x == 62 && y >= 0 && y <= 12){
				chararray[y][x] = 'X';	
				}
				if (x == 82 && y >= 0 && y <= 12){
				chararray[y][x] = 'X';	
				}
				
				if (x == 22 && y >= 18 && y <= 30){
				chararray[y][x] = 'X';
				}
				if (x == 42 && y >= 18 && y <= 30){
				chararray[y][x] = 'X';
				}
				if (x == 62 && y >= 18 && y <= 30){
				chararray[y][x] = 'X';	
				}
				if (x == 82 && y >= 18 && y <= 30){
				chararray[y][x] = 'X';	
				}
				
		}
		
	}
}

void LevelFive(bool newLevel){
	if (newLevel == true){
		direction = "down";
	}
		for(int y = 1; y <= 30; y++) {
		
			for (int x = 1; x <= 102; x++) {
			
				if (x == 12 && y >= 0 && y <= 20){
				chararray[y][x] = 'X';
				}
				if (x == 32 && y >= 0 && y <= 20){
				chararray[y][x] = 'X';
				}
				if (x == 52 && y >= 0 && y <= 20){
				chararray[y][x] = 'X';
				}
				if (x == 72 && y >= 0 && y <= 20){
				chararray[y][x] = 'X';
				}
				if (x == 92 && y >= 0 && y <= 20){
				chararray[y][x] = 'X';
				}

				
				if (x == 22 && y >= 10 && y <= 30){
				chararray[y][x] = 'X';
				}
				if (x == 42 && y >= 10 && y <= 30){
				chararray[y][x] = 'X';
				}
				if (x == 62 && y >= 10 && y <= 30){
				chararray[y][x] = 'X';
				}
				if (x == 82 && y >= 10 && y <= 30){
				chararray[y][x] = 'X';
				}
				
				if (x >= 2 &&  x <= 100 && y == 14){
				chararray[y][x] = ' ';
				}
				if (x >= 2 &&  x <= 100 && y == 15){
				chararray[y][x] = ' ';
				}
				if (x >= 2 &&  x <= 100 && y == 16){
				chararray[y][x] = ' ';
				}
								
		}
		
	}
}