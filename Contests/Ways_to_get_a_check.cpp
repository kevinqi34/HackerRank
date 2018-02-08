#include <bits/stdc++.h>

using namespace std;

struct pos {
    char piece;
    int row;
    int column;
};

// Helper Functions
// Help testKnight
int knight_helper(int p_row, int p_col, pos king) {
  int return_val = 0;
  if (p_row == king.row && p_col == king.column) {
      return_val = 1;
  }
  return return_val;
}

// Help General
// Checks if either a white piece in the way or more than 1 black piece
int general_helper(int p_row, int p_col, pos king, int white_count, int black_count, bool case2) {
  int return_val = 0;
  // Check ending condition
  if (p_row == king.row && p_col == king.column) {
      // Check history
      if (case2) {
          // Case 1 - just king
          if (white_count == 0 && black_count == 0) {
              return_val = 1;
          // Case 2 - just king and one black piece
          } else if (black_count == 1 && white_count == 0) {
              return_val = 1;
          }

      } else {
          // Case 1 - just king
          if (white_count == 0 && black_count == 0) {
              return_val = 1;
          }
      }
  }
  // Return
  return return_val;
}


// Checks if a knight checks king
int testKnight(pos knight, pos king) {
    int checker = 0;
    // Case 1 r + 1, c - 2
    checker+=knight_helper(knight.row + 1, knight.column - 2, king);
    // Case 2 r + 1, c + 2
    checker+=knight_helper(knight.row + 1, knight.column + 2, king);
    // Case 3 r + 2, c - 1
    checker+=knight_helper(knight.row + 2, knight.column - 1, king);
    // Case 4 r + 2, c + 1
    checker+=knight_helper(knight.row + 2, knight.column + 1, king);
    // Case 5 r - 1, c - 2
    checker+=knight_helper(knight.row - 1, knight.column - 2, king);
    // Case 6 r - 1, c + 2
    checker+=knight_helper(knight.row - 1, knight.column + 2, king);
    // Case 7 r - 2, c - 1
    checker+=knight_helper(knight.row - 2, knight.column - 1, king);
    // Case 8 r - 2, c + 1
    checker+=knight_helper(knight.row - 2, knight.column + 1, king);
    // Return
    if (checker) {
        return 1;
    } else {
        return 0;
    }
}

// Checks if a bishop checks king
int testBishop(pos bishop, pos king, vector < vector<char> > board, bool flag) {
    int i_row = bishop.row;
    int i_col = bishop.column;
    int checker = 0;
    int black_count = 0;
    int white_count = 0;
    // Also has to check if either a white piece in the way or more than 1 black piece
    // Case 1 lower left diagonal r + 1, c - 1
    int tmp1_row = i_row;
    int tmp1_col = i_col;
    while (tmp1_row < 8 && tmp1_col >= 0) {
        int round_val = general_helper(tmp1_row, tmp1_col, king, white_count, black_count, flag);
        if (round_val == 1) {
            checker+=round_val;
            break; // Exit
        }
        // Save history
        if (board[tmp1_row][tmp1_col] != '#') {
          char current = board[tmp1_row][tmp1_col];
          // Check color
          if ((int)current > 97) { // Black pieces
            black_count++;
          } else {
            white_count++; // White pieces
          }
        }
        tmp1_row++;
        tmp1_col--;
    } // While
    // Reset count
    black_count = 0;
    white_count = 0;
    // Case 2 lower right diagonal r + 1, c + 1
    int tmp2_row = i_row;
    int tmp2_col = i_col;
    while (tmp2_row < 8 && tmp2_col < 8) {
        int round_val = general_helper(tmp2_row, tmp2_col, king, white_count, black_count, flag);
        if (round_val == 1) {
            checker+=round_val;
            break; // Exit
        }
        // Save history
        if (board[tmp2_row][tmp2_col] != '#') {
          char current = board[tmp2_row][tmp2_col];
          // Check color
          if ((int)current > 97) { // Black pieces
            black_count++;
          } else {
            white_count++; // White pieces
          }
        }
        tmp2_row++;
        tmp2_col++;
    } // While
    // Reset Count
    black_count = 0;
    white_count = 0;
    // Case 3 upper left diagonal r - 1, c - 1
    int tmp3_row = i_row;
    int tmp3_col = i_col;
    while (tmp3_row >= 0 && tmp3_col >= 0) {
        int round_val = general_helper(tmp3_row, tmp3_col, king, white_count, black_count, flag);
        if (round_val == 1) {
            checker+=round_val;
            break; // Exit
        }
        // Save history
        if (board[tmp3_row][tmp3_col] != '#') {
          char current = board[tmp3_row][tmp3_col];
          // Check color
          if ((int)current > 97) { // Black pieces
            black_count++;
          } else {
            white_count++; // White pieces
          }
        }
        tmp3_row--;
        tmp3_col--;
    } // While
    // Reset count
    black_count = 0;
    white_count = 0;
    // Case 2 upper right diagonal r - 1, c + 1
    int tmp4_row = i_row;
    int tmp4_col = i_col;
    while (tmp4_row >= 0 && tmp4_col < 8) {
        int round_val = general_helper(tmp4_row, tmp4_col, king, white_count, black_count, flag);
        if (round_val == 1) {
            checker+=round_val;
            break; // Exit
        }
        // Save history
        if (board[tmp4_row][tmp4_col] != '#') {
          char current = board[tmp4_row][tmp4_col];
          // Check color
          if ((int)current > 97) { // Black pieces
            black_count++;
          } else {
            white_count++; // White pieces
          }
        }
        tmp4_row--;
        tmp4_col++;
    } // While
    // Reset Count
    black_count = 0;
    white_count = 0;
    // Return
    if (checker) {
        return 1;
    } else {
        return 0;
    }
}

// Checks if a rook checks king
int testRook(pos rook, pos king, vector < vector<char> > board, bool flag) {
    int i_row = rook.row;
    int i_col = rook.column;
    int checker = 0;
    int black_count = 0;
    int white_count = 0;
    // Also has to check if either a white piece in the way or more than 1 black piece
    // Case 1 - Right r, c + 1
    int tmp1_row = i_row;
    int tmp1_col = i_col;
    while (tmp1_col < 8) {
        int round_val = general_helper(tmp1_row, tmp1_col, king, white_count, black_count, flag);
        if (round_val == 1) {
            checker+=round_val;
            break; // Exit
        }
        // Save history
        if (board[tmp1_row][tmp1_col] != '#') {
          char current = board[tmp1_row][tmp1_col];
          // Check color
          if ((int)current > 97) { // Black pieces
            black_count++;
          } else {
            white_count++; // White pieces
          }
        }
        tmp1_col++;
    } // While
    // Reset
    black_count = 0;
    white_count = 0;
    // Case 2 - Left r, c - 1
    int tmp2_row = i_row;
    int tmp2_col = i_col;
    while (tmp2_col >= 0) {
        int round_val = general_helper(tmp2_row, tmp2_col, king, white_count, black_count, flag);
        if (round_val == 1) {
            checker+=round_val;
            break; // Exit
        }
        // Save history
        if (board[tmp2_row][tmp2_col] != '#') {
          char current = board[tmp2_row][tmp2_col];
          // Check color
          if ((int)current > 97) { // Black pieces
            black_count++;
          } else {
            white_count++; // White pieces
          }
        }
        tmp2_col--;
    } // While
    // Reset
    black_count = 0;
    white_count = 0;
    // Case 3 - Down r + 1, c
    int tmp3_row = i_row;
    int tmp3_col = i_col;
    while (tmp3_row < 8) {
        int round_val = general_helper(tmp3_row, tmp3_col, king, white_count, black_count, flag);
        if (round_val == 1) {
            checker+=round_val;
            break; // Exit
        }
        // Save history
        if (board[tmp3_row][tmp3_col] != '#') {
          char current = board[tmp3_row][tmp3_col];
          // Check color
          if ((int)current > 97) { // Black pieces
            black_count++;
          } else {
            white_count++; // White pieces
          }
        }
        tmp3_row++;
    } // While
    // Reset
    black_count = 0;
    white_count = 0;
    // Case 4 - Up r - 1, c
    int tmp4_row = i_row;
    int tmp4_col = i_col;
    while (tmp4_row >= 0) {
        int round_val = general_helper(tmp4_row, tmp4_col, king, white_count, black_count, flag);
        if (round_val == 1) {
            checker+=round_val;
            break; // Exit
        }
        // Save history
        if (board[tmp4_row][tmp4_col] != '#') {
          char current = board[tmp4_row][tmp4_col];
          // Check color
          if ((int)current > 97) { // Black pieces
            black_count++;
          } else {
            white_count++; // White pieces
          }
        }
        tmp4_row--;
    } // While
    // Reset
    black_count = 0;
    white_count = 0;
    // Return
    if (checker) {
        return 1;
    } else {
        return 0;
    }
}

// Checks if a queen checks king
// Run bishop and rook
int testQueen(pos queen, pos king, vector < vector<char> > board, bool flag) {
    int count = 0;
    count+=testBishop(queen, king, board, flag);
    count+=testRook(queen, king, board, flag);
    if (count) {
        return 1;
    } else {
        return 0;
    }
}


// Check valid pawn
int is_possible_pawn(pos white_king, vector < vector<char> > board, vector<pos> black_pieces) {
  int count = 0;
  // Find ways
  for (auto p : black_pieces) {
    vector < vector<char> > b_board = board;
    b_board[p.row][p.column] = '#';
    // Check Q, N, R, B
    if (p.piece == 'q') { // Queen
      count+=testQueen(p, white_king, b_board, false);
    } else if (p.piece == 'n') { // Knight
      count+=testKnight(p, white_king);
    } else if (p.piece == 'r') { // Rook
      count+=testRook(p, white_king, b_board, false);
    } else if (p.piece == 'b') { // Bishop
      count+=testBishop(p, white_king, b_board, false);
    }
  } // For

  return count;
}



int waysToGiveACheck(vector < vector<char> > board) {
    int num_of_ways = 0;
    // Pos black king
    pos black_king;
    // Pos white king
    pos white_king;
    vector<pos> white_pawns;
    vector<pos> white_pieces;
    vector<pos> black_pieces;
    for (unsigned int i = 0; i < board.size(); i++) {
        for (unsigned int j = 0; j < board[i].size(); j++) {
          if (board[i][j] != '#') {
              // Find position of black king
              if (board[i][j] == 'k') {
                  black_king.row = i;
                  black_king.column = j;
                  black_king.piece = board[i][j];
              }
              // Find position of white king
              if (board[i][j] == 'K') {
                white_king.row = i;
                white_king.column = j;
                white_king.piece = board[i][j];
              }
              // Find position of white pawns on 7th row
              // White pawn also must be valid
              if (board[i][j] == 'P' && i == 1) {
                  if (board[i - 1][j] == '#') {
                    pos white_pawn;
                    white_pawn.row = i;
                    white_pawn.column = j;
                    white_pawn.piece = board[i][j];
                    white_pawns.push_back(white_pawn);
                  }
              }
              // Find position of white pieces
              if ((unsigned int) board[i][j] < 97) {
                  pos white_piece;
                  white_piece.row = i;
                  white_piece.column = j;
                  white_piece.piece = board[i][j];
                  white_pieces.push_back(white_piece);
              } else { // Find position of black pieces
                  pos black_piece;
                  black_piece.row = i;
                  black_piece.column = j;
                  black_piece.piece = board[i][j];
                  black_pieces.push_back(black_piece);
              }
          }
        } // For
    } // For

    // Find the correct white pawn
    pos pawn; // Correct pawn
    vector < vector<char> >  tmp_board;
    // Pawn is only correct if moving it doesn't lead to a check on white king by black pieces
    for (auto t : white_pawns) {
      // Update board
      vector < vector<char> > t_board = board;
      t_board[t.row][t.column] = '#';
      if (!is_possible_pawn(white_king, t_board, black_pieces)) {
        pawn = t;
        tmp_board = t_board;
        break;
      }
    } // For


    /*
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << tmp_board[i][j] << " ";
        }
        cout << endl;
    }
    */




    // cout << pawn.row << " " << pawn.column << " " << pawn.piece << endl;
    // Check promotions
    // Advance pawn to 8th row
    // Update board
    // Find automatic ways
    // Find promotion ways
    // Advance pawn to 8th row
    pos advanced;
    advanced.row = pawn.row - 1;
    advanced.column = pawn.column;
    // Find discovered ways
    int auto_count = 0;
    for (auto p : white_pieces) {
      vector < vector<char> >  w_board = tmp_board;
      w_board[p.row][p.column] = '#';
      // Check K, Q, N, R, B, P
      if (p.row != pawn.row || p.column != pawn.column) {
        if (p.piece == 'Q') { // Queen
          auto_count+=testQueen(p, black_king, w_board, false);
        } else if (p.piece == 'N') { // Knight
          auto_count+=testKnight(p, black_king);
        } else if (p.piece == 'R') { // Rook
          auto_count+=testRook(p, black_king, w_board, false);
        } else if (p.piece == 'B') { // Bishop
          auto_count+=testBishop(p, black_king, w_board, false);
        }
      }
    } // For

    if (auto_count) {
      num_of_ways+=4;
    } else {
      // Find promotion ways
      // Test Knight
      num_of_ways+=testKnight(advanced, black_king);
      // Test Bishop
      num_of_ways+=testBishop(advanced, black_king, tmp_board, true);
      // Test Rook
      num_of_ways+=testRook(advanced, black_king, tmp_board, true);
      // Test Queen
      num_of_ways+=testQueen(advanced, black_king, tmp_board, true);
    }

    return num_of_ways;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        vector< vector<char> > board(8,vector<char>(8));
        for(int board_i = 0;board_i < 8;board_i++){
           for(int board_j = 0;board_j < 8;board_j++){
              cin >> board[board_i][board_j];
           }
        }
        int result = waysToGiveACheck(board);
        cout << result << endl;
    }
    return 0;
}
