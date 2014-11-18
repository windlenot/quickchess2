//Quickchess
//Base pieces class used for inheritence by actual piece types

#ifndef PIECESBODY_H
#define PIECESBODY_H

class piecesbody{
public:
	piecesbody();
	~piecesbody();
	
	virtual void move(int newx, int newy) = 0;
	
	int getx();
	int gety();
	int getplayer();
	void setplayer(int n);
	void setx(int newx);
	void sety(int newy);
	
	int getpiecetypeint();
	void setpiecetypeint(int n);
	
private:
	int x;
	int y;
	int player;
	int piecetype;
};

piecesbody::piecesbody(){
}

piecesbody::~piecesbody(){
	
}

void move(int newx, int newy){
	
}

int piecesbody::getx(){
	return x;
}

int piecesbody::gety(){
	return y;
}

void piecesbody::setplayer(int n){
	player = n;
}

int piecesbody::getplayer(){
	return player;
}

void piecesbody::setx(int newx){
	x = newx;
}

void piecesbody::sety(int newy){
	y = newy;
}

int piecesbody::getpiecetypeint(){
	return piecetype;
}

void piecesbody::setpiecetypeint(int num){
	piecetype = num;
}

#endif