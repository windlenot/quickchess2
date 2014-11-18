

#ifndef KING_H
#define KING_H

#include "pieces.h"

class king : public piecesbody{
public:
	king();
	~king();
	
	void move(int newx, int newy);
	
};

king::king(){
	setpiecetypeint(6);	
}

king::~king(){
	
}

void king::move(int newx, int newy){
	setx(newx);
	sety(newy);
}

#endif