Author: Jinu Jacob
jj559@drexel.edu
Created: 10/15
CS 380 HW3
Sliding Brick Puzzle A* Search


---------------------------------------------------------------------------------

SUMMARY
---------------------------------------------------------------------------------
This program implements A* star search using a Manhattan distance heuristic
and a slightly better heuristic discussed below. 
This program was written in vim and tested on Drexel's tux server.
This program outputs: 
- start state
- number of nodes explored
- moves to the solution
- solved puzzle
- time taken
- solution length

---------------------------------------------------------------------------------

HOW TO RUN

Run using one of the make commands:

"make" - compiles and runs main.cpp; will prompt user for a puzzle file(please 
specify folder in path as well). The default heuristic will be used(Manhattan Distance)

"make target1=inputFile" - will solve puzzle file. Default heuristic used.

"make target1=inputFile target2=-h" - will use Blocker heuristic.


To compile separately use g++ main.cpp
To run: a.out <file name> [option]

Options:
"-h" - Uses blockers heuristic
If no option is provided the default option will be used. 


---------------------------------------------------------------------------------

HEURISTICS
---------------------------------------------------------------------------------
Manhattan Distance - The h score is calculated by getting the distance
between the master piece and the goal. The distance represents the number of
moves it would take to get to the goal if the board was empty.This is done 
by the getDistance function which averages the distance between each master 
piece position and each goal position. For every provided puzzle it has 
returned the correct Manhattan distance. 

Blockers Hueristic - This heuristic is slightly better than Manhattan
distance and is still admissible. It counts the number of pieces that are in
between the master piece and the goal and adds it to the Manhattan distance.
This will never overestimate the actual cost to the goal because a cost always 
exists for each piece that must be moved out of the way. It is better than 
Manhattan distance because it is closer to the actual cost. This heuristic 
slightly reduces the amount of nodes explored and the time taken. 

---------------------------------------------------------------------------------

IMPLEMENTATION NOTES
---------------------------------------------------------------------------------
Node class - this class contains a gameState, a pointer to its parent Node,
the Move that resulted in the Node, and f, g, and h scores. 

Hash function - nodeHash() creates a unique key using the values of a game
board. This greatly reduces the time for comparing duplicate Nodes. Further
details can be found in Node.cpp.

A* algorithm - Like BFS and DFS, A* uses a hash map for the open and
closed lists. The keys are unique strings provided by the nodeHash function.

Unfortunately the hash map does not store nodes in order of their f scores.
To avoid having to sort the open list every time a node is added, another
map with an integer key and vector<string> value is used to keep track of
Nodes by their f score:

map<int, vector<string>> openListKeys:
			
			KEY:			VALUE:
			F score		Key to Node in open list

			[0]------->[122111034110001]
						  [122111340110001]
						  [122111030110041]
	
			[1]------->[1-1-1111223110041]
						  [1-1-1111223110401]

			[2]------->[1-1-1111034112201]
						  [1-1-1111030112241]

C++ maps are ordered by their keys. This works perfectly for tracking nodes
by their f score. When a node is added to the open list, its hash string is
stored in openListKeys map according to its f score. To get the element with 
the lowest f score we just pop the first element off the map. This will give
the key to that node in the open list.

After getting the Node with the lowest f score it is removed from the open
list and added to the closed list. We check to see if it the goal state. 
This is done directly after to ensure that the goal Node is the Node with 
the lowest f score on the open list. 
							
If the Node is not the goal all its children all generated. When Nodes are
generated they are immediately normalized and their f scores are set. The g
score is their parents g score + 1 and their h score is calculated by a
heuristic function. 
- If they are already on the closed lists they are ignored. 
- If they are on the open list but have a worst f score then they are ignored.
- If they have a better f score they replace the same node on the open list and 
  we update the entries in openListKeys. 
- If the child is not in the open list we add it to the open list and add
  its hash to openListKeys.

When a solution is found we walk backwards using the parent Node pointers
and add each Node to a solution vector. Memory dynamically allocated for
Nodes is freed and we return the solution.

If no solution is found an empty vector is returned.

