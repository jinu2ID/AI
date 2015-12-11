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
	GameState(vector< vector<int> > _matrix);
	GameState(const GameState& obj);           //Copy constructor
		
	//Inspectors
	void printState();
	bool checkSolved();
	vector<Move> getMoves(int piece);
	vector <vector<Move> > getAllMoves();
	vector<Move> getAllMovesV2();
	bool compareState(GameState otherState);

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

private:
	int width;
	int height;
	vector<vector<int> > board;	// 2D vector to hold game state
};

// Operator

bool operator== (const GameState &g1, const GameState &g2){
	return g1.board == g2.board;
}
GameState& GameState::operator= (const GameState &gSource){
   
	// Check for self-assignment
	if (this == &gSource);
		return *this;

	// Copy
	width = gSource.width;
	height = gSource.height;
	board = gSource.board;

	return *this;

}

#endif
