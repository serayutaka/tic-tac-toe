#include <iostream>
#include <vector>
#include "function.hpp"

using namespace std;

vector<string> board = {
    " ", " ", " ",
    " ", " ", " ",
    " ", " ", " "
};

string agent[] = {"X", "O"};
int player = 0;

int position;

void introduction() {

    cout << "Start? [Enter]: \n";
    cin.ignore();

    cout << "\n";

    cout << "===========\n";
    cout << "TIC-TAC-TOE\n";
    cout << "===========\n";

    cout << "\n";

    cout << "Player1: " << agent[0] << endl;
    cout << "Player2: " << agent[1] << endl;

    cout << "\nHere's the 3 x 3 grid: \n";

    cout << "_____ _____ _____\n";
    cout << "     |     |     \n";
    cout << "  1  |  2  |  3  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  4  |  5  |  6  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  7  |  8  |  9  \n";
    cout << "_____|_____|_____\n";
}

void playing() {
    
    while (!is_winning() && !filled_up()) {

       set_position();

       update_board();

       draw();

        if (is_winning()) { break; }

       change_player();

    }
}

bool is_winning() {
    bool win = false;

    // Vertical
    if (board[0] == board[3] && board[0] == board[6] && board[0] != " ") { win = true; }
    else if (board[1] == board[4] && board[1] == board[7] && board[1] != " ") { win = true; }
    else if (board[2] == board[5] && board[2] == board[8] && board[2] != " ") { win = true; }
    
    // Vertical
    else if (board[0] == board[1] && board[0] == board[2] && board[0] != " ") { win = true; }
    else if (board[3] == board[4] && board[3] == board[5] && board[3] != " ") { win = true; }
    else if (board[6] == board[7] && board[6] == board[8] && board[6] != " ") { win = true; }

    // Diagonal
    else if (board[0] == board[4] && board[0] == board[8] && board[0] != " ") { win = true; }
    else if (board[2] == board[4] && board[2] == board[6] && board[2] != " ") { win = true; }

    return win;

}

bool filled_up() {
    bool filled = true;

    for (int i = 0; i < 9; i++) {
        if (board[i] == " ") { filled = false; }
    }
    return filled;
}

void set_position() {
    cout << "\nPlayer " << agent[player] << "'s turn (Enter 1-9): ";

    while(!(cin >> position)) {
        cout << "Input invalid, please try again (Enter 1-9): ";
        cin.clear();
        cin.ignore();
    }

    while(board[position-1] != " ") {
        cout << "There's already " << board[position-1] << " in that position.\n";
        cout << "Please try again, (Enter 1-9): ";

        while (!(cin >> position)) {
            cout << "Input invalid, please try againg (Enter 1-9): ";
            cin.clear();
            cin.ignore();
        } 
    }
}

void update_board() {
    board[position-1] = agent[player];
}

void change_player() {
    if (player == 0) { player = 1; }
    else { player = 0; }
}

void draw() {

    cout << "_____ _____ _____\n";
    cout << "     |     |     \n";
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << endl;
    cout << "_____|_____|_____\n";

}

void end_game() {
    if (is_winning()) { cout << "\nThere's winner! Congratualation to " << agent[player] << "'s Player!"; }
    else if (filled_up()) { cout << "There's tie!\n"; }
}