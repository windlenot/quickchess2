

#ifndef QUEEN_H
#define QUEEN_H

#include "pieces.h"

class queen : public piecesbody{
public:
	queen();
	~queen();
	
	void move(int newx, int newy);
	
};

queen::queen(){
	setpiecetypeint(5);	
}

queen::~queen(){
	
}

void queen::move(int newx, int newy){
	setx(newx);
	sety(newy);
}

#endif