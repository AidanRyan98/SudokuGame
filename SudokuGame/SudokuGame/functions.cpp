#include <iostream>

using namespace std;

//Startup welcome message
void startup() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "        Welcome to C++ Sudoku         " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

//Function to print board
void print_board(int(&board)[9][9]) {
    char grid[9] = { 'A','B','C','D','E','F','G','H','I' };

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "     A  B  C  |  D  E  F  |  G  H  I  " << endl;
    cout << "======================================" << endl;
    for (int i = 0; i < 9; i++) {
        cout << grid[i] << " || ";
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << "  ";
            if (j == 2 || j == 5) {
                cout << "¦  ";
            }
        }
        cout << "\n";
        if (i == 2 || i == 5) {
            cout << "--------------------------------------" << endl;
        }
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
}

//Check if number placement is valid
bool isvalid(int(&board)[9][9], int row, int col, int val) {
    //check row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == val) {
            return false;
        }
    }

    //check columns
    for (int j = 0; j < 9; j++) {
        if (board[j][col] == val) {
            return false;
        }
    }

    //check if number appears in 3*3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (board[x + startRow][y + startCol] == val) {
                return false;
            }
        }
    }

    return true;
}

//swap letter for number
int chartoint(char letter) {
    int number;

    switch (letter) {
    case 'a':
        number = 0;
        break;

    case 'b':
        number = 1;
        break;

    case 'c':
        number = 2;
        break;

    case 'd':
        number = 3;
        break;

    case 'e':
        number = 4;
        break;

    case 'f':
        number = 5;
        break;

    case 'g':
        number = 6;
        break;

    case 'h':
        number = 7;
        break;

    case 'i':
        number = 8;
        break;

    default:
        break;
    }

    return number;
}

//Capture user input and check if valid
void user_input(int(&board)[9][9]) {
    bool valid = false;
    char user_col_char = 'A';
    char user_row_char = 'A';
    int user_col = 0;
    int user_row = 0;
    int user_val = 0;

    //capture valid user input
    while (!valid) {
        cout << "Choose a row: ";
        cin >> user_row_char;
        cout << "Choose a column: ";
        cin >> user_col_char;
        cout << "Enter a value: ";
        cin >> user_val;

        user_row_char = tolower(user_row_char);
        user_col_char = tolower(user_col_char);

        user_row = chartoint(user_row_char);
        user_col = chartoint(user_col_char);

        valid = isvalid(board, user_row, user_col, user_val);

        if (valid) {
            board[user_row][user_col] = user_val;
        }
        else {
            cout << user_val << " at position [" << user_row_char << "][" << user_col_char << "] is invalid." << endl;
        }
    }
}

//check if board is completed
bool iscompleted(int(&board)[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }

    return true;
}