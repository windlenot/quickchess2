//Board class for quickchess
//Team A

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include "pieces.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"
#include "empty.h"

using namespace std;

class board{
public:
	board();
	~board();
	
	//vector<ordered_pair> checkallvalidpositions(piece p);
	void validatemove(char inputpiece, pair <int,int> p1, pair <int,int> p2, char movetype);
	void move(pair <int,int> p1, pair <int,int> & p2, char & movetype);
	pieces getpiece(pair<int, int> d);
	void display();
	bool isempty(pair<int, int> d);
	void startingmove(int n);
	int getplayer();
	bool isvalid(pair <int,int> p1, pair <int,int> p2, char movetype);
	
	pair<int,int> canbecapturedby(pair<int, int> p);
	pair<int,int> checkmaker();
	
	vector<pair <int, int> > generatemoves(pair <int,int> p1, char movetype);
	bool isinvector(vector<pair <int, int> > v,pair <int,int> p1);
	
	void testmove(pair<int, int> p1, pair<int, int> p2);
	
	bool isstalemate();
	bool isdraw();
	bool iscapturedpiece(char capturedp);
	
	void rescuepiece(pair<int, int> p1, char c);
	void promotepiece(pair<int, int> p1);
	
	//for solve class
	bool ischeckmate();
	bool ispromotion(pair<int, int> p1);
	bool ischeck();
	bool isrescue();
	//...
	
private:
	vector<pieces> enemiescaptured;	//List of enemies captured
	vector<pieces> pieceslost;		//List of pieces lost
	
	vector< vector < pieces> > TheBoard;	//2d vector of pieces
	
	int playerturn;
	int moveswithoutcapture;
	
	knight * bn = new knight;
	pieces bnp;
	knight * wn = new knight;
	pieces wnp;
	bishop * bb = new bishop;
	pieces bbp;
	bishop * wb = new bishop;
	pieces wbp;
	rook * br = new rook;
	pieces brp;
	rook * wr = new rook;
	pieces wrp;
	king * bk = new king;
	pieces bkp;
	king * wk = new king;
	pieces wkp;
	queen * bq = new queen;
	pieces bqp;
	queen * wq = new queen;
	pieces wqp;
	pawn * bp1 = new pawn;
	pieces bp1p;
	pawn * bp2 = new pawn;
	pieces bp2p;
	pawn * bp3 = new pawn;
	pieces bp3p;
	pawn * bp4 = new pawn;
	pieces bp4p;
	pawn * bp5 = new pawn;
	pieces bp5p;
	pawn * wp1 = new pawn;
	pieces wp1p;
	pawn * wp2 = new pawn;
	pieces wp2p;
	pawn * wp3 = new pawn;
	pieces wp3p;
	pawn * wp4 = new pawn;
	pieces wp4p;
	pawn * wp5 = new pawn;
	pieces wp5p;
	empty * emp = new empty;
	pieces empp;
	
	bool iswhitecheckmate();
	
	bool iswhiteincheck(); 
	
	//...
};

board::board(){
	enemiescaptured.resize(0);
	pieceslost.resize(0);
	
	moveswithoutcapture = 0;
	
	TheBoard.resize(5);
	for(int i = 0; i < 5; i++)
		TheBoard[i].resize(6);
	
	//All white pieces...
	wn->setplayer(0);		//Set to first player
	wn->setx(4);				//Set x position
	wn->sety(5);				//Set y position
	wnp.set(wn);
	TheBoard[4][5] = wnp;	//place in the board
	wk->setplayer(0);
	wk->setx(2);
	wk->sety(5);
	wkp.set(wk);
	TheBoard[2][5] = wkp;
	wq->setplayer(0);
	wq->setx(3);
	wq->sety(5);
	wqp.set(wq);
	TheBoard[3][5] = wqp;
	wb->setplayer(0);
	wb->setx(1);
	wb->sety(5);
	wbp.set(wb);
	TheBoard[1][5] = wbp;
	wr->setplayer(0);
	wr->setx(0);
	wr->sety(5);
	wrp.set(wr);
	TheBoard[0][5] = wrp;
	wp1->setplayer(0);
	wp1->setx(0);
	wp1->sety(4);
	wp1p.set(wp1);
	TheBoard[0][4] = wp1p;
	wp2->setplayer(0);
	wp2->setx(1);
	wp2->sety(4);
	wp2p.set(wp2);
	TheBoard[1][4] = wp2p;
	wp3->setplayer(0);
	wp3->setx(2);
	wp3->sety(4);
	wp3p.set(wp3);
	TheBoard[2][4] = wp3p;
	wp4->setplayer(0);
	wp4->setx(3);
	wp4->sety(4);
	wp4p.set(wp4);
	TheBoard[3][4] = wp4p;
	wp5->setplayer(0);
	wp5->setx(4);
	wp5->sety(4);
	wp5p.set(wp5);
	TheBoard[4][4] = wp5p;
	
	bn->setplayer(1);
	bn->setx(4);
	bn->sety(0);
	bnp.set(bn);
	TheBoard[4][0] = bnp;
	bk->setplayer(1);
	bk->setx(2);
	bk->sety(0);
	bkp.set(bk);
	TheBoard[2][0] = bkp;
	bq->setplayer(1);
	bq->setx(3);
	bq->sety(0);
	bqp.set(bq);
	TheBoard[3][0] = bqp;
	bb->setplayer(1);
	bb->setx(1);
	bb->sety(0);
	bbp.set(bb);
	TheBoard[1][0] = bbp;
	br->setplayer(1);
	br->setx(0);
	br->sety(0);
	brp.set(br);
	TheBoard[0][0] = brp;
	bp1->setplayer(1);
	bp1->setx(0);
	bp1->sety(1);
	bp1p.set(bp1);
	TheBoard[0][1] = bp1p;
	bp2->setplayer(1);
	bp2->setx(1);
	bp2->sety(1);
	bp2p.set(bp2);
	TheBoard[1][1] = bp2p;
	bp3->setplayer(1);
	bp3->setx(2);
	bp3->sety(1);
	bp3p.set(bp3);
	TheBoard[2][1] = bp3p;
	bp4->setplayer(1);
	bp4->setx(3);
	bp4->sety(1);
	bp4p.set(bp4);
	TheBoard[3][1] = bp4p;
	bp5->setplayer(1);
	bp5->setx(4);
	bp5->sety(1);
	bp5p.set(bp5);
	TheBoard[4][1] = bp5p;
	
	emp->setplayer(2);
	empp.set(emp);

	for (int i = 0; i < 5; i++)
		for (int j = 2; j < 4; j++)
			TheBoard[i][j] = empp;
			
	enemiescaptured.resize(0);
	pieceslost.resize(0);	
}

//destructor
board::~board(){
	delete br;
	delete bb;
	delete bk;
	delete bq;
	delete bn;
	delete bp1;
	delete bp2;
	delete bp3;
	delete bp4;
	delete bp5;
	
	delete wr;
	delete wb;
	delete wk;
	delete wq;
	delete wn;
	delete wp1;
	delete wp2;
	delete wp3;
	delete wp4;
	delete wp5;	
	
	delete emp;
}

void board::startingmove(int n){
	playerturn = n;
}

int board::getplayer(){
	return playerturn;
}

//valid move function used to be called from the main program, takes an input piece
void board::validatemove(char inputpiece, pair <int,int> p1, pair <int,int> p2, char movetype){
	char p;
	int num1;
	pieces temppiece;
	char a = 'a';
	bool checkbool;
	
	bool validpieceselect = true;		//used if the initial piece choice was valid
	bool validsecondarypiece = true;	//used if the second piece choice was
	char capturedp;
	
	if (inputpiece == 'p' || inputpiece == 'P')			//determine if the first piece is valid
		validpieceselect = (TheBoard[p1.first][p1.second].getpiecetypeint() == 1);
	else if (inputpiece == 'r' || inputpiece == 'R')
		validpieceselect = (TheBoard[p1.first][p1.second].getpiecetypeint() == 2);
	else if (inputpiece == 'n' || inputpiece == 'N')
		validpieceselect = (TheBoard[p1.first][p1.second].getpiecetypeint() == 3);
	else if (inputpiece == 'b' || inputpiece == 'B')
		validpieceselect = (TheBoard[p1.first][p1.second].getpiecetypeint() == 4);
	else if (inputpiece == 'q' || inputpiece == 'Q')
		validpieceselect = (TheBoard[p1.first][p1.second].getpiecetypeint() == 5);
	else if (inputpiece == 'k' || inputpiece == 'K')
		validpieceselect = (TheBoard[p1.first][p1.second].getpiecetypeint() == 6);
	else
		validpieceselect = false;
		
	if (movetype == 'c' || movetype == 'C' || movetype == 'r' || movetype == 'R'){		//if a second piece is necessary,
		cout << "Enter secondary piece type (K/Q/R/N/B/P): ";								//makes sure it's a valid choice
		cin >> capturedp;
		if (movetype == 'c' || movetype == 'C'){
			if (capturedp == 'p' || capturedp == 'P')
				validpieceselect = (TheBoard[p2.first][p2.second].getpiecetypeint() == 1);
			else if (capturedp == 'r' || capturedp == 'R')
				validpieceselect = (TheBoard[p2.first][p2.second].getpiecetypeint() == 2);
			else if (capturedp == 'n' || capturedp == 'N')
				validpieceselect = (TheBoard[p2.first][p2.second].getpiecetypeint() == 3);
			else if (capturedp == 'b' || capturedp == 'B')
				validpieceselect = (TheBoard[p2.first][p2.second].getpiecetypeint() == 4);
			else if (capturedp == 'q' || capturedp == 'Q')
				validpieceselect = (TheBoard[p2.first][p2.second].getpiecetypeint() == 5);
			else if (capturedp == 'k' || capturedp == 'K')
				validpieceselect = (TheBoard[p2.first][p2.second].getpiecetypeint() == 6);
			else
				validpieceselect = false;
		}
		else{
			validsecondarypiece = iscapturedpiece(capturedp);
		}
	}
	
	if (ischeck()){
		if (isvalid(p1, p2, a)){
			temppiece = TheBoard[p2.first][p2.second];
			move(p1,p2,a);
			playerturn = abs(playerturn - 1);
			if (ischeck()){
				move(p2,p1,a);
				TheBoard[p2.first][p2.second] = temppiece;
				checkbool = true;
				playerturn = abs(playerturn -1);
			}
			else{
				move(p2,p1,a);
				playerturn = abs(playerturn - 1);
				checkbool = false;
			}
		}
	}
	
		while(!isvalid(p1,p2, movetype) || !validpieceselect || !validsecondarypiece || checkbool){
			if (ischeck()){
				if (isvalid(p1, p2, a)){
					temppiece = TheBoard[p2.first][p2.second];
					move(p1,p2,a);
					playerturn = abs(playerturn - 1);
					if (ischeck()){
						move(p2,p1,a);
						TheBoard[p2.first][p2.second] = temppiece;
						p2.first = -1;
						p2.second = -1;
						checkbool = true;
						playerturn = abs(playerturn -1);
					}
					else{
						move(p2,p1,a);
						playerturn = abs(playerturn - 1);
						checkbool = false;
					}
				}
			}
			if (!isvalid(p1,p2, movetype) || !validpieceselect || !validsecondarypiece){
			
			cout << "Invalid move." << endl << endl;
			cout << "First piece type (K/Q/R/N/B/P): ";
			cin >> inputpiece;
			cout << "	first X: ";
			cin >> p;
			
			if (p == 'A'|| p == 'a')
				p1.first = 0;
			else if (p == 'B'|| p == 'b')
				p1.first = 1;
			else if (p == 'C'|| p == 'c')
				p1.first = 2;
			else if (p == 'D'|| p == 'd')
				p1.first = 3;
			else if (p == 'E'|| p == 'e')
				p1.first = 4;
			else
				p1.first = -1;
			
			cout << "	first Y: ";
			cin >> 	num1;
			
			if (num1 == 1)
				p1.second = 5;
			else if (num1 == 2)
				p1.second = 4;
			else if (num1 == 3)
				p1.second = 3;
			else if (num1 == 4)
				p1.second = 2;
			else if (num1 == 5)
				p1.second = 1;
			else if (num1 == 6)
				p1.second = 0;
				
			if (inputpiece == 'p' || inputpiece == 'P')
				validpieceselect = (TheBoard[p1.first][p1.second].getpiecetypeint() == 1);
			else if (inputpiece == 'r' || inputpiece == 'R')
				validpieceselect = (TheBoard[p1.first][p1.second].getpiecetypeint() == 2);
			else if (inputpiece == 'n' || inputpiece == 'N')
				validpieceselect = (TheBoard[p1.first][p1.second].getpiecetypeint() == 3);
			else if (inputpiece == 'b' || inputpiece == 'B')
				validpieceselect = (TheBoard[p1.first][p1.second].getpiecetypeint() == 4);
			else if (inputpiece == 'q' || inputpiece == 'Q')
				validpieceselect = (TheBoard[p1.first][p1.second].getpiecetypeint() == 5);
			else if (inputpiece == 'k' || inputpiece == 'K')
				validpieceselect = (TheBoard[p1.first][p1.second].getpiecetypeint() == 6);
			else
				validpieceselect = false;
				
				
			cout << "	second X: ";
			cin >> p;

			if (p == 'A'|| p == 'a')
				p2.first = 0;
			else if (p == 'B'|| p == 'b')
				p2.first = 1;
			else if (p == 'C'|| p == 'c')
				p2.first = 2;
			else if (p == 'D'|| p == 'd')
				p2.first = 3;
			else if (p == 'E'|| p == 'e')
				p2.first = 4;
			else
				p2.first = -1;

			cout << "	second Y: ";
			cin >> 	num1;
			
			if (num1 == 1)
				p2.second = 5;
			else if (num1 == 2)
				p2.second = 4;
			else if (num1 == 3)
				p2.second = 3;
			else if (num1 == 4)
				p2.second = 2;
			else if (num1 == 5)
				p2.second = 1;
			else if (num1 == 6)
				p2.second = 0;
				
			cout << "Enter the move type (m/c/r/p): ";
			cin >> movetype;
			
			
			while (movetype != 'M' && movetype != 'C' && movetype != 'R' && movetype != 'P' && movetype != 'm' && movetype != 'c' && movetype != 'r' && movetype != 'p' && movetype != 'A' && movetype != 'a'){
				cout << "Invalid movetype." << endl << endl;
				cout << "Enter the move type (m/c/r/p): ";
				cout << "AAAA" << endl;
				cin >> movetype;
			}
			
			if (movetype == 'c' || movetype == 'C' || movetype == 'r' || movetype == 'R'){
				cout << "Enter secondary piece type (K/Q/R/N/B/P): ";
				cin >> capturedp;
				if (movetype == 'c' || movetype == 'C'){
					if (capturedp == 'p' || capturedp == 'P')
						validpieceselect = (TheBoard[p2.first][p2.second].getpiecetypeint() == 1);
					else if (capturedp == 'r' || capturedp == 'R')
						validpieceselect = (TheBoard[p2.first][p2.second].getpiecetypeint() == 2);
					else if (capturedp == 'n' || capturedp == 'N')
						validpieceselect = (TheBoard[p2.first][p2.second].getpiecetypeint() == 3);
					else if (capturedp == 'b' || capturedp == 'B')
						validpieceselect = (TheBoard[p2.first][p2.second].getpiecetypeint() == 4);
					else if (capturedp == 'q' || capturedp == 'Q')
						validpieceselect = (TheBoard[p2.first][p2.second].getpiecetypeint() == 5);
					else if (capturedp == 'k' || capturedp == 'K')
						validpieceselect = (TheBoard[p2.first][p2.second].getpiecetypeint() == 6);
					else
						validpieceselect = false;
				}
				else{
					validsecondarypiece = iscapturedpiece(capturedp);
				}
			}
		} 
	}
	
	move(p1,p2,movetype);
	if (movetype == 'r' || movetype == 'R'){
		rescuepiece(p2,capturedp);
		moveswithoutcapture = 0;
	}
	if (movetype == 'p' || movetype == 'P'){
		promotepiece(p2);
		moveswithoutcapture = 0;
	}
	
	
}

//move pieces
void board::move(pair<int, int> p1, pair<int, int> & p2, char & movetype){
	char p;
	int num1;
	

	if (!isvalid(p1,p2, movetype)){
		while(!isvalid(p1,p2, movetype)){
			cout << "Invalid move." << endl << endl;
			
			cout << "	first X: ";
			cin >> p;
			
			if (p == 'A'|| p == 'a')
				p1.first = 0;
			else if (p == 'B'|| p == 'b')
				p1.first = 1;
			else if (p == 'C'|| p == 'c')
				p1.first = 2;
			else if (p == 'D'|| p == 'd')
				p1.first = 3;
			else if (p == 'E'|| p == 'e')
				p1.first = 4;
			else
				p1.first = -1;
			
			cout << "	first Y: ";
			cin >> 	num1;
			
			if (num1 == 1)
				p1.second = 5;
			else if (num1 == 2)
				p1.second = 4;
			else if (num1 == 3)
				p1.second = 3;
			else if (num1 == 4)
				p1.second = 2;
			else if (num1 == 5)
				p1.second = 1;
			else if (num1 == 6)
				p1.second = 0;
			else
				p1.second = -1;
				
				
			cout << "	second X: ";
			cin >> p;

			if (p == 'A'|| p == 'a')
				p2.first = 0;
			else if (p == 'B'|| p == 'b')
				p2.first = 1;
			else if (p == 'C'|| p == 'c')
				p2.first = 2;
			else if (p == 'D'|| p == 'd')
				p2.first = 3;
			else if (p == 'E'|| p == 'e')
				p2.first = 4;
			else
				p2.first = -1;

			cout << "	second Y: ";
			cin >> 	num1;
			
			if (num1 == 1)
				p2.second = 5;
			else if (num1 == 2)
				p2.second = 4;
			else if (num1 == 3)
				p2.second = 3;
			else if (num1 == 4)
				p2.second = 2;
			else if (num1 == 5)
				p2.second = 1;
			else if (num1 == 6)
				p2.second = 0;
			else
				p2.second = -1;
				
			cout << "Enter the move type (m/c/r/p): ";
			cin >> movetype;
			
			while (movetype != 'M' && movetype != 'C' && movetype != 'R' && movetype != 'P' && movetype != 'm' && movetype != 'c' && movetype != 'r' && movetype != 'p' && movetype != 'A' && movetype != 'a'){
				cout << "Invalid movetype." << endl << endl;
				cout << "Enter the move type (m/c/r/p): ";
				cin >> movetype;
			}
		}
	}
	
	pieces capturedpiece;
	capturedpiece = TheBoard[p2.first][p2.second];
	if (TheBoard[p2.first][p2.second].getplayer() != 2){
		if (TheBoard[p2.first][p2.second].getplayer() == 0){
			capturedpiece.move(-1,-1);
			pieceslost.push_back(TheBoard[p2.first][p2.second]);
			moveswithoutcapture = -1;
		}
		else{
			enemiescaptured.push_back(TheBoard[p2.first][p2.second]);
			capturedpiece.move(-1,-1);
			moveswithoutcapture = -1;
		}
	}
	
	pieces movepiece;
	movepiece = TheBoard[p1.first][p1.second];
	TheBoard[p1.first][p1.second] = empp;		//Previous piece position is now empty
	movepiece.move(p2.first, p2.second);			//make the piece know its new position
	TheBoard[p2.first][p2.second] = movepiece;	//make the board know where the piece is
	
	
	moveswithoutcapture++;
	
	playerturn = abs(playerturn - 1);

}

//sees if a piece is captured
//true if in the respective vector of captured pieces, false if not
bool board::iscapturedpiece(char capturedp){
	int pieceval;
	if (capturedp == 'r' || capturedp == 'R')		//assigns a piece value for the piece
		pieceval = 2;
	else if (capturedp == 'n' || capturedp == 'N')
		pieceval = 3;
	else if (capturedp == 'b' || capturedp == 'B')
		pieceval = 4;
	else if (capturedp == 'q' || capturedp == 'Q')
		pieceval = 5;
		
	int vectorsize = 0;
	if (playerturn == 0)					//assign the vector size according to player
		vectorsize = pieceslost.size();
	else
		vectorsize = enemiescaptured.size();
		
	for (int i = 0; i < vectorsize; i++){		//check each element of the vector depending on player
		if (playerturn == 0){
			if (pieceslost[i].getpiecetypeint() == pieceval)
				return true;
		}
		else{
			if (pieceslost[i].getpiecetypeint() == pieceval)
				return true;
		}
	}
	return false;
}


//see if a spot is empty
bool board::isempty(pair<int, int> d){
	if (TheBoard[d.first][d.second].getpiecetypeint() == 0)
		return true;
	else
		return false;
}

//Given a position, return the piece
pieces board::getpiece(pair <int, int> d){
	return TheBoard[d.first][d.second];
}

//print out the board
void board::display(){
	cout << "A  B  C  D  E "<< endl;
	int num = 6;
	for (int j = 0; j < 6; j++){
		cout << "--------------"<< endl;
		for (int i = 0; i < 5; i++){
			if (TheBoard[i][j].getpiecetypeint() == 1){
				if (TheBoard[i][j].getplayer() == 0)
					cout << "WP|";
				else
					cout << "BP|";
			}
			else if (TheBoard[i][j].getpiecetypeint() == 2){
				if (TheBoard[i][j].getplayer() == 0)
					cout << "WR|";
				else
					cout << "BR|";
			}
			else if (TheBoard[i][j].getpiecetypeint() == 3){
				if (TheBoard[i][j].getplayer() == 0)
					cout << "WN|";
				else
					cout << "BN|";
			}
			else if (TheBoard[i][j].getpiecetypeint() == 4){
				if (TheBoard[i][j].getplayer() == 0)
					cout << "WB|";
				else
					cout << "BB|";
			}
			else if (TheBoard[i][j].getpiecetypeint() == 5){
				if (TheBoard[i][j].getplayer() == 0)
					cout << "WQ|";
				else
					cout << "BQ|";
			}
			else if (TheBoard[i][j].getpiecetypeint() == 6){
				if (TheBoard[i][j].getplayer() == 0)
					cout << "WK|";
				else
					cout << "BK|";
			}
			else
				cout << "  |";
		}
		cout << "| " << num << endl;
		num--;
	}
}


//See if a move is valid, true if  it is, false if not
bool board::isvalid(pair <int,int> p1, pair <int,int> p2, char movetype){
	if (p1.first < 0 || p1.second < 0 || p2.first < 0 || p2.second < 0 || p1.second > 5 || p2.second > 5)		//position is outside of the board
		return false;
	if (p1 == p2)			//positions are the same
		return false;
		
	if (movetype == 'p' || movetype == 'P'){	//Attempts a promotion when it's not valid
		if (!ispromotion(p2))
			return false;
	}
	
	vector<pair<int, int> > v;		//vector v will hold possible moves for a given piece
	int piecenum = TheBoard[p1.first][p1.second].getpiecetypeint();
	int curplayer = TheBoard[p1.first][p1.second].getplayer();
	
	if (curplayer != playerturn)		//selected piece is not player's
		return false;
	
	if (piecenum == 0)			//selected board position is empty
		return false;
	else {					//selected position is not empty...
		v = generatemoves(p1, movetype);	//vector v now holds the possible positions the piece at p1 can move to.
		return (isinvector(v,p2));			//return the result of isinvector, true if p2 is in v, false if not.
	}
	return true;
}

//generates all possible moves of piece at position p1 given the type of move movetype
//returns a vector of positions
vector<pair<int, int> > board::generatemoves(pair<int, int> p1, char movetype){
	vector<pair<int, int> > v;
	v.resize(0);
	int localx = p1.first;
	int localy = p1.second;
	pair<int, int> p(localx, localy);
	
	if (TheBoard[localx][localy].getpiecetypeint() == 1){	//PAWN
		if (playerturn == 0){
			if(localy != 0){			//White pawn
				if (TheBoard[localx][localy - 1].getpiecetypeint() == 0){		//Can only move up...
					p.second = localy - 1;
					if (movetype != 'C' && movetype != 'c')
						v.push_back(p);
				}
				if (localx < 4){									//up left as a capture...
					if (movetype != 'M' && movetype != 'm'){
						if (TheBoard[localx+1][localy - 1].getplayer() == 1){
						p.second = localy - 1;
						p.first = localx + 1;
						v.push_back(p);
						}
					}
				}
				if (localx > 0){								//up right as a capture.
					if (movetype != 'M' && movetype != 'm'){
						if (TheBoard[localx-1][localy - 1].getplayer() == 1){
						p.second = localy - 1;
						p.first = localx - 1;
						v.push_back(p);
						}
					}
				}
			}
		}
		else{						//black pawn...
			if(localy != 5){						//Can only move down...
				if (TheBoard[localx][localy + 1].getpiecetypeint() == 0){
					p.second = localy + 1;
					if (movetype != 'C' && movetype != 'c')
						v.push_back(p);
				}								//Left as a capture...
				if (localx < 4){
					if (movetype != 'M' && movetype != 'm'){
						if (TheBoard[localx+1][localy + 1].getplayer() == 0){
							p.second = localy + 1;
							p.first = localx + 1;
							v.push_back(p);
						}
					}
				}
				if (localx > 0){					//Right as a capture
					if (movetype != 'M' && movetype != 'm'){
						if (TheBoard[localx-1][localy + 1].getplayer() == 0){
							p.second = localy + 1;
							p.first = localx - 1;
							v.push_back(p);
						}
					}
				}
			}
		}
	}
	localy = p1.second;		//reset all variables just in case...
	localx = p1.first;
	p.first = p1.first;
	p.second = p1.second;
	if (TheBoard[p1.first][p1.second].getpiecetypeint() == 2){	//ROOK
		while (true){								//UP
			p.second = localy - 1;
			if (localy == 0)
				break;
			if (TheBoard[localx][localy - 1].getpiecetypeint() == 0){
				if (movetype != 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			else{
				if (TheBoard[localx][localy - 1].getplayer() != playerturn &&TheBoard[localx][localy - 1].getplayer() != 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				}
				break;
			}
			localy--;
		}
		localy = p1.second;
		p.first = p1.first;
		p.second = p1.second;
		while (true){								//DOWN
			p.second = localy + 1;
			if (localy == 5)
				break;
			if (TheBoard[localx][localy+1].getpiecetypeint() == 0){
				if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			else{
				if (TheBoard[localx][localy+1].getplayer()!= playerturn && TheBoard[localx][localy+1].getplayer()!= 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				}
				break;
			}
			localy++;
		}									//LEFT
		localy = p1.second;
		p.first = p1.first;
		p.second = p1.second;
		while (true){
			p.first = localx - 1;
			if (localx == 0)
				break;
			if (TheBoard[localx - 1][localy].getpiecetypeint() == 0){
				if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			else{
				if (TheBoard[localx - 1][localy].getplayer() != playerturn && TheBoard[localx - 1][localy].getplayer() != 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				break;
				}
			}
			localx--;
		}					
		localx = p1.first;
		p.first = p1.first;
		p.second = p1.second;	
		while (true){								//RIGHT
			p.first = localx + 1;
			if (localx == 4)
				break;
			if (TheBoard[localx + 1][localy].getpiecetypeint() == 0){
				if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			else{
				if (TheBoard[localx + 1][localy].getplayer() != playerturn && TheBoard[localx + 1][localy].getplayer() != 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				break;
				}
			}
			localx++;
		}
		localx = p1.first;
	}
	localy = p1.second;
	localx = p1.first;
	p.first = p1.first;
	p.second = p1.second;
	
	if (TheBoard[p1.first][p1.second].getpiecetypeint() == 3){	//KNIGHT
		if (localy > 1){
			p.second = localy - 2;		//up
			if (localx >0){					//left
				p.first = localx - 1;
				if (TheBoard[p.first][p.second].getpiecetypeint() == 0){
					if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				}
				else{
					if (TheBoard[p.first][p.second].getplayer() != playerturn && TheBoard[p.first][p.second].getplayer() != 2){
						if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
							v.push_back(p);
						}
					}
				}
			}
			p.first = p1.first;
			if (localx <4){
				p.first = localx + 1;		//right
				if (TheBoard[p.first][p.second].getpiecetypeint() == 0){
					if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				}
				else{
					if (TheBoard[p.first][p.second].getplayer() != playerturn && TheBoard[p.first][p.second].getplayer() != 2){
						if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
							v.push_back(p);
						}
					}
				}
			}
		}
		if (localy < 4){					//down
			p.second = localy + 2;
			if (localx >0){					//left
				p.first = localx - 1;
				if (TheBoard[p.first][p.second].getpiecetypeint() == 0){
					if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				}
				else{
					if (TheBoard[p.first][p.second].getplayer() != playerturn && TheBoard[p.first][p.second].getplayer() != 2){
						if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
							v.push_back(p);
						}
					}
				}
			}
			p.first = p1.first;
			if (localx <4){
				p.first = localx + 1;		//right
				if (TheBoard[p.first][p.second].getpiecetypeint() == 0){
					if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				}
				else{
					if (TheBoard[p.first][p.second].getplayer() != playerturn && TheBoard[p.first][p.second].getplayer() != 2){
						if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
							v.push_back(p);
						}
					}
				}
			}
		}
		if (localx > 1){
			p.first = localx - 2;		//left
			if (localy >0){					//up
				p.second = localy - 1;
				if (TheBoard[p.first][p.second].getpiecetypeint() == 0){
					if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				}
				else{
					if (TheBoard[p.first][p.second].getplayer() != playerturn && TheBoard[p.first][p.second].getplayer() != 2){
						if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
							v.push_back(p);
						}
					}
				}
			}
			p.first = p1.first;
			if (localy <5){
				p.second = localy + 1;		//down
				if (TheBoard[p.first][p.second].getpiecetypeint() == 0){
					if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				}
				else{
					if (TheBoard[p.first][p.second].getplayer() != playerturn && TheBoard[p.first][p.second].getplayer() != 2){
						if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
							v.push_back(p);
						}
					}
				}
			}
		}
		if (localx < 3){					//right
			p.first = localx + 2;
			if (localy >0){					//up
				p.second = localy - 1;
				if (TheBoard[p.first][p.second].getpiecetypeint() == 0){
					if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				}
				else{
					if (TheBoard[p.first][p.second].getplayer() != playerturn && TheBoard[p.first][p.second].getplayer() != 2){
						if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
							v.push_back(p);
						}
					}
				}
			}
			p.first = p1.first;
			if (localy <5){
				p.second = localy + 1;		//down
				if (TheBoard[p.first][p.second].getpiecetypeint() == 0){
					if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				}
				else{
					if (TheBoard[p.first][p.second].getplayer() != playerturn && TheBoard[p.first][p.second].getplayer() != 2){
						if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
							v.push_back(p);
						}
					}
				}
			}
		}
	}
	localy = p1.second;
	localx = p1.first;
	p.first = p1.first;
	p.second = p1.second;
	if (TheBoard[p1.first][p1.second].getpiecetypeint() == 4){	//BISHOP
		while (true){											//UP LEFT
			p.second = localy - 1;
			p.first = localx - 1;
			if (localy == 0 || localx == 0)
				break;
			if (TheBoard[localx - 1][localy - 1].getpiecetypeint() == 0){
				if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			else{
				if (TheBoard[localx - 1][localy - 1].getplayer() != playerturn && TheBoard[localx - 1][localy - 1].getplayer() != 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				break;
				}
			}
			localy--;
			localx--;
		}
		localx = p1.first;
		localy = p1.second;
		p.first = p1.first;
		p.second = p1.second;
		while (true){									//DOWN LEFT
			p.second = localy + 1;
			p.first = localx - 1;
			if (localy == 5 || localx == 0)
				break;
			if (TheBoard[localx - 1][localy+1].getpiecetypeint() == 0){
				if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			else{
				if (TheBoard[localx - 1][localy+1].getplayer()!= playerturn && TheBoard[localx - 1][localy+1].getplayer()!= 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				break;
				}
			}
			localy++;
			localx--;
		}
		localy = p1.second;
		localx = p1.first;
		p.first = p1.first;
		p.second = p1.second;
		while (true){					//UP RIGHT
			p.first = localx + 1;
			p.second = localy - 1;
			if (localx == 4|| localy == 0)
				break;
			if (TheBoard[localx + 1][localy - 1].getpiecetypeint() == 0){
				if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			else{
				if (TheBoard[localx + 1][localy - 1].getplayer() != playerturn && TheBoard[localx + 1][localy - 1].getplayer() != 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				break;
				}
			}
			localx++;
			localy--;
		}
		localx = p1.first;
		localy = p1.second;
		p.first = p1.first;
		p.second = p1.second;
		while (true){					//DOWN RIGHT
			p.first = localx + 1;
			p.second = localy + 1;
			if (localx == 4 || localy == 5)
				break;
			if (TheBoard[localx + 1][localy + 1].getpiecetypeint() == 0){
				if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			else{
				if (TheBoard[localx + 1][localy + 1].getplayer() != playerturn && TheBoard[localx + 1][localy + 1].getplayer() != 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				break;
				}
			}
			localx++;
			localy++;
		}
	}
	if (TheBoard[p1.first][p1.second].getpiecetypeint() == 5){	//QUEEN
		while (true){											//UP LEFT
			p.second = localy - 1;
			p.first = localx - 1;
			if (localy == 0 || localx == 0)
				break;
			if (TheBoard[localx - 1][localy - 1].getpiecetypeint() == 0){
				if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			else{
				if (TheBoard[localx - 1][localy - 1].getplayer() != playerturn && TheBoard[localx - 1][localy - 1].getplayer() != 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				break;
				}
			}
			localy--;
			localx--;
		}
		localx = p1.first;
		localy = p1.second;
		p.first = p1.first;
		p.second = p1.second;
		while (true){									//DOWN LEFT
			p.second = localy + 1;
			p.first = localx - 1;
			if (localy == 5 || localx == 0)
				break;
			if (TheBoard[localx - 1][localy+1].getpiecetypeint() == 0){
				if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			else{
				if (TheBoard[localx - 1][localy+1].getplayer()!= playerturn && TheBoard[localx - 1][localy+1].getplayer()!= 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				break;
				}
			}
			localy++;
			localx--;
		}
		localy = p1.second;
		localx = p1.first;
		p.first = p1.first;
		p.second = p1.second;
		while (true){					//UP RIGHT
			p.first = localx + 1;
			p.second = localy - 1;
			if (localx == 4|| localy == 0)
				break;
			if (TheBoard[localx + 1][localy - 1].getpiecetypeint() == 0){
				if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			else{
				if (TheBoard[localx + 1][localy - 1].getplayer() != playerturn && TheBoard[localx + 1][localy - 1].getplayer() != 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				break;
				}
			}
			localx++;
			localy--;
		}
		localx = p1.first;
		localy = p1.second;
		p.first = p1.first;
		p.second = p1.second;
		while (true){					//DOWN RIGHT
			p.first = localx + 1;
			p.second = localy + 1;
			if (localx == 4 || localy == 5)
				break;
			if (TheBoard[localx + 1][localy + 1].getpiecetypeint() == 0){
				if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			else{
				if (TheBoard[localx + 1][localy + 1].getplayer() != playerturn && TheBoard[localx + 1][localy + 1].getplayer() != 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				break;
				}
			}
			localx++;
			localy++;
		}
	localy = p1.second;
	localx = p1.first;
	p.first = p1.first;
	p.second = p1.second;
		while (true){						//UP
			p.second = localy - 1;
			if (localy == 0)
				break;
			if (TheBoard[localx][localy - 1].getpiecetypeint() == 0){
				if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			else{
				if (TheBoard[localx][localy - 1].getplayer() != playerturn && TheBoard[localx][localy - 1].getplayer() != 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				break;
				}
			}
			localy--;
		}
		localy = p1.second;
		p.first = p1.first;
		p.second = p1.second;
		while (true){						//DOWN
			p.second = localy + 1;
			if (localy == 5)
				break;
			if (TheBoard[localx][localy+1].getpiecetypeint() == 0){
				if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			else{
				if (TheBoard[localx][localy+1].getplayer()!= playerturn && TheBoard[localx][localy+1].getplayer()!= 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				break;
				}
			}
			localy++;
		}
		localy = p1.second;
		p.first = p1.first;
		p.second = p1.second;
		while (true){						//LEFT
			p.first = localx - 1;
			if (localx == 0)
				break;
			if (TheBoard[localx - 1][localy].getpiecetypeint() == 0){
				if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			else{
				if (TheBoard[localx - 1][localy].getplayer() != playerturn && TheBoard[localx - 1][localy].getplayer() != 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				break;
				}
			}
			localx--;
		}									//RIGHT
		localx = p1.first;
		p.first = p1.first;
		p.second = p1.second;
		while (true){
			p.first = localx + 1;
			if (localx == 4)
				break;
			if (TheBoard[localx + 1][localy].getpiecetypeint() == 0){
				if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			else{
				if (TheBoard[localx + 1][localy].getplayer() != playerturn && TheBoard[localx + 1][localy].getplayer() != 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				break;
				}
			}
			localx++;
		}
		localx = p1.first;
	}
		localy = p1.second;
	localx = p1.first;
	p.first = p1.first;
	p.second = p1.second;
	if (TheBoard[p1.first][p1.second].getpiecetypeint() == 6){	//KING
		if (localx != 4){			//RIGHT
			p.first = localx + 1;
			if (TheBoard[p.first][p.second].getpiecetypeint() == 0){
				if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			else if (TheBoard[p.first][p.second].getplayer() != playerturn && TheBoard[p.first][p.second].getplayer() != 2){
				if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
		}
		if (localx != 0){			//LEFT
			p.first = localx - 1;
			if (TheBoard[p.first][p.second].getpiecetypeint() == 0){
				if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
				v.push_back(p);
				}
			}
			else if (TheBoard[p.first][p.second].getplayer() != playerturn && TheBoard[p.first][p.second].getplayer() != 2){
				if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
		}
		p.first = localx;
		if (localy != 5){			//DOWN
			p.second = localy + 1;
			if (TheBoard[p.first][p.second].getpiecetypeint() == 0){
				if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			else if (TheBoard[p.first][p.second].getplayer() != playerturn && TheBoard[p.first][p.second].getplayer() != 2){
				if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			if (localx != 4){		//DOWNRIGHT
				p.first = localx + 1;
				if (TheBoard[p.first][p.second].getpiecetypeint() == 0){
					if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
					}
				}
				else if (TheBoard[p.first][p.second].getplayer() != playerturn && TheBoard[p.first][p.second].getplayer() != 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				}
			}
			if (localx != 0){		//DOWNLEFT
				p.first = localx - 1;
				if (TheBoard[p.first][p.second].getpiecetypeint() == 0){
					if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				}
				else if (TheBoard[p.first][p.second].getplayer() != playerturn && TheBoard[p.first][p.second].getplayer() != 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				}
			}
		
	p.first = p1.first;
	p.second = p1.second;
		
		}
		if (localy != 0){			//UP
			p.second = localy - 1;
			if (TheBoard[p.first][p.second].getpiecetypeint() == 0){
				if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			else if (TheBoard[p.first][p.second].getplayer() != playerturn && TheBoard[p.first][p.second].getplayer() != 2){
				if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
					v.push_back(p);
				}
			}
			if (localx != 4){		//UPRIGHT
				p.first = localx + 1;
				if (TheBoard[p.first][p.second].getpiecetypeint() == 0){
					if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				}
				else if (TheBoard[p.first][p.second].getplayer() != playerturn && TheBoard[p.first][p.second].getplayer() != 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				}
			}
			if (localx != 0){		//UPLEFT
				p.first = localx - 1;
				if (TheBoard[p.first][p.second].getpiecetypeint() == 0){
					if (movetype == 'M' || movetype == 'm' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				}
				else if (TheBoard[p.first][p.second].getplayer() != playerturn &&TheBoard[p.first][p.second].getplayer() != 2){
					if (movetype == 'C' || movetype == 'c' || movetype == 'A' || movetype == 'a'){
						v.push_back(p);
					}
				}
			}
		}
	}
	return v;
}


//Checks to see if the position p1 is in the vector
//True if it is, false if not
bool board::isinvector(vector<pair <int, int> > v,pair <int,int> p1){
	for (int i = 0; i < v.size(); i++){
		//cout << "(" << v[i].first << " , " << v[i].second << ")";
	}
	for (int i = 0; i < v.size(); i++){
		if (v[i] == p1)
			return true;
	}
	return false;
}

//sees if player is in check
bool board::ischeck(){
	playerturn = abs(playerturn - 1);		//change to opposing team so moves will be valid
	int localx;
	int localy;

	if (playerturn == 0){				//set local x and y to original player's king
		localx = bkp.getx();
		localy = bkp.gety();
	}
	else{
		localx = wkp.getx();
		localy = wkp.gety();
	}
	
	
	pair<int, int> p1;
	pair<int, int> p2;
	p2.first = localx;
	p2.second = localy;
	pieces p;
	
	//check every space of the board
	for (int j =0; j < 6; j++){
		for (int i = 0; i < 5; i++){
			if (TheBoard[i][j].getplayer() == playerturn){	//if the piece is of the player that can capture the king...
				p = TheBoard[i][j];
				p1.first = i;
				p1.second = j;
				if (isvalid(p1, p2, 'c')){			//see if the capture is possible
					//cout << endl << endl << p.getpiecetypeint() << endl << endl;
					playerturn = abs(playerturn - 1);		//return to original player
					return true;						//return true
				}
			//	cout << endl;
			}
		}
	}
	playerturn = abs(playerturn - 1);			//none of the positions could put the king in check
	return false;						//not in check
}

//finds the piece that's putting the king in check
//returns the position of that piece
//similar to the ischeck() function
pair<int, int> board::checkmaker(){
	playerturn = abs(playerturn - 1);		//switch to opposite team
	int localx;
	int localy;
	
	if (playerturn == 0){
		localx = bkp.getx();
		localy = bkp.gety();
	}
	else{
		localx = wkp.getx();
		localy = wkp.gety();
	}
	
	
	pair<int, int> p1;
	pair<int, int> p2;
	p2.first = localx;
	p2.second = localy;
	
	for (int j =0; j < 6; j++){
		for (int i = 0; i < 5; i++){
			if (TheBoard[i][j].getplayer() == playerturn){
				p1.first = i;
				p1.second = j;
				if (isvalid(p1, p2, 'c')){
					playerturn = abs(playerturn - 1);
					return p1;				//return the position of the piece putting the king in check
				}
			}
		}
	}
	playerturn = abs(playerturn - 1);
	p2.first = -1;				//No piece can put the king in check
	p2.second = -1;
	
	return p2;						//returns bogus board position
}

//See if the king is in checkmate
//returns true if no possible moves that gets the king out of check, false if not
bool board::ischeckmate(){				//assume we start in black's turn, seeing if black is in checkmate
	int localx;
	int localy;
	char a = 'a';
	
	if (playerturn == 1){
		localx = bkp.getx();
		localy = bkp.gety();
	}
	else{
		localx = wkp.getx();
		localy = wkp.gety();
	}
	
	pair<int, int> p1;
	pair<int, int> p2;
	pieces removedpiece;
	
	p1.first = localx;		//Try to move the king out of check
	p1.second = localy;
	p2.first = p1.first;
	p2.second = p1.second;
		p2.first = localx + 1;			//RIGHT
		if (isvalid(p1,p2, a)){			//try to move black king to right
			removedpiece = TheBoard[p2.first][p2.second];
			move(p1,p2,a);				//move, switches to white's turn
			playerturn = abs(playerturn - 1);	//switch back to black's
			if(!ischeck()){						//see if black is in check
				move(p2, p1,a);				//move the king back, switches to white
				removedpiece.move(p2.first,p2.second);		//put the removed piece's coord's back
				TheBoard[p2.first][p2.second] = removedpiece;	//put piece back on the board
				playerturn = abs(playerturn - 1);				//switch back to black
				return false;								//return false, not in checkmate, still black's moves
			}
			move(p2, p1,a);							//still in check, switches to white's
			playerturn = abs(playerturn - 1);			//switch back to black's
			removedpiece.move(p2.first,p2.second);		//put piece's coord's back
			TheBoard[p2.first][p2.second] = removedpiece;	//put piece in board
		}
		
		p2.first = p1.first;
		p2.second = p1.second;
		
		p2.first = localx - 1;		//LEFT
		if (isvalid(p1,p2, 'a')){
			removedpiece = TheBoard[p2.first][p2.second];
			move(p1,p2,a);
			playerturn = abs(playerturn - 1);
			if(!ischeck()){
				move(p2, p1,a);
				removedpiece.move(p2.first,p2.second);
				TheBoard[p2.first][p2.second] = removedpiece;
				playerturn = abs(playerturn - 1);
				return false;
			}
			move(p2, p1,a);
			playerturn = abs(playerturn - 1);
			removedpiece.move(p2.first,p2.second);
			TheBoard[p2.first][p2.second] = removedpiece;
		}
			
		p2.first = p1.first;
		p2.second = p1.second;
		
		p2.second = localy + 1;			//DOWN
		if (isvalid(p1,p2, 'a')){
			removedpiece = TheBoard[p2.first][p2.second];
			move(p1,p2,a);
			playerturn = abs(playerturn - 1);
			if(!ischeck()){
				move(p2, p1,a);
				removedpiece.move(p2.first,p2.second);
				TheBoard[p2.first][p2.second] = removedpiece;
				playerturn = abs(playerturn - 1);
				return false;
			}
			move(p2, p1,a);
			playerturn = abs(playerturn - 1);
			removedpiece.move(p2.first,p2.second);
			TheBoard[p2.first][p2.second] = removedpiece;
		}
			
		p2.first = p1.first;
		p2.second = p1.second;
		
		p2.second = localy + 1;
		p2.first = localx + 1;
		if (isvalid(p1,p2, 'a')){	//DOWNRIGHT
			removedpiece = TheBoard[p2.first][p2.second];
			move(p1,p2,a);
			playerturn = abs(playerturn - 1);
			if(!ischeck()){
				move(p2, p1,a);
				removedpiece.move(p2.first,p2.second);
				TheBoard[p2.first][p2.second] = removedpiece;
				playerturn = abs(playerturn - 1);
				return false;
			}
			move(p2, p1,a);
			playerturn = abs(playerturn - 1);
			removedpiece.move(p2.first,p2.second);
			TheBoard[p2.first][p2.second] = removedpiece;
		}
			
		p2.first = p1.first;
		p2.second = p1.second;
		
		
		p2.second = localy + 1;
		p2.first = localx - 1;
		if (isvalid(p1,p2, 'a')){		//DOWNLEFT
			removedpiece = TheBoard[p2.first][p2.second];
			move(p1,p2,a);
			playerturn = abs(playerturn - 1);
			if(!ischeck()){
				move(p2, p1,a);
				removedpiece.move(p2.first,p2.second);
				TheBoard[p2.first][p2.second] = removedpiece;
				playerturn = abs(playerturn - 1);
				return false;
			}
			move(p2, p1,a);
			playerturn = abs(playerturn - 1);
			removedpiece.move(p2.first,p2.second);
			TheBoard[p2.first][p2.second] = removedpiece;
		}
			
		p2.first = p1.first;
		p2.second = p1.second;
		

		p2.second = localy - 1;
		if (isvalid(p1,p2, 'a')){		//UP
			removedpiece = TheBoard[p2.first][p2.second];
			move(p1,p2,a);
			playerturn = abs(playerturn - 1);
			if(!ischeck()){
				move(p2, p1,a);
				removedpiece.move(p2.first,p2.second);
				TheBoard[p2.first][p2.second] = removedpiece;
				playerturn = abs(playerturn - 1);
				return false;
			}
			move(p2, p1,a);
			playerturn = abs(playerturn - 1);
			removedpiece.move(p2.first,p2.second);
			TheBoard[p2.first][p2.second] = removedpiece;
		}
			
		p2.first = p1.first;
		p2.second = p1.second;
		
		p2.second = localy - 1;
		p2.first = localx + 1;
		if (isvalid(p1,p2, 'a')){		//UPRIGHT
			removedpiece = TheBoard[p2.first][p2.second];
			move(p1,p2,a);
			playerturn = abs(playerturn - 1);
			if(!ischeck()){
				move(p2, p1,a);
				removedpiece.move(p2.first,p2.second);
				TheBoard[p2.first][p2.second] = removedpiece;
				playerturn = abs(playerturn - 1);
				return false;
			}
			move(p2, p1,a);
			playerturn = abs(playerturn - 1);
			removedpiece.move(p2.first,p2.second);
			TheBoard[p2.first][p2.second] = removedpiece;
		}
			
		p2.first = p1.first;
		p2.second = p1.second;

		p2.second = localy + 1;
		p2.first = localx - 1;
		if (isvalid(p1,p2, 'a')){			//UPLEFT
			removedpiece = TheBoard[p2.first][p2.second];
			move(p1,p2,a);
			playerturn = abs(playerturn - 1);
			if(!ischeck()){
				move(p2, p1,a);
				removedpiece.move(p2.first,p2.second);
				TheBoard[p2.first][p2.second] = removedpiece;
				playerturn = abs(playerturn - 1);
				return false;
			}
			move(p2, p1,a);
			removedpiece.move(p2.first,p2.second);
			TheBoard[p2.first][p2.second] = removedpiece;
		}
										//Try to have something capture the checkmaker
										//if seeing if black is in checkmate...
	pair<int, int> p3;					//we're already in white's turn...
	playerturn = abs(playerturn - 1);	//switch to black
	p3 = checkmaker();					//see who is putting black in check
	pair<int,int> p4;
	playerturn = abs(playerturn - 1);	//switch to white
	p4 = canbecapturedby(p3);			//as white, see which black pieces can capture p3
	if (p4.first != -1){				//p3 can be captured
		playerturn = abs(playerturn - 1);						//as black
		removedpiece = TheBoard[p4.first][p4.second];		//set this for the piece that'll be removed
		move(p4,p3, a);											//make the capture, automatically switches to white
		playerturn = abs(playerturn - 1);							//switch back to black
		if (!ischeck()){										//the move makes them no longer in check
			move(p3,p4, a);										//move the capturing piece back, autmatically switches to white
			removedpiece.move(p4.first,p4.second);
			TheBoard[p4.first][p4.second] = removedpiece;	//put the captured piece back on the board
								//captured x back
									//captured y back
			playerturn = abs(playerturn - 1);					//switch back to black
			return false;										//return, remaining in black's turn
		}
		else{													//still in check
			move(p3,p4, a);										//move cap'n piece back, auto switching to white
			removedpiece.move(p2.first,p2.second);
			TheBoard[p4.first][p4.second] = removedpiece;	//put cap'd piece on board
									//cap'd coord's

		}
	}
	
	playerturn = abs(playerturn - 1);
										//Try to put something between the king and the checkmaker
	if (playerturn == 1){
		localx = bkp.getx();
		localy = bkp.gety();
	}
	else{
		localx = wkp.getx();
		localy = wkp.gety();
	}
	p2.first = localx;
	p2.second = localy;
	
	
	int xdistance;
	int ydistance;
	pair<int, int> temppos;						//black's move
	p3 = checkmaker();
	
	if (p2.first == p3.first){			//checkmaker is on the same x as king
		ydistance = abs(p2.second - p3.second);
		if (ydistance>1){		//and they're more than one space apart
			temppos.first = p2.first;
			if (p2.second < p3.second)
				localy = p2.second;
			else
				localy = p3.second;
				
			localy++;
			while (ydistance >=1){
				temppos.second = localy;
				playerturn = abs(playerturn-1);			//to white's
				p4 = canbecapturedby(temppos);
				playerturn = abs(playerturn-1);			//to black's
				if (isvalid(p4,temppos,'a')){\
					move(p4,temppos,a);			//move into free space between checkmaker and king, goes to white's turn
					playerturn = abs(playerturn - 1);	//back to  black's turn
					if (!ischeck()){					//no longer in check
						move(temppos, p4, a);			//move piece back, switches to white
						playerturn = abs(playerturn - 1);	//put back in black's
						return false;
					}
					move(temppos, p4, a);			//move piece back, switches to white
					playerturn = abs(playerturn - 1);	//put back in black's
				}
				localy++;		//go to next space
				ydistance--;	//distance decreases
			}
		}
	}
	else if (p2.second == p3.second){			//checkmaker is on the same y as king
		xdistance = abs(p2.second - p3.second);
		if (xdistance>1){		//and they're more than one space apart
			temppos.second = p2.second;
			if (p2.second < p3.second)
				localx = p2.second;
			else
				localx = p3.second;
				
			localx++;
			while (xdistance >=1){
				temppos.first = localx;
				playerturn = abs(playerturn-1);			//to white's
				p4 = canbecapturedby(temppos);
				playerturn = abs(playerturn-1);			//to black's
				if (isvalid(p4,temppos,'a')){
					move(p4,temppos,a);			//move into free space between checkmaker and king, goes to white's turn
					playerturn = abs(playerturn - 1);	//back to  black's turn
					if (!ischeck()){					//no longer in check
						move(temppos, p4, a);			//move piece back, switches to white
						playerturn = abs(playerturn - 1);	//put back in black's
						return false;
					}
					move(temppos, p4, a);			//move piece back, switches to white
					playerturn = abs(playerturn - 1);	//put back in black's
				}
				localx++;		//go to next space
				xdistance--;	//distance decreases
			}
		}
	}
	else if ((((p2.second - p3.second) > 1) && ((p2.first - p3.first)>1))
				|| (((p3.second - p2.second) > 1) && ((p3.first - p2.first) > 1))){			//diagonal backslash
		xdistance = abs(p2.second - p3.second);
		ydistance = abs(p2.first - p3.first);
			if (p2.second < p3.second)
				localy = p2.second;
			else
				localy = p3.second;
				
			if (p2.second < p3.second)
				localx = p2.first;
			else
				localx = p3.first;
				
			localx++;
			localy++;
			while (ydistance > 1 && xdistance > 1){
				temppos.first = localx;
				temppos.second = localy;
				playerturn = abs(playerturn - 1);
				p4 = canbecapturedby(temppos);
				playerturn = abs(playerturn - 1);
				if (isvalid(p4, temppos, 'a')){
					move(p4, temppos, a);
					playerturn = abs(playerturn - 1);
					if (!ischeck()){
						move(temppos, p4, a);
						playerturn = abs(playerturn - 1);
						return false;
					}
					move(temppos, p4, a);			//move piece back, switches to white
					playerturn = abs(playerturn - 1);	//put back in black's
				}
				localx++;
				localy++;
				ydistance--;
				xdistance--;
			}
	}
	else if (((p2.second - p3.second) > 1 && (p3.first - p2.first)>1)
				|| ((p3.second - p2.second) > 1 && (p2.first - p3.first) > 1)){			//diagonal forward slash
		xdistance = abs(p2.second - p3.second);
		ydistance = abs(p2.first - p3.first);
			if (p2.second > p3.second)
				localy = p2.second;
			else
				localy = p3.second;
				
			if (p2.second > p3.second)
				localx = p2.first;
			else
				localx = p3.first;
				
			localx++;
			localy--;
			while (ydistance > 1 && xdistance > 1){
				temppos.first = localx;
				temppos.second = localy;
				playerturn = abs(playerturn - 1);
				p4 = canbecapturedby(temppos);
				playerturn = abs(playerturn - 1);
				if (isvalid(p4, temppos, 'a')){
					move(p4, temppos, a);
					playerturn = abs(playerturn - 1);
					if (!ischeck()){
						move(temppos, p4, a);
						playerturn = abs(playerturn - 1);
						return false;
					}
					move(temppos, p4, a);			//move piece back, switches to white
					playerturn = abs(playerturn - 1);	//put back in black's
				}
				localx++;
				localy--;
				ydistance--;
				xdistance--;
			}
	}
	
	
	playerturn = abs(playerturn - 1);		//put back in black's turn
	return true;							//the king is still in check

}

//return the piece putting the piece at position p2 in check, if there is one
pair<int,int> board::canbecapturedby(pair<int, int> p2){
	playerturn = abs(playerturn - 1);
	pair<int, int> p1;
	
	for (int j =0; j < 6; j++){
		for (int i = 0; i < 5; i++){
			if (TheBoard[i][j].getplayer() == playerturn){
				p1.first = i;
				p1.second = j;
				if (isvalid(p1, p2, 'a')){				//p2 can be captured
					playerturn = abs(playerturn - 1);
					return p1;							//return the position that would capture it
				}
			}
		}
	}
	playerturn = abs(playerturn - 1);					//p2 cannot be captured
	p1.first = -1;
	p1.second = -1;
	return p1;										//return bogus board position
}


//test function to make sure that a capturing move can be done and undone
void board::testmove(pair<int, int> p1, pair<int, int> p2){
	char a = 'a';
	display();
	pieces removedpiece;
	removedpiece = TheBoard[p2.first][p2.second];
	cout << "the piece at p2 is of type " << removedpiece.getpiecetypeint() << endl;
	move(p1,p2,a);
	display();
	playerturn = abs(playerturn - 1);
	move(p2,p1,a);
	display();
	playerturn = abs(playerturn - 1);
	removedpiece.move(p2.first,p2.second);
	TheBoard[p2.first][p2.second] = removedpiece;
		cout << "the piece at p2 is of type " << removedpiece.getpiecetypeint() << " and the board at p2 is "<< TheBoard[p2.first][p2.second].getpiecetypeint() << endl;
	display();
	
}

//Check if the game is a stalemate
//returns false if a piece can make a move
bool board::isstalemate(){
	pair<int,int> p;
	vector<pair<int, int> > v;
	for (int j =0; j < 6; j++){
		for (int i = 0; i < 5; i++){
			p.first = i;
			p.second = j;
			v = generatemoves(p, 'a');
			if (v.size() != 0){
				return false;
			}
		}
	}
	playerturn = abs(playerturn - 1);
	for (int j =0; j < 6; j++){
		for (int i = 0; i < 5; i++){
			p.first = i;
			p.second = j;
			v = generatemoves(p, 'a');
			if (v.size() != 0){
				playerturn = abs(playerturn - 1);
				return false;
			}
		}
	}
	playerturn = abs(playerturn - 1);	
	return true;
}

//test if there is a draw
//true if there have been 20+ moves without a capture, rescue, or promotion
bool board::isdraw(){
	return (moveswithoutcapture>=20);
}

//perform a rescue
//remove the pawn at position p1, replace it with piece c
void board::rescuepiece(pair<int, int> p1, char c){
	int piecetype;
	pieces tempp;
	pieces replacement;
	int vectorsize;
	int nextpos = 1;
	bool removed;
	
	if (playerturn == 1){			//because this happens after the move function, the playerturn has already change
		if (c == 'r' || c == 'R'){		//figure out what piece will be captured at set tempp as that piece
			tempp = wrp;
			TheBoard[p1.first][p1.second] = tempp;
			tempp.move(p1.first,p1.second);
			piecetype = 2;
		}
		else if (c == 'n' || c == 'N'){
			tempp = wnp;
			TheBoard[p1.first][p1.second] = tempp;
			tempp.move(p1.first,p1.second);
			piecetype = 3;
		}
		else if (c == 'b' || c == 'B'){
			tempp = wbp;
			TheBoard[p1.first][p1.second] = tempp;
			tempp.move(p1.first,p1.second);
			piecetype = 4;
		}
		else if (c == 'q' || c == 'Q'){
			for (int i = 0; i < pieceslost.size(); i++){		//different because there might be multiple queens
				if (pieceslost[i].getpiecetypeint() == 5){
					tempp = pieceslost[i];
				}
			}
			TheBoard[p1.first][p1.second] = tempp;
			tempp.move(p1.first,p1.second);
			piecetype = 5;
		}
		
		vectorsize = pieceslost.size();
		
		for (int x = 0; x < vectorsize; x++){			//go through the vector to remove it
			if (pieceslost[x].getpiecetypeint() == piecetype)		//the current piece in the vector is the one to be removed
				removed = true;										//so we know to start rewriting the vector
			
			if (removed){							//It's been removed, so...
				if (nextpos >= vectorsize)					//at the last position
					pieceslost.resize(pieceslost.size() - 1);		//so shrink down the vector by one
				else{										//it's not the last position
					tempp = pieceslost[nextpos];			//so set tempp to equal the next piece in the vector
					pieceslost[x] = tempp;					//and make it the current
				}
			}

		nextpos++;
		}
	}
	else{
		if (c == 'r' || c == 'R'){
			tempp = brp;
			TheBoard[p1.first][p1.second] = tempp;
			tempp.move(p1.first,p1.second);
			piecetype = 2;
		}
		else if (c == 'n' || c == 'N'){
			tempp = bnp;
			TheBoard[p1.first][p1.second] = tempp;
			tempp.move(p1.first,p1.second);
			piecetype = 3;
		}
		else if (c == 'b' || c == 'B'){
			tempp = bbp;
			TheBoard[p1.first][p1.second] = tempp;
			tempp.move(p1.first,p1.second);
			piecetype = 4;
		}
		else if (c == 'q' || c == 'Q'){
			tempp = bqp;
			TheBoard[p1.first][p1.second] = tempp;
			tempp.move(p1.first,p1.second);
			piecetype = 5;
		}
		
		vectorsize = enemiescaptured.size();
		
		for (int x = 0; x < vectorsize; x++){
			if (enemiescaptured[x].getpiecetypeint() == piecetype)
				removed = true;
			
			if (removed){
				if (nextpos >= vectorsize)
					enemiescaptured.resize(enemiescaptured.size() - 1);
				else{
					tempp = enemiescaptured[nextpos];
					enemiescaptured[x] = tempp;
				}
			}

		nextpos++;
		}
	}
		
}

//a promotion is possible
bool board::ispromotion(pair<int, int> p1){
	if (playerturn == 0){			//check if the the curret player's position to move to
		if (p1.second != 0)		//is at the end of the board for that player
			return false;
		for (int i = 0; i < pieceslost.size(); i++){		//make sure there's nothing else in the captured vector
			if (pieceslost[i].getpiecetypeint() != 1){			//except pawns
				return false;
			}
		}
	}
	else{							//same but for opposing player
		if (p1.second != 5)
			return false;
		for (int i = 0; i < enemiescaptured.size(); i++){
			if (enemiescaptured[i].getpiecetypeint() != 1){
				return false;
			}
		}
	}
	return true;
}

//promote piece at position p1
void board::promotepiece(pair<int, int> p1){
	pieces temp;
	temp = TheBoard[p1.first][p1.second];
	temp.move(-1,-1);					//move the pawn off the board
	
	queen * q1 = new queen;			//Create a new queen
	pieces q1p;						//and a piece to point at it
	q1p.set(q1);
	
	q1p.setplayer(abs(playerturn-1));		//set the queen to the current player, switched as this occurs after move function
	q1p.move(p1.first,p1.second);			//make the piece know where it is on the board
	TheBoard[p1.first][p1.second] = q1p;	//make the board know where the piece should be
}

#endif