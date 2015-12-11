/*
Author: Jinu Jacob
jj559@drexel.edu
Created: 10/21/15
Runs test for Sliding Brick Puzzle classes
*/

#ifndef _TEST_SUITE_
#define _TEST_SUITE_

#include "GameState.h"
#include "Move.h"
#include "Node.h"

using namespace std;

class TestSuite {

	public:
		// Constructor
		TestSuite();

		// Tests
		void testPrint(const GameState testState);
		void testCopyFunction(const GameState gSource);
		void testPuzzleSolved(const GameState testState);
		void testPieceMoves(const GameState testState);
		void testAllMoves(const GameState testState);
		void testApplyMove(const GameState testState);
		void testMoveClone(const GameState testState);
		void compareState(const GameState testState, const GameState compareState);
		void testNormalize(const GameState testState);

		void testRandomWalk(const GameState testState);
		void testBFS(const GameState testState);
		void testDFS(const GameState testState);





};

#endif
