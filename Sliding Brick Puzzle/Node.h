/*
Created: 10/18/15
Author: Jinu Jacob
jj559@drexel.edu
node class for Sliding Brick Puzzle
This class will be used to perform searches such as BFS amd DFS
*/

#ifndef _NODE_
#define _NODE_

#include <string> 
#include "GameState.h"

using namespace std;

class Node{

	public:
		// Constructor
		Node();
		Node(GameState _state);
		Node(GameState _state, Node *_parent);
		Node(GameState _state, Node *_parent, Move _parentMove);
		Node(GameState _state, Node *_parent, Move _parentMove, int _g);
		Node(const Node & nSource);    // Copy Constructor

		// Inspectors
		bool compareNode(const Node otherNode);
		bool checkSolved();
		void printNode();
		int getFScore();
		int getGScore();

		// Access
		GameState getState();
		Node* getParent();

		// Overload operators
		friend bool operator== (const Node &n1, const Node &n2);
		Node& operator= (const Node &nSource);
		

		string hashNode();
		void setGScore();
		void setH1Score();
		void setH2Score();
		void setFScore();
		void setScores();
		void setScoresH2();

	private:
		GameState state;
		Node *parent;
		Move parentMove;
		int f,g,h;


};

bool operator== (const Node &n1, const Node &n2){
	return (n1.state == n2.state);
}

Node& Node::operator= (const Node &nSource){
	state = nSource.state;
	parent = nSource.parent;
	parentMove = nSource.parentMove;
	f = nSource.f;
	g = nSource.g;
	h = nSource.h;
}

#endif
