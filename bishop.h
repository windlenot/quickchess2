

#ifndef BISHOP_H
#define BISHOP_H

#include "pieces.h"

class bishop : public piecesbody{
public:
	bishop();
	~bishop();
	
	void move(int newx, int newy);
	
};

bishop::bishop(){
	setpiecetypeint(4);	
}

bishop::~bishop(){
	
}

void bishop::move(int newx, int newy){
	setx(newx);
	sety(newy);
}

#endif