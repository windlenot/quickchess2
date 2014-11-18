#include <iostream>
#include <vector>
#include <cstdlib>
#include "pieces.h"
#include "king.h"
#include "board.h"

using namespace std;

int main(){
	
	board b;
	b.display();
	char c;
	int curplayer;
	pair<int, int> first;
	pair<int, int> second;
	bool gameover = true;
	
	
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
		

	

for (int x = 0; x <8; x++){
	
	if (curplayer == 0)
		cout << "White's turn:" <<endl;
	else
		cout << "Black's Turn:"<<endl;
	cout << "	first X: ";
	cin >> get<0>(first);
	cout << "	first Y: ";
	cin >> 	get<1>(first);
	cout << "	second X: ";
	cin >> get<0>(second);
	cout << "	second Y: ";
	cin >> get<1>(second);
	
	b.move(first, second);
	b.display();
	
	cout << endl << endl;
	curplayer = abs(curplayer - 1);

}

	return 0;
}
