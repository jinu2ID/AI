/*
Author: Jinu Jacob
jj559@drexel.edu
Created: 10/21/15
*/


#include "TestSuite.h"
#include "GameState.h"

void TestSuite::testPrint(const GameState testState){
	
	cout << "Print Function Test" << endl;
	testState.printState();
	cout << endl;
}

void TestSutie::testCopyFunction(const GameState gSource){

	cout << "Copy Function Test" << endl;
	GameState copy(gSource);

	copy.changeValue(0,0,100);

	cout << "Changed Copy" << endl;
	copy.printState();
	cout << "Original Unchanged" << endl;
	gSource.printState();
	cout << endl;
}

void TestSuite::PuzzleSolved(const GameState testState){
	cout << "Puzzle Solved Function Test" << endl;
	if (testState.checkSolve())
		cout << "Solved!" << endl;
	else
		cout << "Not Solved!" << endl;
	cout << endl;

}

void TestSuite::testPieceMoves(const GameState testState){

	cout << "Get Piece's Move Function Test" << endl << "Enter piece" <<
		endl;
	int piece;
	cin >> piece;
	vector<Move> moves = testState.getMoves(piece);

	if (moves.size() == 0)
		cout << "No moves" << endl;
	else {
		int i;
		for (i = 0; i < moves.size(); i++){
			moves[i].printMove();
		}
	}
	cout << endl;

}

void TestSuite::testAllMoves(const GameState testState){
	
	cout << "Get All Moves Function Test" << endl;;
	vector <vector<Move> > allMoves = myGame.getAllMovesV2();
	
	int i;
	for (i = 0; i < allMoves.size(); i++)
		allMoves[i].printMove();

};

void TestSuite::testApplyMoves(const GameState testState){
	
	cout << "Apply Move Function Test" << endl << "Enter piece" << endl;
	cin >> piece;
	cout << "Enter direction: u d l r" << endl;
   char dir;
   cin >> dir;
   Move newMove(piece, dir);
   testState.applyMove(newMove);
   testState.printState();
   cout << endl;

}

void TestSuite::testMoveClone(const GameState testState){

	cout << "Apply Move Cloning Test" << endl << "Enter piece" << endl;
   cin >> piece;
   cout << "Enter direction: u d l r" << endl;
   cin >> dir;
   Move newMove(piece, dir);
   GameState cloneState = testState.applyMoveCloning(newMove);
   cloneState.printState();
   cout << endl;

}

void TestSuite::compareState(const GameState testState, const GameState
		compareState){

	cout << "Compare States Function Test" << endl;
   bool same = testState.compareState(compareState);
   cout << ( same ? "Same" : "Not Same") << endl;
   GameState copyState(testState);
   same = myGame.compareState(copyState);
   cout << "Comparing to a copy of original game state" << endl;
   cout << ( same ? "Same" : "Not Same") << endl;
   cout << endl;

}

void TestSuite::testNormalize(const GameState testState){

	cout << "Normalize State Function Test" << endl;
   myGame.normalizeState();
   myGame.printState();
   cout << endl;				

}

// Test search functions
void TestSuite::testRandomWalk(const GameState testState){

	cout << "Random Walk Function Test" << endl << "Enter a number" << endl;
   int n;
	cin >> n;
   myGame.randomWalk(n);

}

void TestSuite::testBFS(const GameState testState){

}

void TestSuite::testDFS(const GameState teststate){

}

