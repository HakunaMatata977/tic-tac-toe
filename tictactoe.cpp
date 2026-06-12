// ============================================
//   Tic-Tac-Toe  |  C++
//   Player (X) vs Computer (O)
//   github.com/HalunaMatata
// ============================================

#include <iostream>
#include <array>
#include <limits>

// ── Board ────────────────────────────────────
class Board {
public:
    std::array<char, 9> cells;

    Board() { cells.fill(' '); }

    void display() const {
        std::cout << "\n";
        for (int i = 0; i < 9; i++) {
            char display = (cells[i] == ' ') ? ('1' + i) : cells[i];
            std::cout << " " << display;
            if (i % 3 != 2) std::cout << " |";
            else if (i != 8) std::cout << "\n---+---+---\n";
        }
        std::cout << "\n\n";
    }

    bool place(int pos, char mark) {
        if (pos < 0 || pos > 8 || cells[pos] != ' ') return false;
        cells[pos] = mark;
        return true;
    }

    bool isFull() const {
        for (char c : cells) if (c == ' ') return false;
        return true;
    }

    char winner() const {
        // rows, cols, diagonals
        const int wins[8][3] = {
            {0,1,2},{3,4,5},{6,7,8},  // rows
            {0,3,6},{1,4,7},{2,5,8},  // cols
            {0,4,8},{2,4,6}           // diagonals
        };
        for (auto& w : wins) {
            if (cells[w[0]] != ' ' &&
                cells[w[0]] == cells[w[1]] &&
                cells[w[1]] == cells[w[2]])
                return cells[w[0]];
        }
        return ' ';
    }
};

// ── Minimax AI ───────────────────────────────
int minimax(Board b, bool isMaximizing) {
    char w = b.winner();
    if (w == 'O') return  10;
    if (w == 'X') return -10;
    if (b.isFull())  return  0;

    int best = isMaximizing ? -100 : 100;
    for (int i = 0; i < 9; i++) {
        if (b.cells[i] != ' ') continue;
        b.cells[i] = isMaximizing ? 'O' : 'X';
        int score = minimax(b, !isMaximizing);
        b.cells[i] = ' ';
        best = isMaximizing ? std::max(best, score)
                            : std::min(best, score);
    }
    return best;
}

int bestMove(Board b) {
    int best = -100, move = -1;
    for (int i = 0; i < 9; i++) {
        if (b.cells[i] != ' ') continue;
        b.cells[i] = 'O';
        int score = minimax(b, false);
        b.cells[i] = ' ';
        if (score > best) { best = score; move = i; }
    }
    return move;
}

// ── Game loop ────────────────────────────────
int getPlayerMove(const Board& b) {
    int pos;
    while (true) {
        std::cout << "Your move (1-9): ";
        if (!(std::cin >> pos)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. ";
            continue;
        }
        pos--;  // convert to 0-indexed
        if (pos >= 0 && pos <= 8 && b.cells[pos] == ' ') return pos;
        std::cout << "Cell taken or out of range. Try again.\n";
    }
}

void playGame() {
    Board board;
    std::cout << "\n=== Tic-Tac-Toe ===";
    std::cout << "\nYou are X  |  Computer is O";
    std::cout << "\nEnter a number (1-9) to place your mark.\n";

    while (true) {
        // Player turn
        board.display();
        int move = getPlayerMove(board);
        board.place(move, 'X');

        if (board.winner() == 'X') {
            board.display();
            std::cout << "You win! Well played!\n";
            return;
        }
        if (board.isFull()) break;

        // Computer turn
        std::cout << "Computer is thinking...\n";
        board.place(bestMove(board), 'O');

        if (board.winner() == 'O') {
            board.display();
            std::cout << "Computer wins! Better luck next time.\n";
            return;
        }
        if (board.isFull()) break;
    }

    board.display();
    std::cout << "It's a draw!\n";
}

int main() {
    char again = 'y';
    while (again == 'y' || again == 'Y') {
        playGame();
        std::cout << "\nPlay again? (y/n): ";
        std::cin >> again;
    }
    std::cout << "\nThanks for playing!\n";
    return 0;
}
