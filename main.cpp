#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <queue>
#include "pieces.h"
#include "king.h"
#include "board.h"

using namespace std;


int main(){

	board b;
	string inputpiecetype;
	string c;
	string p;
	int curplayer;
	string num1;
	pair<int, int> first;
	pair<int, int> second;
	string movetype;
	char a = 'a';
	bool drawend = false;
	bool gameOver = false;
	bool stalemate = false;
	
    //Start Queue Setup
	//Creates a Priority queue in order to customize the compare function it uses
	typedef priority_queue<board, std::vector<board>, less <board> > priQ;
	priQ PriQTy;
    //End Queue Setup
	double curHeuristic;
	vector<board> expansion;
	vector<board> expansion2;
	
	cout << "Who will move first? w/b: ";
	cin >> c;
	while (c !="w" && c != "b"){
		cout << "Invalid entry" << endl << endl;
		cout << "Who will move first? w/b: ";
		cin >> c;
	}
	
	if (c == "w"){
		b.startingmove(0);
		curplayer = 0;
	}
	else{
		b.startingmove(1);
		curplayer = 1;
	}
		

//	first.first = 0;
//	first.second = 1;
//	second.first = 3;
//	second.second = 3;
//	b1.move(first,second,a);
	
//	board b(b1);

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
	
// 	curplayer = 1;


while (!gameOver){
	b.display();
	if (b.ischeck()){
		if (curplayer == 0){
			cout << "White is in check." << endl;
			if (b.ischeckmate()){
				cout << "White is in checkmate. Black wins." << endl;
				gameOver = true;
				//x = 20;
			}
		}
		if (curplayer == 1){
			cout << "Black is in check." << endl;
			if (b.ischeckmate()){
				cout << "Black is in checkmate. White wins." << endl;
				gameOver = true;
				//x = 20;
			}
		}
	}
	
	if (b.isstalemate()){
		if (curplayer == 0){
			cout << "White is stalemated." << endl;
			gameOver = true;
			drawend = true;
		}
		else{
			cout << "Black is stalemated." << endl;
			gameOver = true;
			drawend = true;
		}
	}
	
	if (b.isdraw()){
		cout << "There has been 20 moves without a capture, rescue, or promotion. It's a draw." << endl;
		gameOver = true;
		drawend = true;
	}
		
	if (!gameOver && curplayer == 0){
		if (curplayer == 0)
			cout << "White's turn:" <<endl;
		else
			cout << "Black's Turn:"<<endl;
			
		cout << "First piece type (K/Q/R/N/B/P): ";
		cin >> inputpiecetype;
		cout << "	first X: ";
		cin >> p;
		
		if (p == "A"|| p == "a")
			first.first = 0;
		else if (p == "B"|| p == "b")
			first.first = 1;
		else if (p == "C"|| p == "c")
			first.first = 2;
		else if (p == "D"|| p == "d")
			first.first = 3;
		else if (p == "E"|| p == "e")
			first.first = 4;
		else
			first.first = -1;
		
		cout << "	first Y: ";
		cin >> 	num1;
		
		if (num1 == "1")
			first.second = 5;
		else if (num1 == "2")
			first.second = 4;
		else if (num1 == "3")
			first.second = 3;
		else if (num1 == "4")
			first.second = 2;
		else if (num1 == "5")
			first.second = 1;
		else if (num1 == "6")
			first.second = 0;
		else
			first.second = -1;
			
			
		cout << "	second X: ";
		cin >> p;

		if (p == "A"|| p == "a")
			second.first = 0;
		else if (p == "B"|| p == "b")
			second.first = 1;
		else if (p == "C"|| p == "c")
			second.first = 2;
		else if (p == "D"|| p == "d")
			second.first = 3;
		else if (p == "E"|| p == "e")
			second.first = 4;
		else
			second.first = -1;

		cout << "	second Y: ";
		cin >> 	num1;
		
		if (num1 == "1")
			second.second = 5;
		else if (num1 == "2")
			second.second = 4;
		else if (num1 == "3")
			second.second = 3;
		else if (num1 == "4")
			second.second = 2;
		else if (num1 == "5")
			second.second = 1;
		else if (num1 == "6")
			second.second = 0;
		else
			second.second = -1;
			
		cout << "Enter the move type (m/c/r/p): ";
		cin >> movetype;
		
		b.validatemove(inputpiecetype, first, second, movetype);
		
		}
		else if(!gameOver && curplayer == 1)				//AI STARTS
		{
			cout << "in ai move" << endl;
			expansion = b.expand(false,false);
			cout << "back in ai move" << endl;
			for(int i = 0; i < expansion.size() - 1; i++)
			{
				cout << "			BEGIN FOR LOOP ITERATION "<< i << endl;
				expansion2 = expansion[i].expand(false,false);
				cout << "back again" << endl;
				for(int j = 0; j < expansion.size(); j++)
				{
					cout << "before push" << endl;
					PriQTy.push(expansion2[j]);
					cout << "after push" << endl;
				}
				cout << "after priqty pushes" << endl;
				curHeuristic = 0;
				board temp;
				temp = PriQTy.top();
				curHeuristic = (-1.0 * temp.getHeuristic());
				cout << "before expansion2 assign" << endl;
				temp = PriQTy.top();
				expansion2 = temp.expand(false,false);
				cout << "after that" << endl;
					
				while(!PriQTy.empty()){
					cout << "prepop" << endl;
					PriQTy.pop();
					cout << "popped" << endl;
				}
				
				cout << "before prqty 2" << endl;
				for(int k = 0; k < expansion2.size(); k++)
				{
					cout << "Inside for expansion2";
					PriQTy.push(expansion2[k]);
				}
				cout << "after for 2" << endl;
				curHeuristic += PriQTy.top().getHeuristic();
				curHeuristic += expansion[i].getHeuristic();
				expansion[i].updateHeuristicValueDouble(curHeuristic);
				while(!PriQTy.empty()){
					PriQTy.pop();
				}
			}
			cout <<endl << endl << endl<< "		before for 5" << endl << endl << endl;
			for(int l = 0; l < expansion.size(); l++)
			{
				PriQTy.push(expansion[l]);
			}
			cout << "			after for 5" << endl;
			board bPrime(PriQTy.top());
			b = bPrime;
			cout <<"final board h' is " << b.getHeuristic() << endl;
			b.startingmove(0);
		}
		
		curplayer = abs(curplayer - 1);
	}

	if (drawend){
		int whitepoints = 0;
		int blackpoints = 0;
		pair<int, int> p;
		pieces curpiece;
		if (stalemate){
			if (curplayer == 0)
				blackpoints = 14;
			else
				whitepoints = 14;
		}
		
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 6; j++){
				p.first = i;
				p.second = j;
				curpiece = b.getpiece(p);
				if (curpiece.getpiecetypeint() != 0){
					if (curpiece.getplayer() == 0){
						if (curpiece.getpiecetypeint() == 1)
							whitepoints = whitepoints + 1;
						else if(curpiece.getpiecetypeint() == 2)
							whitepoints = whitepoints + 5;
						else if(curpiece.getpiecetypeint() == 3 || curpiece.getpiecetypeint() == 4)
							whitepoints = whitepoints + 3;
						else if(curpiece.getpiecetypeint() == 5)
							whitepoints = whitepoints + 9;
					}
					else{
						if (curpiece.getpiecetypeint() == 1)
							blackpoints = blackpoints + 1;
						else if(curpiece.getpiecetypeint() == 2)
							blackpoints = blackpoints + 5;
						else if(curpiece.getpiecetypeint() == 3 || curpiece.getpiecetypeint() == 4)
							blackpoints = blackpoints + 3;
						else if(curpiece.getpiecetypeint() == 5)
							blackpoints = blackpoints + 9;
					}
				}
			}
		}
		
	if (whitepoints > blackpoints)
		cout << "White wins with " << whitepoints << " points. Black has " << blackpoints << " points." << endl;
	else if (whitepoints < blackpoints)
		cout << "Black wins with " << blackpoints << " points. White has " << whitepoints << " points." << endl;
	else
		cout << "Each team has the same points in pieces on the board. It's a draw." << endl;

	}

	return 0;
}
