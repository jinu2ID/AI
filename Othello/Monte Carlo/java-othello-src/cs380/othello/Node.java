package cs380.othello;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * Created by jinuj on 11/20/2015.
 */
public class Node {

    private OthelloState state;
    private Node parent;
    private List<Node> children;
    private OthelloMove parentMove;
    int nVisited, avgScore;

    // Constructors
    public Node(OthelloState _state){
        state = _state;
        parent = null;
        nVisited = 0;
        avgScore = 0;
        children = new ArrayList<Node>();
    }

    public Node(OthelloState _state, Node _parent){
        state = _state;
        parent = _parent;
        nVisited = 0;
        avgScore = 0;
        children = new ArrayList<Node>();
    }

    // Gets all the successors of Node and stores them in children (List)
    public void getChildren(){
        List<OthelloMove> moves = state.generateMoves();
        for (int i = 0; i < moves.size(); i++){
            OthelloState childState = state.applyMoveCloning(moves.get(i));
            Node child = new Node(childState);
            child.parentMove = moves.get(i);
            children.add(child);
        }
    }

    // Returns the move that resulted in the game state of a Node
    public OthelloMove getMove(){
        return parentMove;
    }

    // Returns a child with max or min score depending on which player moves next
    public Node bestChild(){

        int bestScore;
        int currentScore;
        Node best = null;
        // Maximizing player (player 1)
        if (state.nextPlayerToMove == 0) {

            bestScore = (int)Double.NEGATIVE_INFINITY;

            // Find child with highest score
            for (int i = 0; i < children.size(); i++){

                currentScore = children.get(i).score();
                if (currentScore > bestScore) {
                    bestScore = currentScore;
                    best = children.get(i);
                }
            }

            return best;
        } // Minimizing player (player 2)
        else {

            bestScore = (int)Double.POSITIVE_INFINITY;

            // Find child with lowest score
            for (int i = 0; i < children.size(); i++){

                currentScore = children.get(i).score();
                if (currentScore < bestScore){
                    bestScore = currentScore;
                    best = children.get(i);
                }
            }

            return best;
        }

    }

    // Returns a Node based on tree created from root node
    public Node treePolicy(int rand){

        List<OthelloMove> moves = state.generateMoves();

        // If this is a terminal node
        if (moves.isEmpty())
            return this;

        // If this has children not in tree
        if (children.size() < moves.size()){
            // Generate child and add to children List
            int index = children.size();
            OthelloState successor = state.applyMoveCloning(moves.get(index));
            Node child = new Node(successor, this);
            return child;
        }

        // If all children are in the tree
        if (children.size() == moves.size()) {
            // 90% return bestChild()
            if (rand >= 1)
                return this.bestChild();
            else { // 10% return random child
                Random randomIndex = new Random();
                int index = randomIndex.nextInt(children.size());
                return children.get(index);
            }
        }

        return null;
    }

    // Selects successors at random for node and plays till end game; returns final state
    public Node defaultPolicy()
    {
        Node n = this;
        Random rand = new Random();

        // If the game is not over and there are possible moves, continue to play randomly
        while ( !(n.state.gameOver()) && !(n.children.isEmpty()) ) {
            int r = rand.nextInt(children.size());
            n = children.get(r);
            n.getChildren();
        }
        return n; // return final state
    }

    // Returns the score of a game
    public int score(){
        return state.score();
    }

    // Recursively increments nVisited and avgScore
    public void backup(int score){

        nVisited++;
        avgScore = (avgScore+score)/nVisited;

        if (parent != null)
            parent.backup(score);
    }

}
