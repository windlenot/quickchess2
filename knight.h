

#ifndef KNIGHT_H
#define KNIGHT_H

#include "pieces.h"

class knight : public piecesbody{
public:
	knight();
	~knight();
	
	void move(int newx, int newy);
	
};

knight::knight(){
	setpiecetypeint(3);	
}

knight::~knight(){
	
}

void knight::move(int newx, int newy){
	setx(newx);
	sety(newy);
}

#endif