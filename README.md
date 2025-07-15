# memoryMatchGame

This project was developed as part of an advanced programming module to demonstrate logic implementation, game design, and the practical use of data structures. The Memory Match Game is a console-based memory puzzle that challenges users to match pairs of items from a hidden table within a limited number of attempts.

Game Overview:
Upon starting the game, the user is presented with a main menu offering three difficulty levels: Easy, Medium, and Hard. Once a level is selected, the game displays a grid of item pairs (e.g., words or symbols) for a few seconds. These items are then hidden, and each cell in the grid is replaced with a number.

The user is prompted to input two card numbers in each turn:

If the selected cards contain matching items, the numbers are erased from the board.

If they do not match, the actual items are briefly revealed, and then the numbers are restored without erasing.

The player is given 10 turns to match as many pairs as possible. At the end of the game, a final score is displayed, based on the number of correct matches, regardless of whether the player wins or loses.

Key Features:
Dynamic Difficulty Levels: Grid size and complexity vary based on the selected level.

Timed Memory Challenge: Items are visible for a short time before being hidden, testing the user’s memory.

Turn-Based Logic: A clear structure for tracking user input, turn count, and score.

Randomization: The items are randomly shuffled each time the game is launched to ensure a unique experience in every session.

Technical Implementation:
AVL Tree Data Structure: Used to efficiently handle searching, insertion, and deletion of elements during gameplay, ensuring optimal performance even as the game progresses.

Complex Logic: Includes dynamic table generation, randomized placement of items, and conditional turn handling based on match accuracy.

This project reflects a strong understanding of both algorithmic thinking and the integration of data structures like AVL trees into interactive applications. It demonstrates problem-solving skills, game logic implementation, and the ability to create engaging, user-focused programs.
