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
	void move(pair <int,int> p1, pair <int,int> p2);
	pieces getpiece(pair<int, int> d);
	void display();
	bool isempty(pair<int, int> d);
	void startingmove(int n);
	int getplayer();
	bool isvalid(pair <int,int> p1, pair <int,int> p2);
	
	vector<pair <int, int> > generatemoves(pair <int,int> p1);
	bool isinvector(vector<pair <int, int> > v,pair <int,int> p1);
	
	//for solve class
	bool ischeckmate();
	bool ispromotion();
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

//move pieces
void board::move(pair<int, int> p1, pair<int, int> p2){

	if (!isvalid(p1,p2)){
		while(!isvalid(p1,p2)){
			cout << "Invalid move." << endl << endl;
			
			cout << "	first X: ";
			cin >> get<0>(p1);
			cout << "	first Y: ";
			cin >> 	get<1>(p1);
			cout << "	second X: ";
			cin >> get<0>(p2);
			cout << "	second Y: ";
			cin >> get<1>(p2);
		}
	}
	cout << endl;
	if (TheBoard[get<0>(p2)][get<1>(p2)].getplayer() != 2){
		if (TheBoard[get<0>(p2)][get<1>(p2)].getplayer() == 0){
			pieceslost.push_back(TheBoard[get<0>(p2)][get<1>(p2)]);
			moveswithoutcapture = -1;
		}
		else{
			enemiescaptured.push_back(TheBoard[get<0>(p2)][get<1>(p2)]);
			moveswithoutcapture = -1;
		}
	}
	
	pieces movepiece;
	movepiece = TheBoard[get<0>(p1)][get<1>(p1)];
	TheBoard[get<0>(p1)][get<1>(p1)] = empp;		//Previous piece position is now empty
	movepiece.move(get<0>(p2), get<1>(p2));			//make the piece know its new position
	TheBoard[get<0>(p2)][get<1>(p2)] = movepiece;	//make the board know where the piece is
	
	moveswithoutcapture++;
	
	playerturn = abs(playerturn - 1);

}

//see if a spot is empty
bool board::isempty(pair<int, int> d){
	if (TheBoard[get<0>(d)][get<1>(d)].getpiecetypeint() == 0)
		return true;
	else
		return false;
}

//Given a position, return the piece
pieces board::getpiece(pair <int, int> d){
	return TheBoard[get<0>(d)][get<1>(d)];
}

//print out the board
void board::display(){
	for (int j = 0; j < 6; j++){
		for (int i = 0; i < 5; i++){
			if (TheBoard[i][j].getpiecetypeint() == 1){
				if (TheBoard[i][j].getplayer() == 0)
					cout << "WP ";
				else
					cout << "BP ";
			}
			else if (TheBoard[i][j].getpiecetypeint() == 2){
				if (TheBoard[i][j].getplayer() == 0)
					cout << "WR ";
				else
					cout << "BR ";
			}
			else if (TheBoard[i][j].getpiecetypeint() == 3){
				if (TheBoard[i][j].getplayer() == 0)
					cout << "WN ";
				else
					cout << "BN ";
			}
			else if (TheBoard[i][j].getpiecetypeint() == 4){
				if (TheBoard[i][j].getplayer() == 0)
					cout << "WB ";
				else
					cout << "BB ";
			}
			else if (TheBoard[i][j].getpiecetypeint() == 5){
				if (TheBoard[i][j].getplayer() == 0)
					cout << "WQ ";
				else
					cout << "BQ ";
			}
			else if (TheBoard[i][j].getpiecetypeint() == 6){
				if (TheBoard[i][j].getplayer() == 0)
					cout << "WK ";
				else
					cout << "BK ";
			}
			else
				cout << "    ";
		}
		cout << endl;
	}
}


bool board::isvalid(pair <int,int> p1, pair <int,int> p2){
	if (get<0>(p1) < 0 || get<1>(p1) < 0 || get<0>(p2) < 0 || get<1>(p2) < 0)
		return false;
	if (p1 == p2)
		return false;
	
	vector<pair<int, int> > v;
	int piecenum = TheBoard[get<0>(p1)][get<1>(p1)].getpiecetypeint();
	int curplayer = TheBoard[get<0>(p1)][get<1>(p1)].getplayer();
	if (curplayer != playerturn)
		return false;
	
	if (piecenum == 0)
		return false;
	else if (piecenum == 1){
		if (curplayer == 0){
			if (get<1>(p1) - get<1>(p2) == 1){
				if (get<0>(p1) == get<0>(p2)){
					if (TheBoard[get<0>(p2)][get<1>(p2)].getpiecetypeint() == 0)
						return true;
				}
				else if(abs(get<0>(p1) - get<0>(p2)) == 1)
					if (TheBoard[get<0>(p2)][get<1>(p2)].getplayer() == 1)
						return true;
			}
			return false;		
		}
		else{
			if (get<1>(p2) - get<1>(p1) == 1){
				if (get<0>(p1) == get<0>(p2)){
					if (TheBoard[get<0>(p2)][get<1>(p2)].getpiecetypeint() == 0)
						return true;
				}
				else if(abs(get<0>(p1) - get<0>(p2)) == 1)
					if (TheBoard[get<0>(p2)][get<1>(p2)].getplayer() == 0)
						return true;
			}
			return false;		
		}
	}
	else if (piecenum == 2){
		v = generatemoves(p1);
		return (isinvector(v,p2));
	}
	else if (piecenum == 3){
		v = generatemoves(p1);
		return (isinvector(v,p2));
	}
	else if (piecenum == 4){
		v = generatemoves(p1);
		return (isinvector(v,p2));
	}
	else if (piecenum == 5){
		v = generatemoves(p1);
		return (isinvector(v,p2));
	}
	else if (piecenum == 6){
		if ((abs(get<0>(p1) - get<0>(p2))) >1 || (abs(get<1>(p1) - get<1>(p2)) > 1))
			return false; 
		if (TheBoard[get<0>(p2)][get<1>(p2)].getplayer() == playerturn)
			return false;
		return true;
		}
	return true;
}

vector<pair<int, int> > board::generatemoves(pair<int, int> p1){
	vector<pair<int, int> > v;
	v.resize(0);
	int localx = get<0>(p1);
	int localy = get<1>(p1);
	pair<int, int> p(localx, localy);
	if (TheBoard[get<0>(p1)][get<1>(p1)].getpiecetypeint() == 2){	//ROOK
		while (true){								//UP
			get<1>(p) = localy - 1;
			if (localy == 0)
				break;
			if (TheBoard[localx][localy - 1].getpiecetypeint() == 0)
				v.push_back(p);
			else{
				if (TheBoard[localx][localy - 1].getplayer() != playerturn)
					v.push_back(p);
				break;
			}
			localy--;
		}
		localy = get<1>(p1);
		get<0>(p) = get<0>(p1);
		get<1>(p) = get<1>(p1);
		while (true){								//DOWN
			get<1>(p) = localy + 1;
			if (localy == 5)
				break;
			if (TheBoard[localx][localy+1].getpiecetypeint() == 0)
				v.push_back(p);
			else{
				if (TheBoard[localx][localy+1].getplayer()!= playerturn)
					v.push_back(p);
				break;
			}
			localy++;
		}									//LEFT
		localy = get<1>(p1);
		get<0>(p) = get<0>(p1);
		get<1>(p) = get<1>(p1);
		while (true){
			get<0>(p) = localx - 1;
			if (localx == 0)
				break;
			if (TheBoard[localx - 1][localy].getpiecetypeint() == 0)
				v.push_back(p);
			else{
				if (TheBoard[localx - 1][localy].getplayer() != playerturn)
					v.push_back(p);
				break;
			}
			localx--;
		}					
		localx = get<0>(p1);
		get<0>(p) = get<0>(p1);
		get<1>(p) = get<1>(p1);	
		while (true){								//RIGHT
			get<0>(p) = localx + 1;
			if (localx == 4)
				break;
			if (TheBoard[localx + 1][localy].getpiecetypeint() == 0)
				v.push_back(p);
			else{
				if (TheBoard[localx + 1][localy].getplayer() != playerturn)
					v.push_back(p);
				break;
			}
			localx++;
		}
		localx = get<0>(p1);
	}
	localy = get<1>(p1);
	localx = get<0>(p1);
	get<0>(p) = get<0>(p1);
	get<1>(p) = get<1>(p1);
	
	if (TheBoard[get<0>(p1)][get<1>(p1)].getpiecetypeint() == 3){	//KNIGHT
		if (localy > 1){
			get<1>(p) = localy - 2;		//up
			if (localx >0){					//left
				get<0>(p) = localx - 1;
				if (TheBoard[get<0>(p)][get<1>(p)].getplayer() != playerturn)
					v.push_back(p);
			}
			get<0>(p) = get<0>(p1);
			if (localx <4){
				get<0>(p) = localx + 1;		//right
				if (TheBoard[get<0>(p)][get<1>(p)].getplayer() != playerturn)
					v.push_back(p);
			}
		}
		if (localy < 4){					//down
			get<1>(p) = localy + 2;
			if (localx >0){					//left
				get<0>(p) = localx - 1;
				if (TheBoard[get<0>(p)][get<1>(p)].getplayer() != playerturn)
					v.push_back(p);
			}
			get<0>(p) = get<0>(p1);
			if (localx <4){
				get<0>(p) = localx + 1;		//right
				if (TheBoard[get<0>(p)][get<1>(p)].getplayer() != playerturn)
					v.push_back(p);
			}
		}
		if (localx > 1){
			get<0>(p) = localx - 2;		//left
			if (localy >0){					//up
				get<1>(p) = localy - 1;
				if (TheBoard[get<0>(p)][get<1>(p)].getplayer() != playerturn)
					v.push_back(p);
			}
			get<0>(p) = get<0>(p1);
			if (localy <5){
				get<1>(p) = localy + 1;		//down
				if (TheBoard[get<0>(p)][get<1>(p)].getplayer() != playerturn)
					v.push_back(p);
			}
		}
		if (localx < 3){					//right
			get<0>(p) = localx + 2;
			if (localy >0){					//up
				get<1>(p) = localy - 1;
				if (TheBoard[get<0>(p)][get<1>(p)].getplayer() != playerturn)
					v.push_back(p);
			}
			get<0>(p) = get<0>(p1);
			if (localy <5){
				get<1>(p) = localy + 1;		//down
				if (TheBoard[get<0>(p)][get<1>(p)].getplayer() != playerturn)
					v.push_back(p);
			}
		}
	
	}
	localy = get<1>(p1);
	localx = get<0>(p1);
	get<0>(p) = get<0>(p1);
	get<1>(p) = get<1>(p1);
	if (TheBoard[get<0>(p1)][get<1>(p1)].getpiecetypeint() == 4){	//BISHOP
		while (true){											//UP LEFT
			get<1>(p) = localy - 1;
			get<0>(p) = localx - 1;
			if (localy == 0 || localx == 0)
				break;
			if (TheBoard[localx - 1][localy - 1].getpiecetypeint() == 0)
				v.push_back(p);
			else{
				if (TheBoard[localx - 1][localy - 1].getplayer() != playerturn)
					v.push_back(p);
				break;
			}
			localy--;
			localx--;
		}
		localx = get<0>(p1);
		localy = get<1>(p1);
		get<0>(p) = get<0>(p1);
		get<1>(p) = get<1>(p1);
		while (true){									//DOWN LEFT
			get<1>(p) = localy + 1;
			get<0>(p) = localx - 1;
			if (localy == 5 || localx == 0)
				break;
			if (TheBoard[localx - 1][localy+1].getpiecetypeint() == 0)
				v.push_back(p);
			else{
				if (TheBoard[localx - 1][localy+1].getplayer()!= playerturn)
					v.push_back(p);
				break;
			}
			localy++;
			localx--;
		}
		localy = get<1>(p1);
		localx = get<0>(p1);
		get<0>(p) = get<0>(p1);
		get<1>(p) = get<1>(p1);
		while (true){					//UP RIGHT
			get<0>(p) = localx + 1;
			get<1>(p) = localy - 1;
			if (localx == 4|| localy == 0)
				break;
			if (TheBoard[localx + 1][localy - 1].getpiecetypeint() == 0)
				v.push_back(p);
			else{
				if (TheBoard[localx + 1][localy - 1].getplayer() != playerturn)
					v.push_back(p);
				break;
			}
			localx++;
			localy--;
		}
		localx = get<0>(p1);
		localy = get<1>(p1);
		get<0>(p) = get<0>(p1);
		get<1>(p) = get<1>(p1);
		while (true){					//DOWN RIGHT
			get<0>(p) = localx + 1;
			get<1>(p) = localy + 1;
			if (localx == 4 || localy == 5)
				break;
			if (TheBoard[localx + 1][localy + 1].getpiecetypeint() == 0)
				v.push_back(p);
			else{
				if (TheBoard[localx + 1][localy + 1].getplayer() != playerturn)
					v.push_back(p);
				break;
			}
			localx++;
			localy++;
		}
	}
	if (TheBoard[get<0>(p1)][get<1>(p1)].getpiecetypeint() == 5){	//QUEEN
		while (true){											//UP LEFT
			get<1>(p) = localy - 1;
			get<0>(p) = localx - 1;
			if (localy == 0 || localx == 0)
				break;
			if (TheBoard[localx - 1][localy - 1].getpiecetypeint() == 0)
				v.push_back(p);
			else{
				if (TheBoard[localx - 1][localy - 1].getplayer() != playerturn)
					v.push_back(p);
				break;
			}
			localy--;
			localx--;
		}
		localx = get<0>(p1);
		localy = get<1>(p1);
		get<0>(p) = get<0>(p1);
		get<1>(p) = get<1>(p1);
		while (true){									//DOWN LEFT
			get<1>(p) = localy + 1;
			get<0>(p) = localx - 1;
			if (localy == 5 || localx == 0)
				break;
			if (TheBoard[localx - 1][localy+1].getpiecetypeint() == 0)
				v.push_back(p);
			else{
				if (TheBoard[localx - 1][localy+1].getplayer()!= playerturn)
					v.push_back(p);
				break;
			}
			localy++;
			localx--;
		}
		localy = get<1>(p1);
		localx = get<0>(p1);
		get<0>(p) = get<0>(p1);
		get<1>(p) = get<1>(p1);
		while (true){					//UP RIGHT
			get<0>(p) = localx + 1;
			get<1>(p) = localy - 1;
			if (localx == 4|| localy == 0)
				break;
			if (TheBoard[localx + 1][localy - 1].getpiecetypeint() == 0)
				v.push_back(p);
			else{
				if (TheBoard[localx + 1][localy - 1].getplayer() != playerturn)
					v.push_back(p);
				break;
			}
			localx++;
			localy--;
		}
		localx = get<0>(p1);
		localy = get<1>(p1);
		get<0>(p) = get<0>(p1);
		get<1>(p) = get<1>(p1);
		while (true){					//DOWN RIGHT
			get<0>(p) = localx + 1;
			get<1>(p) = localy + 1;
			if (localx == 4 || localy == 5)
				break;
			if (TheBoard[localx + 1][localy + 1].getpiecetypeint() == 0)
				v.push_back(p);
			else{
				if (TheBoard[localx + 1][localy + 1].getplayer() != playerturn)
					v.push_back(p);
				break;
			}
			localx++;
			localy++;
		}
	localy = get<1>(p1);
	localx = get<0>(p1);
	get<0>(p) = get<0>(p1);
	get<1>(p) = get<1>(p1);
		while (true){						//UP
			get<1>(p) = localy - 1;
			if (localy == 0)
				break;
			if (TheBoard[localx][localy - 1].getpiecetypeint() == 0)
				v.push_back(p);
			else{
				if (TheBoard[localx][localy - 1].getplayer() != playerturn)
					v.push_back(p);
				break;
			}
			localy--;
		}
		localy = get<1>(p1);
		get<0>(p) = get<0>(p1);
		get<1>(p) = get<1>(p1);
		while (true){						//DOWN
			get<1>(p) = localy + 1;
			if (localy == 5)
				break;
			if (TheBoard[localx][localy+1].getpiecetypeint() == 0)
				v.push_back(p);
			else{
				if (TheBoard[localx][localy+1].getplayer()!= playerturn)
					v.push_back(p);
				break;
			}
			localy++;
		}
		localy = get<1>(p1);
		get<0>(p) = get<0>(p1);
		get<1>(p) = get<1>(p1);
		while (true){						//LEFT
			get<0>(p) = localx - 1;
			if (localx == 0)
				break;
			if (TheBoard[localx - 1][localy].getpiecetypeint() == 0)
				v.push_back(p);
			else{
				if (TheBoard[localx - 1][localy].getplayer() != playerturn)
					v.push_back(p);
				break;
			}
			localx--;
		}									//RIGHT
		localx = get<0>(p1);
		get<0>(p) = get<0>(p1);
		get<1>(p) = get<1>(p1);
		while (true){
			get<0>(p) = localx + 1;
			if (localx == 4)
				break;
			if (TheBoard[localx + 1][localy].getpiecetypeint() == 0)
				v.push_back(p);
			else{
				if (TheBoard[localx + 1][localy].getplayer() != playerturn)
					v.push_back(p);
				break;
			}
			localx++;
		}
		localx = get<0>(p1);
	}
	return v;
}

bool board::isinvector(vector<pair <int, int> > v,pair <int,int> p1){
	for (int i = 0; i < v.size(); i++){
		if (v[i] == p1)
			return true;
	}
	return false;
}

#endif