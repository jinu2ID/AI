/* 
Created: 10/18/15
Author: Jinu Jacob
jj559@drexel.edi
node class implementation for Sliding Brick Puzzle
*/

#include <vector>
#include <string>
#include <iostream>
#include "Node.h"
#include "GameState.h"

using namespace std;

// Constructors
Node::Node(){

	state = GameState();
	parent = NULL;
	parentMove = Move();
	g = 0;
}

Node::Node(GameState _state){

	state = _state;
	parent = NULL;
	parentMove = Move();
	g = 0;
}

Node::Node(GameState _state, Node *_parent){

	state = _state;
	parent = _parent;
	parentMove = Move();
	g = 0;
}

Node::Node(GameState _state, Node *_parent, Move _parentMove){
	
	state = _state;
	parent = _parent;
	parentMove = _parentMove;
	g = 0;
}

Node::Node(GameState _state, Node *_parent, Move _parentMove, int _g){
	
	state = _state;
	parent = _parent;
	parentMove = _parentMove;
	g = _g;
}

// Copy Constructor
Node::Node(const Node &nSource){
	state = nSource.state;
	parent = nSource.parent;
	parentMove = nSource.parentMove;
	f = nSource.f;
	g = nSource.g;
	h = nSource.h;
}

// Inspectors
bool Node::checkSolved(){

	return state.checkSolved();
}
bool Node::compareNode(const Node otherNode){
	if (state == otherNode.state)
		return true;
	else
		return false;
}

void Node::printNode(){
	
	parentMove.printMove();
	state.printState();
	cout << "F:" << f << " G:" << g << " H:" << h << endl;
}

int Node::getFScore(){
	return f;
}

int Node::getGScore(){
	return g;
}
// Accessors
GameState Node::getState(){
	return state;
}

Node* Node::getParent(){
	return parent;
}

// Creates a hash from a gameState by converting the 2D vector to a single
// string
string Node::hashNode(){

	string hash;   // Stores hash
	vector< vector<int> > state = this->getState().getBoard();

	int i,j;
	for ( i = 0; i < state.size(); i++){									// [#1]
		for (j = 0; j < state[i].size(); j++){
			// Convert number to string and append to hash string
			int number = state[i][j];
			string numberStr = static_cast<ostringstream*>( &(ostringstream()
						<< number) )->str();
			hash.append(numberStr);
		}
	}
	return hash;
}

// [#1] To create a unique hash this function takes the values in a matrix
// and turns them into a one line string. So for the following matrix:
//
//			1 2 3 
//       4 5 6     ----[ nodeHash()]------>  "123456789012" 
//       7 8 9
//       0 1 2
//       
// Of course a 3 X 4 matrix with the same values in the same order would 
// return the same hash, but for our sliding brick puzzles the dimensions 
// of the board stay the same (even if we did have have to deal with changing 
// dimensions we could tag the height and width to the hash to ensure 
// that it was unique). Therefore any two game states will return the same
// hash.

// Sets g(n) for node by adding +1 to the parent nodes g score
void Node::setGScore(){
	
	if (parent == NULL)
		g = 0;
	else	
		g = parent->g + 1;
}

// Sets h(n) for node using heuristic 1 which is Manhattan distance
void Node::setH1Score(){

	// Get average of distance between goals and pieces
	int distance = state.getDistance(2,-1);

	// Set h = avg distance
	h = distance;
}

// Adds number of blocker to Manhattan distance
void Node::setH2Score(){

	// Get distance between goals and pieces and number of blockers
	int distance = state.getDistance(2,-1);
	int blockers = state.getBlocked(2,-1);

	h = distance + blockers;
}

// f(n) = g(n) + h(n)
void Node::setFScore(){
	f = g + h;
}

// Set f(n) and h(n)
void Node::setScores(){
	this->setH1Score();
	this->setFScore();
}

// Set scores using H2 heuristic
void Node::setScoresH2(){
	this->setH2Score();
	this->setFScore();
}
