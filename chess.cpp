// chess.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// This file is a version of the chess game I am presenting
//There is nothing new in the game the difference is that the solution you gave to the game is as follows
//The game is designed for two people

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
typedef vector<vector<int>> Board;

const int EMPTY = 0;
const  int KING = 1;
const int QUEEN = 2;
const int  ROOK = 3;
const int  BISHOP = 4;
const int KNIGHT = 5;
const int PAWN = 6;

const int WHITE = 1;
const int BLACK = -1;

unordered_map<int, string>piece_to_print{
	{-ROOK,"BR"},
	{-QUEEN,"BQ"},
	{-BISHOP,"BB"},
	{-KNIGHT,"BK"},
	{-KING,"BK"},
	{-PAWN,"BP"},
	{ROOK,"WR"},
	{QUEEN,"WQ"},
	{BISHOP,"WB"},
	{KNIGHT,"WK"},
	{KING,"WK"},
	{PAWN,"WP"},
	{EMPTY,"  "},
};

Board create_board() {
	return {
		{-ROOK, -KNIGHT, -BISHOP, -QUEEN, -KING, -BISHOP, -KNIGHT, -ROOK },
		{-PAWN, -PAWN, -PAWN, -PAWN, -PAWN, -PAWN, -PAWN, -PAWN, },
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, },
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, },
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, },
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, },
		{PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, },
		{ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK },
	};
}


void print_board(const Board& board) {
	cout << "    ";
	for (char ch = 'a'; ch <= 'h'; ++ch) {
		cout << ch << "   ";
	}

	cout << "\n  +---+---+---+---+---+---+---+---+\n";
	int count = 8;
	for (vector<int>row : board) {
		cout << count << " ";
		for (int j : row) {
			cout << "| " << piece_to_print[j];
		}
		cout << "|" << count-- << "\n";
		cout << "  +---+---+---+---+---+---+---+---+ \n";
	}

	cout << "    ";
	for (char ch = 'a'; ch <= 'h'; ++ch) {
		cout << ch << "   ";
	}
}
int cast(char x) {
	return static_cast<int>(x) - 97;
}
int input(const Board& board, char* i, int* j, char* m, int* n, int* count) {
	string x;
	if (pow(-1, *count) > 0) {
		cout << "\nWHITES MOVE\n";
	}
	else {
		cout << "\nBLACKS MOVE\n";
	}
	do {
		cout << "\nEnter your step: ";
		cin >> x;
		if (x == "exit") {
			return -1;
		}
		*i = x[0];
		*j = x[1] - '0';
		*m = x[2];
		*n = x[3] - '0';
	} while (cast(*i) < 0 || cast(*i) > 8 || *j < 0 || *j>8 || cast(*m) < 0 || cast(*m) > 8 || *n < 0 || *n>8);


	if ((board[8 - *j][cast(*i)] > 0)) {
		if (pow(-1, *count) < 0) {
			cout << "\nEROR";
			input(board, i, j, m, n, count);
		}
	}


	if ((board[8 - *j][cast(*i)] < 0)) {
		if (pow(-1, *count) > 0) {
			cout << "\nEROR";
			input(board, i, j, m, n, count);
		}
	}

	if ((board[8 - *n][cast(*m)] > 0 && pow(-1, *count) > 0) || (board[8 - *n][cast(*m)] < 0 && pow(-1, *count) < 0))
	{
		cout << "\nThere is your figure ";
		input(board, i, j, m, n, count);
	}
	return 0;
}



bool test(Board& board, char i, int j, char m, int n) {
	if (board[8 - j][cast(i)] == -ROOK || board[i][j] == ROOK) {
		if (cast(i) != cast(m) && j != n) {
			return false;
		}
		if (8 - n >= 8 - j) {
			for (int q = 8 - j + 1; q < 8 - n; ++q) {
				if (board[q][cast(i)] != EMPTY) {
					return false;
				}
			}
		}
		else
		{
			for (int q = 8 - n + 1; q < 8 - j; ++q) {
				if (board[q][cast(i)] != EMPTY) {
					return false;
				}
			}

			if (cast(i) >= cast(m)) {
				for (int q = cast(i) + 1; q < cast(m); ++q) {
					if (board[8 - j][q] != EMPTY) {
						return false;
					}
				}
			}
			else {
				for (int q = cast(m) + 1; q < cast(i); ++q) {
					if (board[8 - j][q] != EMPTY) {
						return false;
					}
				}
			}
		}
	}
	return true;
}


void do_move(Board& board, char& i, int& j, char& m, int& n) {
	

	board[8 - n][cast(m)] = board[8 - j][cast(i)];
	board[8 - j][cast(i)] = EMPTY;
}


	int main()
	{
		cout << "       For exit enter 'exit'\n";
		cout << "    Make your move as follows a4a5\n";
		vector<vector<int>> board{
			{-ROOK, -KNIGHT, -BISHOP, -QUEEN, -KING, -BISHOP, -KNIGHT, -ROOK },
			{-PAWN, -PAWN, -PAWN, -PAWN, -PAWN, -PAWN, -PAWN, -PAWN, },
			{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, },
			{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, },
			{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, },
			{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, },
			{PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, },
			{ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK }, };
		print_board(board);
		char i;
		int j;
		char m;
		int n;
		int count{};
		while (input(board, &i, &j, &m, &n, &count) != -1) {
			do_move(board, i, j, m, n);
			print_board(board);
			++(count);
		}

		return 0;
	}
