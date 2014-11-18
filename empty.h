

#ifndef EMPTY_H
#define EMPTY_H

#include "pieces.h"

class empty : public piecesbody{
public:
	empty();
	~empty();
	
	void move(int newx, int newy);
	
};

empty::empty(){
	setpiecetypeint(0);
}

empty::~empty(){
	
}

void empty::move(int newx, int newy){
	setx(newx);
	sety(newy);
}

#endif