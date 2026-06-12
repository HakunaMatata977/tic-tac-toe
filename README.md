[README.md](https://github.com/user-attachments/files/28874588/README.md)
# Tic-Tac-Toe (C++)

A terminal-based Tic-Tac-Toe game with an unbeatable AI opponent, built in C++.

## Features

- Player (X) vs Computer (O)
- AI powered by the **Minimax algorithm** — it never loses
- Clean board display with numbered cells
- Input validation & replay option

## How to run

```bash
# Compile
g++ -o tictactoe tictactoe.cpp

# Play
./tictactoe
```

## How to play

The board positions are numbered 1–9:

```
 1 | 2 | 3
---+---+---
 4 | 5 | 6
---+---+---
 7 | 8 | 9
```

Enter a number to place your **X**. The computer plays **O** using the Minimax algorithm — try to force a draw!

## Concepts used

- Object-oriented design (`Board` class)
- Recursion (Minimax algorithm)
- Arrays and game state management
- Input validation

## Author

[HalunaMatata](https://github.com/HalunaMatata)
