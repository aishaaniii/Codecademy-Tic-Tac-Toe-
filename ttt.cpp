include <iostream>
#include <string>
#include <vector>

#include "ttt_functions.hpp"

// slightly modified version of 'Kenny Yip Coding' from YouTube

// std::cin.clear(); std::cin.ignore(10000, "\n"); tried to add this but then my brain died


int main(){


  // setting up users
  std::string userX;
  std::string userO;
  const char playerX = 'X';
  const char playerO = 'O';
  char currentplayer = playerX;
  char winner = ' ';


  std::cout << "Please enter the name of player one (playing as X): \n";
  std::cin >> userX;
  std::cout << "Please enter the name of player two (playing as O): \n";
  std::cin >> userO;

  int r = -1;
  int c = -1;
  //setting up the 'board' using a 2d array
  char board[3][3]{
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };

  for (int j = 0; j < 9; j++){
    //dissplaying the board
    display_board(board);

    if (winner!=' '){
      break;
    }

    if (currentplayer == 'X'){
      std::cout << userX << ", it is your turn\n";
    }else{
      std::cout << userO << ", it is your turn\n";
    }

    while (true){
      std::cout << "enter row value (0-2) \n";
      std::cin >> r;
      std::cout << "enter column value (0-2) \n";
      std::cin >> c;
      if (r < 0 || r > 2 || c < 0 || c > 2){
        std::cout << "invalid input, try again\n";
      }else if (board[r][c] != ' '){
        std::cout << "already taken! try again\n";
      }else{
        break;
      }
      r = -1;
      c = -1;
      }


    board[r][c] = currentplayer;
    currentplayer = (currentplayer == playerX) ? playerO : playerX;
    // checking winners
    //first checking rows
    for (int e = 0; e<3; e++){

      if (board[e][0] != ' ' && (board[e][0] == board[e][1]) && (board[e][1] == board[e][2])){
        winner = board[e][0];
        break;
      }

    }

    // checking columns
    for (int y = 0; y<3; y++){
      if (board[0][y]!= ' ' && board[1][y]==board[2][y] && board[2][y]==board[0][y]){
        winner = board[0][y];
        break;
      }
    }

    //checking diagonals 

    if ((board[0][0] != ' ' ) && board[0][0]==board[1][1] && board[1][1]==board[2][2]){
      winner = board[0][0];
    }else if ((board[0][2] != ' ') && board[0][2]==board[1][1] && board[1][1]==board[2][0]){
      winner = board[0][2];
    }

  }

  if (winner!=' '&&winner=='X'){
    std::cout << userX << " you are the winner!!!\n";
  }else if (winner!=' '&&winner=='O'){
    std::cout << userO << " you are the winner!!!\n";
  }else{
    std::cout << "it is a draw!! " << userX << " and " << userO << " are both winners :)\n";
  }

  return 0 ;



}
