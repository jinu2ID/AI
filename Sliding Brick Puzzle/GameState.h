/*
Created: 9/23/15
Author: Jinu Jacob
game state class for Sliding Brick Puzzle
*/

#ifndef _GAME_STATE_
#define _GAME_STATE_

#include <fstream>
#include <vector>
#include <string>
#include "Move.h"

using namespace std;

class GameState {


public:
	//Constructors
	GameState();
	GameState(vector< vector<int> > _matrix);
	GameState(const GameState& obj);           //Copy constructor
		
	//Inspectors
	void printState();
	bool checkSolved();
	vector<Move> getMoves(int piece);
	vector <vector<Move> > getAllMoves();
	vector<Move> getAllMovesV2();
	bool compareState(const GameState otherState);
	int getDistance(int piece1, int piece2);
	int getBlocked(int piece1, int piece2);

	//Mutators
	void changeValue(int row, int column, int newValue);
	void applyMove(Move move);
	GameState applyMoveCloning(Move move);
	void normalizeState();
	void swapIdx(int idx1, int idx2);
	void randomWalk(int n);
	
	// Overload operators
	GameState& operator= (const GameState &gSource);
	friend bool operator== (const GameState &g1, const GameState &g2);

	// Getters
	vector< vector<int> > getBoard();

private:
	int width;
	int height;
	vector<vector<int> > board;	// 2D vector to hold game state
};

// Overloaded Operators

bool operator== (const GameState &g1, const GameState &g2){
	return g1.board == g2.board;
}
GameState& GameState::operator= (const GameState &gSource){

	// Copy
	width = gSource.width;
	height = gSource.height;
	board = gSource.board;

	return *this;

}

#endif
