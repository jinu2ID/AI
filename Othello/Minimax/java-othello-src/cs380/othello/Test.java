package cs380.othello;

/**
 *
 * @author santi
 */
public class Test {
    
    
    public static void main(String args[]) {

/*  TESTING CODE
 * 	
 *      int won = 0;
 *      int lost = 0;
 *      int tie = 0;

        long startTime = System.nanoTime();
        for (int i =0; i < 100; i++) {
*/
        // Create the game state with the initial position for an 8x8 board:
        OthelloState state = new OthelloState(8);
        OthelloPlayer players[] = {new OthelloRandomPlayer(),
                                   new Iago(8)};

        do {
           	// Display the current state in the console
			  	System.out.println("\nCurrent state, " + OthelloState.PLAYER_NAMES[state.nextPlayerToMove] + " to move:");
           	System.out.print(state);

           	// Get the move from the player:
			  	OthelloMove move = players[state.nextPlayerToMove].getMove(state);
           	System.out.println(move);
           	state = state.applyMoveCloning(move);
           } while (!state.gameOver());

            // Show the result of the game:
            System.out.println("\nFinal state with score: " + state.score());
            System.out.println(state);

/* TESTING CODE
 *	
 *          if (state.score() < 0)
 *              won++;
 *          else if (state.score() > 0)
 *              lost++;
 *          else
 *              tie++;
 *       }
 *      long endTime = System.nanoTime();
 *
 *      long duration = (endTime - startTime)/1000000;
 *
 *      System.out.println("won: " + won + " " + "lost: " + lost + " " +
 *			  "tie:  " + tie + " " + "time: " + duration + " ms");
 */
    }    
    
}
