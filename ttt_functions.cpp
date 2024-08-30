#include <iostream>

#include "ttt_functions.hpp"

void display_board(char board[3][3]){
  for (int i = 0; i<3; i++){

    std::cout << board[i][0] << " | "<< board[i][1] << " | "<< board[i][2] << "\n";
    if (i<2){
      std::cout << "_________" << "\n\n";

    }
  }

  
}
