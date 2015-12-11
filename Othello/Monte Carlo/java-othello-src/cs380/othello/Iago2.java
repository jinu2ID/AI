package cs380.othello;

import java.util.List;

/**
 * Created by jinuj on 11/23/2015.
 */
public class Iago2 extends OthelloPlayer {

    private int max_depth;

    public Iago2(int depth) {
        this.max_depth = depth;
    }

    public OthelloMove getMove(OthelloState state){

        List<OthelloMove> moves = state.generateMoves();

        // If there are no possible moves, just return "pass":
        if (moves.isEmpty())
            return null;

        int best_move_index = 0;
        int best_score;

        boolean player1_turn;

        // Set player and set best_score according to player
        if (state.nextPlayerToMove == 0) {
            player1_turn = true;
            best_score = (int) Double.NEGATIVE_INFINITY;
        }
        else {
            player1_turn = false;
            best_score = (int) Double.POSITIVE_INFINITY;
        }


        // Calculate the score for each move
        for(int i = 0; i < moves.size(); i++){
            OthelloState new_state = state.applyMoveCloning(moves.get(i));
            int score = Minimax(new_state, 0, (int)Double.NEGATIVE_INFINITY, (int)Double.POSITIVE_INFINITY);

            // Maximizing player
            if (player1_turn){
                if (score > best_score) {
                    best_score = score;
                    best_move_index = i;
                }
            }// Minimizing player
            else {
                if (score < best_score) {
                    best_score = score;
                    best_move_index = i;
                }
            }

        }

        // Return best move
        return moves.get(best_move_index);
    }

    private int Minimax(OthelloState state, int depth, int alpha, int beta) {

        // Reached max search depth or game is over
        if (depth == max_depth)
            return state.eval();
        else {
            // Generate all moves
            List<OthelloMove> moves = state.generateMoves();

            // No possible moves or end of game
            if (moves == null)
                return state.eval();

                // Maximizing (player 1)
            else if (state.nextPlayerToMove == 0) {
                int best_score = (int)Double.NEGATIVE_INFINITY;

                for(int i = 0; i < moves.size(); i++) {
                    OthelloState new_state = state.applyMoveCloning(moves.get(i));
                    int score = Minimax(new_state, depth + 1, alpha, beta);
                    if (score > best_score)
                        best_score = score;

                    // alpha-beta pruning
                    alpha = Math.max(alpha, best_score);
                    if (alpha >= beta)
                        return alpha;
                }
                return best_score;
            }
            // Minimizing (player 2)
            else {
                int best_score = (int)Double.POSITIVE_INFINITY;

                for(int i = 0; i < moves.size(); i++) {
                    OthelloState new_state = state.applyMoveCloning(moves.get(i));
                    int score = Minimax(new_state, depth+1, alpha, beta);
                    if (score < best_score)
                        best_score = score;

                    // alpha-beta pruning
                    beta = Math.min(beta, best_score);
                    if (beta <= alpha)
                        return beta;
                }
                return best_score;
            }
        }
    }
}
