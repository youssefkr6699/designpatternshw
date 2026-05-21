1. Factory Method (Creational)
Instead of using raw numbers, this pattern creates the Rock, Paper, and Scissors objects dynamically based on the player's choice. It keeps the object creation code cleanly separated from the main game loop.

2. Adapter (Structural)
This acts as a bridge. It takes our new Move objects and adapts them to work perfectly with the original 2D-array math logic that decides the winner of a round.

3. Facade (Structural)
This pattern hides all the complicated engine setup behind a single GameFacade class. Because of this, the main() function only needs one simple command (playMatch()) to run the entire game.

4. Strategy (Behavioral)
This lets us swap out the computer's "brain" on the fly. It allows the game to easily switch between a "Random AI" and a "Hard AI" without having to rewrite any of the core game rules.

5. Template Method (Behavioral)
This defines a strict skeleton for how a match is played (initializeGame(), playRounds(), displayFinalResults()). It ensures the game always runs in the correct sequence while allowing us to easily customize those individual steps later.
