/* 
Created: 9/26/15
Author: Jinu Jacob
A move class for the Sliding Brick Puzzle
*/

#ifndef _MOVE_
#define _MOVE_

using namespace std;
 

class Move{

	public:
		//Constructors
		Move();
		Move(int value, char _direction);
		Move(const Move &mSource);		
		//Inspectors
		void printMove();
		int getPiece();
		char getDirection();
		
		// Overload operators
		friend bool operator== (const Move &m1, const Move &m2);
		Move& operator= (const Move &mSource);

	private:
		int piece;
		char direction;


};

bool operator== (const Move &m1, const Move &m2){
	return ((m1.piece == m2.piece) and (m1.direction == m2.direction));
}

Move& Move::operator= (const Move &mSource){
	// Check for self-assignment
	if(this == &mSource)
		return *this;

	// Copy
	piece = mSource.piece;
	direction = mSource.direction;

	return *this;
}

#endif
