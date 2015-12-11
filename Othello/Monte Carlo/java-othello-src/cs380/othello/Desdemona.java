package cs380.othello;

import java.util.Random;

/**
 * Created by jinuj on 11/20/2015.
 * jj559@drexel.edu
 * This agent uses the Monte Carlo Tree Search algorithm to play Othello
 *
 */
public class Desdemona extends OthelloPlayer {

    int iterations;

    public Desdemona(int _iterations){
        iterations = _iterations;
    }

    public OthelloMove getMove(OthelloState state){

        if (state.generateMoves().isEmpty())
            return null;

        OthelloMove bestMove = MonteCarloTreeSearch(state, iterations);
        return bestMove;
    }

    public OthelloMove MonteCarloTreeSearch(OthelloState gameState, int iterations){
        Random rand = new Random();
        Node root = createNode(gameState);

        for (int i = 0; i < iterations; i++) {
            int r = rand.nextInt(10);
            Node node = root.treePolicy(r);
            if (node != null) {
                Node node2 = node.defaultPolicy();
                int Node2Score = node2.score();
                node.backup(Node2Score);
            }
        }
        OthelloMove bestMove = root.bestChild().getMove();
        return bestMove;
    }

    // Returns a Node from the given game state
    public Node createNode(OthelloState state){
        Node node = new Node(state);
        node.getChildren();
        return node;
    }



}
