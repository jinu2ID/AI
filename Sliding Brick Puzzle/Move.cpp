/*
Author: Jinu Jacob
Created: 9/27/15
Move class for Sliding Brick Puzzle
*/

#include <stdio.h>
#include "Move.h"

using namespace std;

//Constructors
Move::Move(){
	piece = 0;
	direction = '0';
}

Move::Move(int value, char _direction){

	piece = value;
	direction = _direction;
}

Move::Move(const Move &mSource){
	
	piece = mSource.piece;
	direction = mSource.direction;
}

//Inspectors
void Move::printMove(){
	if(direction == 'u')
	  cout << "(" << piece << ", up)" << endl;	
	else if (direction == 'd')
		cout << "(" << piece << ", down)" << endl;
	else if (direction == 'l')
		cout << "(" << piece << ", left)" << endl;
	else if (direction == 'r')
		cout << "(" << piece << ", right)" << endl;
	else if (direction == '0')
		cout << "Start State" << endl;
	else
		cout << "direction " << direction << " unrecognized" << endl;
}

int Move::getPiece(){
	return piece;
}

char Move::getDirection(){
	return direction;
}
