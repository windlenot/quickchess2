

#ifndef PAWN_H
#define PAWN_H

#include "piecesbody.h"

class pawn : public piecesbody{
public:
	pawn();
	~pawn();
	
	void move(int newx, int newy);
	
};

pawn::pawn(){
	setpiecetypeint(1);
}

pawn::~pawn(){
	
}

void pawn::move(int newx, int newy){
	setx(newx);
	sety(newy);
}

#endif