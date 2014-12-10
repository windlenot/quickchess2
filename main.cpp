#include <iostream>
#include <vector>
#include <cstdlib>
#include "pieces.h"
#include "king.h"
#include "board.h"

using namespace std;

int main(){
	
	board b;
	char inputpiecetype;
	char c;
	char p;
	int curplayer;
	int num1;
	pair<int, int> first;
	pair<int, int> second;
	char movetype;
	char a = 'a';
	bool drawend = false;
	
	
	cout << "Who will move first? w/b: ";
	cin >> c;
	while (c !='w' && c != 'b'){
		cout << "Invalid entry" << endl << endl;
		cout << "Who will move first? w/b: ";
		cin >> c;
	}
	
	if (c == 'w'){
		b.startingmove(0);
		curplayer = 0;
	}
	else{
		b.startingmove(1);
		curplayer = 1;
	}
		

//	first.first = 2;
//	first.second = 4;
//	second.first = 2;
//	second.second = 3;
//	b.move(first,second,a);

//	first.first = 2;
//	first.second = 1;
//	second.first = 2;
//	second.second = 2;
//	b.move(first,second,a);
	
//	first.first = 3;
//	first.second = 5;
//	second.first = 1;
//	second.second = 3;
//	b.move(first,second,a);
	
//	first.first = 1;
//	first.second = 0;
//	second.first = 2;
//	second.second = 1;
//	b.move(first,second,a);
	
//	first.first = 4;
//	first.second = 4;
//	second.first = 4;
//	second.second = 3;
//	b.move(first,second,a);
	
//	first.first = 0;
//	first.second = 0;
//	second.first = 1;
//	second.second = 0;
//	b.move(first,second,a);
	
//	first.first = 3;
//	first.second = 4;
//	second.first = 3;
//	second.second = 3;
//	b.move(first,second,a);
	
//	first.first = 1;
//	first.second = 1;
//	second.first = 1;
//	second.second = 2;
//	b.move(first,second,a);
	
//	first.first = 1;
//	first.second = 3;
//	second.first = 0;
//	second.second = 2;
//	b.move(first,second,a);
	
//	first.first = 3;
//	first.second = 1;
//	second.first = 3;
//	second.second = 2;
//	b.move(first,second,a);
	
//	first.first = 4;
//	first.second = 3;
//	second.first = 3;
//	second.second = 2;
//	b.move(first,second,a);
	
//	first.first = 1;
//	first.second = 2;
//	second.first = 1;
//	second.second = 3;
//	b.move(first,second,a);
	
//	first.first = 3;
//	first.second = 2;
//	second.first = 4;
//	second.second = 1;
//	b.move(first,second,a);
	
//	first.first = 1;
//	first.second = 3;
//	second.first = 0;
//	second.second = 4;
//	b.move(first,second,a);
	
 //	curplayer = 1;


while (true){
	b.display();
	if (b.ischeck()){
		if (curplayer == 0){
			cout << "White is in check." << endl;
			if (b.ischeckmate()){
				cout << "White is in checkmate. Black wins." << endl;
				break;
				//x = 20;
			}
		}
		if (curplayer == 1){
			cout << "Black is in check." << endl;
			if (b.ischeckmate()){
				cout << "Black is in checkmate. White wins." << endl;
				break;
				//x = 20;
			}
		}
	}
	
	if (b.isstalemate()){
		if (curplayer == 0){
			cout << "White is stalemated." << endl;
			break;
			drawend = true;
		}
		else{
			cout << "Black is stalemated." << endl;
			break;
			drawend = true;
		}
	}
	
	if (b.isdraw()){
		cout << "There has been 20 moves without a capture, rescue, or promotion. It's a draw." << endl;
		break;
		drawend = true;
	}
		
	
	if (curplayer == 0)
		cout << "White's turn:" <<endl;
	else
		cout << "Black's Turn:"<<endl;
		
	cout << "First piece type (K/Q/R/N/B/P): ";
	cin >> inputpiecetype;
	cout << "	first X: ";
	cin >> p;
	
	if (p == 'A'|| p == 'a')
		first.first = 0;
	else if (p == 'B'|| p == 'b')
		first.first = 1;
	else if (p == 'C'|| p == 'c')
		first.first = 2;
	else if (p == 'D'|| p == 'd')
		first.first = 3;
	else if (p == 'E'|| p == 'e')
		first.first = 4;
	else
		first.first = -1;
	
	cout << "	first Y: ";
	cin >> 	num1;
	
	if (num1 == 1)
		first.second = 5;
	else if (num1 == 2)
		first.second = 4;
	else if (num1 == 3)
		first.second = 3;
	else if (num1 == 4)
		first.second = 2;
	else if (num1 == 5)
		first.second = 1;
	else if (num1 == 6)
		first.second = 0;
	else
		first.second = -1;
		
		
	cout << "	second X: ";
	cin >> p;

	if (p == 'A'|| p == 'a')
		second.first = 0;
	else if (p == 'B'|| p == 'b')
		second.first = 1;
	else if (p == 'C'|| p == 'c')
		second.first = 2;
	else if (p == 'D'|| p == 'd')
		second.first = 3;
	else if (p == 'E'|| p == 'e')
		second.first = 4;
	else
		second.first = -1;

	cout << "	second Y: ";
	cin >> 	num1;
	
	if (num1 == 1)
		second.second = 5;
	else if (num1 == 2)
		second.second = 4;
	else if (num1 == 3)
		second.second = 3;
	else if (num1 == 4)
		second.second = 2;
	else if (num1 == 5)
		second.second = 1;
	else if (num1 == 6)
		second.second = 0;
	else
		second.second = -1;
		
	cout << "Enter the move type (m/c/r/p): ";
	cin >> movetype;
	
	b.validatemove(inputpiecetype, first, second, movetype);
	
	curplayer = abs(curplayer - 1);

}

	return 0;
}
