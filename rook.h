

#ifndef ROOK_H
#define ROOK_H

#include "pieces.h"

class rook : public piecesbody{
public:
	rook();
	~rook();
	
	void move(int newx, int newy);
	
};

rook::rook(){
	setpiecetypeint(2);	
}

rook::~rook(){
	
}

void rook::move(int newx, int newy){
	setx(newx);
	sety(newy);
}

#endif