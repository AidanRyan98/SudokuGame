#include <iostream>
#include "functions.h"

using namespace std;

int main() {
    int board[9][9] = {
      {6, 7, 2, 0, 0, 1, 9, 8, 4},
      {0, 3, 1, 0, 0, 0, 0, 0, 0},
      {0, 4, 0, 0, 2, 0, 0, 0, 3},
      {4, 0, 5, 0, 0, 0, 3, 0, 8},
      {9, 2, 0, 3, 7, 0, 5, 0, 0},
      {7, 6, 0, 0, 0, 0, 0, 2, 0},
      {0, 0, 0, 4, 9, 0, 8, 3, 2},
      {3, 0, 6, 0, 0, 0, 0, 4, 5},
      {0, 0, 4, 0, 5, 0, 1, 9, 6}
    };

    startup();

    print_board(board);

    bool completed = false;

    while (!completed) {
        user_input(board);
        print_board(board);
        completed = iscompleted(board);
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "           Congratulations!           " << endl;
    cout << "       You finished the puzzel        " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}