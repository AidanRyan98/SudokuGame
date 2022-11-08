#pragma once
void startup();
void print_board(int(&board)[9][9]);
bool isvalid(int(&board)[9][9], int row, int col, int val);
void user_input(int(&board)[9][9]);
bool iscompleted(int(&board)[9][9]);
int chartoint(char letter);