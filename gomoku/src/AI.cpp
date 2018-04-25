//
//  AI.cpp
//  gomoku
//
//  Created by Ricky Peng on 4/20/18.
//

#include "gomoku.h"

void gomoku::robotMove(int x, int y){
    
    //evaluate defensive
    std::vector<tuple<int,int,int>> results;
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = WHITE;
                for (int i = 0; i < size - 1; i++) {
                    for (int j = 0; j < size - 1; j++) {
                        if (board[i][j] == EMPTY) {
                            board[i][j] = BLACK;
                            results.push_back(make_tuple(evaluate(x, y), i, j));
                            board[i][j] = EMPTY;
                        }
                    }
                }
            } else {
                continue;
            }
            
            
            board[i][j] = EMPTY;
            
        
        }
    }
    
    int best = std::get<0>(results.at(0));
    tuple<int, int, int> bestCombo = make_tuple(std::get<0>(results.at(0)), std::get<1>(results.at(0)), std::get<2>(results.at(2)));
    
    for (int i = 0; i < results.size(); i++) {
        int current = std::get<0>(results.at(i));
        if (current > best) {
            bestCombo = make_tuple(std::get<0>(results.at(i)), std::get<1>(results.at(i)), std::get<2>(results.at(i)));
            best = current;
        }
    }
    
    int bestX = std::get<1>(bestCombo);
    int bestY = std::get<2>(bestCombo);
    
    //evaluate offensive
    
    
    
        if (autoDraw((bestX + 1) * unit_width, (bestY + 1) * unit_height)) {
            draw();
            if (isWin()) {
                //std::cout << "win!" << std::endl;
                current_state = END;
                draw();
            }
            
        }
    
        if (current_state != END) {
            changeTurn();
            current_state = NO_PLACE;
        }
}

int gomoku::evaluate(int x, int y) {
    
    int result = 0;
    

    
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            
            if (board[j][i] == EMPTY)  {
                continue;
            }
            
            //int current_color = board[j][i];
            
            //skip the ones that are in the middle of a connection (only validate the ones that are at front)
            
            
            
            //check right - connect 4
            if (board[j][i] != EMPTY && (j + 4) <= (size - 2)) {
                for (int count = 1; count < 5; count++) {
                    if (board[j + count][i] == BLACK) {
                        if (count == 3) {
                            result += 500;
                        }
                        if (count == 2) {
                            result += 10;
                        }
                        if (count == 4) {
                            result += 1000;
                        }
                    } else {
                        break;
                    }
                }
            }
            
            //check downward right - connect 4
            if (board[j][i] != EMPTY && (i + 4) <= (size - 2) && (j + 4) <= (size - 2)) {
                for (int count = 1; count < 5; count++) {
                    if (board[j + count][i + count] == BLACK) {
                        if (count == 3) {
                            result += 500;
                        }
                        if (count == 2) {
                            result += 10;
                        }
                        if (count == 4) {
                            result += 1000;
                        }
                    } else {
                        break;
                    }
                }
            }
            
            //check downward - connect 4
            if (board[j][i] != EMPTY && (i + 4) <= (size - 2)) {
                for (int count = 1; count < 5; count++) {
                    if (board[j][i + count] == BLACK) {
                        if (count == 3) {
                            result += 500;
                        }
                        if (count == 2) {
                            result += 10;
                        }
                        if (count == 4) {
                            result += 1000;
                        }
                    } else {
                        break;
                    }
                }
            }
            
            //check downward left - connect 4
            
            if (board[j][i] != EMPTY && (i + 4) <= (size - 2) && (j - 4) >= 0) {
                for (int count = 1; count < 5; count++) {
                    if (board[j - count][i + count] == BLACK) {
                        if (count == 3) {
                            result += 500;
                        }
                        if (count == 2) {
                            result += 10;
                        }
                        if (count == 4) {
                            result += 1000;
                        }
                    } else {
                        break;
                    }
                }
            }
            
            
            
        }
    }
    
    return result;
}

void gomoku::checkFree(renjuType type, int renju, int i, int j) {
    if (type == RIGHT && board[j - 1][i] == EMPTY && board[j + renju][]) {
        
    }
}




