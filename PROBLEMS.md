"Spaghetti" Logic: All the game rules, player inputs, and score tracking were stuffed into one giant while loop.

Hard to Update: Because the code relied on long if/else chains, adding a new move (like "Lizard" or "Spock") would require rewriting almost the entire game.

Disconnected Features: There was a very clever 2D array matrix written to calculate the winner quickly, but it was isolated in the main() function and completely ignored by the actual Game class!

Not Object-Oriented: The game used raw numbers (1, 2, 3) and text ("rock") to represent moves instead of proper Objects, making the architecture rigid.
