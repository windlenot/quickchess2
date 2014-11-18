//handle class of pieces

#ifndef PIECES_H
#define PIECES_H

#include "piecesbody.h"

class pieces{
public:
	pieces();
	pieces(piecesbody * piecetype);
	~pieces();
	
	void move(int newx, int newy);
	
	void set(piecesbody * piecetype);
	
	int getx();
	int gety();
	int getplayer();
	void setplayer(int n);
	void setx(int newx);
	void sety(int newy);
	
	int getpiecetypeint();
	void setpiecetypeint(int n);
	
private:
	piecesbody* p;
};

pieces::pieces(){
	p = NULL;
}

pieces::pieces(piecesbody * piecetype){
	p = piecetype;
}

pieces::~pieces(){
	p = NULL;
}
	
	
void pieces::move(int newx, int newy){
	p->move(newx, newy);
}

void pieces::set(piecesbody * piecetype){
	p = piecetype;
}

int pieces::getx(){
	return p->getx();
}

int pieces::gety(){
	return p->gety();
}

int pieces::getplayer(){
	return p->getplayer();
}

void pieces::setplayer(int n){
	p->setplayer(n);
}

void pieces::setx(int newx){
	p->setx(newx);
}

void pieces::sety(int newy){
	p->sety(newy);
}
	
int pieces::getpiecetypeint(){
	return p->getpiecetypeint();
}

void pieces::setpiecetypeint(int n){
	p->setpiecetypeint(n);
}

#endif
