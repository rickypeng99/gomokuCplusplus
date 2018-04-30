//
//  AI.cpp
//  gomoku
//
//  Created by Ricky Peng on 4/20/18.
//

#include "gomoku.h"

void gomoku::robotMove(int x, int y){
    current_state = PLACE;

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
                            int scoreAI = evaluateWhite(x, y);
                            int scoreHuman = evaluate(x, y);
                            int score = scoreHuman - scoreAI;
                            results.push_back(make_tuple(score, i, j));
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
int gomoku::evaluateWhite(int x, int y) {

    int result = 0;



    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1; ++j) {

            if (board[j][i] == EMPTY || board[j][i] == BLACK)  {
                continue;
            }

            //int current_color = board[j][i];

            //skip the ones that are in the middle of a connection (only validate the ones that are at front)



            //check right - connect 4
            if ((j + 4) <= (size - 2)) {
                for (int count = 1; count < 5; count++) {
                    if (board[j + count][i] == WHITE) {
                        if (count == 1) {
                            result += 5;
                        }
                        if (count == 3) {
                            if (board[j][i] == WHITE && checkFree(RIGHT, 3, i, j)) {
                                result += 1000;
                            }
                            result += 500;
                        }

                        if (count == 2) {
                            if (board[j][i] == WHITE && checkFree(RIGHT, 2, i, j)) {
                                result += 10;
                            }
                            result += 10;
                        }
                        if (count == 4) {
                            if (board[j][i] == WHITE && checkFree(RIGHT, 4, i, j)) {
                                result += 2000;
                            }
                            result += 1000;
                        }
                    } else {
                        break;
                    }
                }
            }

            //check downward right - connect 4
            if ((i + 4) <= (size - 2) && (j + 4) <= (size - 2)) {
                for (int count = 1; count < 5; count++) {
                    if (board[j + count][i + count] == WHITE) {
                        if (count == 1) {
                            result += 5;
                        }
                        if (count == 3) {
                            if (board[j][i] == WHITE && checkFree(DOWNRIGHT, 3, i, j)) {
                                result += 1000;
                            }
                            result += 500;
                        }
                        if (count == 2) {
                            if (board[j][i] == WHITE && checkFree(DOWNRIGHT, 2, i, j)) {
                                result += 10;
                            }
                            result += 10;
                        }
                        if (count == 4) {
                            if (board[j][i] == WHITE && checkFree(DOWNRIGHT, 4, i, j)) {
                                result += 2000;
                            }
                            result += 1000;
                        }
                    } else {
                        break;
                    }
                }
            }

            //check downward - connect 4
            if ((i + 4) <= (size - 2)) {
                for (int count = 1; count < 5; count++) {
                    if (board[j][i + count] == WHITE) {
                        if (count == 1) {
                            result += 5;
                        }
                        if (count == 3) {
                            if (board[j][i] == WHITE && checkFree(DOWN, 3, i, j)) {
                                result += 1000;
                            }
                            result += 500;
                        }
                        if (count == 2) {
                            if (board[j][i] == WHITE && checkFree(DOWN, 2, i, j)) {
                                result += 10;
                            }
                            result += 10;
                        }
                        if (count == 4) {
                            if (board[j][i] == WHITE && checkFree(DOWN, 4, i, j)) {
                                result += 2000;
                            }
                            result += 1000;
                        }
                    } else {
                        break;
                    }
                }
            }

            //check downward left - connect 4

            if ((i + 4) <= (size - 2) && (j - 4) >= 0) {
                for (int count = 1; count < 5; count++) {
                    if (board[j - count][i + count] == WHITE) {
                        if (count == 1) {
                            result += 5;
                        }
                        if (count == 3) {
                            if (board[j][i] == WHITE && checkFree(DOWNLEFT, 3, i, j)) {
                                result += 1000;
                            }
                            result += 500;
                        }
                        if (count == 2) {
                            if (board[j][i] == WHITE && checkFree(DOWNLEFT, 2, i, j)) {
                                result += 10;
                            }
                            result += 10;
                        }
                        if (count == 4) {
                            if (board[j][i] == WHITE && checkFree(DOWNLEFT, 4, i, j)) {
                                result += 2000;
                            }
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
int gomoku::evaluate(int x, int y) {

    int result = 0;



    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1; ++j) {

            if (board[j][i] == EMPTY || board[j][i] == WHITE)  {
                continue;
            }

            //int current_color = board[j][i];

            //skip the ones that are in the middle of a connection (only validate the ones that are at front)



            //check right - connect 4
            if ((j + 4) <= (size - 2)) {
                for (int count = 1; count < 5; count++) {
                    if (board[j + count][i] == BLACK) {
                        if (count == 1) {
                            result += 5;
                        }
                        if (count == 3) {
                            if (board[j][i] == BLACK && checkFree(RIGHT, 3, i, j)) {
                                result += 1000;
                            }
                            result += 500;
                        }

                        if (count == 2) {
                            if (board[j][i] == BLACK && checkFree(RIGHT, 2, i, j)) {
                                result += 10;
                            }
                            result += 10;
                        }
                        if (count == 4) {
                            if (board[j][i] == BLACK && checkFree(RIGHT, 4, i, j)) {
                                result += 2000;
                            }
                            result += 1000;
                        }
                    } else {
                        break;
                    }
                }
            }

            //check downward right - connect 4
            if ((i + 4) <= (size - 2) && (j + 4) <= (size - 2)) {
                for (int count = 1; count < 5; count++) {
                    if (board[j + count][i + count] == BLACK) {
                        if (count == 1) {
                            result += 5;
                        }
                        if (count == 3) {
                            if (board[j][i] == BLACK && checkFree(DOWNRIGHT, 3, i, j)) {
                                result += 1000;
                            }
                            result += 500;
                        }
                        if (count == 2) {
                            if (board[j][i] == BLACK && checkFree(DOWNRIGHT, 2, i, j)) {
                                result += 10;
                            }
                            result += 10;
                        }
                        if (count == 4) {
                            if (board[j][i] == BLACK && checkFree(DOWNRIGHT, 4, i, j)) {
                                result += 2000;
                            }
                            result += 1000;
                        }
                    } else {
                        break;
                    }
                }
            }

            //check downward - connect 4
            if ((i + 4) <= (size - 2)) {
                for (int count = 1; count < 5; count++) {
                    if (board[j][i + count] == BLACK) {
                        if (count == 1) {
                            result += 5;
                        }
                        if (count == 3) {
                            if (board[j][i] == BLACK && checkFree(DOWN, 3, i, j)) {
                                result += 1000;
                            }
                            result += 500;
                        }
                        if (count == 2) {
                            if (board[j][i] == BLACK && checkFree(DOWN, 2, i, j)) {
                                result += 10;
                            }
                            result += 10;
                        }
                        if (count == 4) {
                            if (board[j][i] == BLACK && checkFree(DOWN, 4, i, j)) {
                                result += 2000;
                            }
                            result += 1000;
                        }
                    } else {
                        break;
                    }
                }
            }

            //check downward left - connect 4

            if ((i + 4) <= (size - 2) && (j - 4) >= 0) {
                for (int count = 1; count < 5; count++) {
                    if (board[j - count][i + count] == BLACK) {
                        if (count == 1) {
                            result += 5;
                        }
                        if (count == 3) {
                            if (board[j][i] == BLACK && checkFree(DOWNLEFT, 3, i, j)) {
                                result += 1000;
                            }
                            result += 500;
                        }
                        if (count == 2) {
                            if (board[j][i] == BLACK && checkFree(DOWNLEFT, 2, i, j)) {
                                result += 10;
                            }
                            result += 10;
                        }
                        if (count == 4) {
                            if (board[j][i] == BLACK && checkFree(DOWNLEFT, 4, i, j)) {
                                result += 2000;
                            }
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

Boolean gomoku::checkFree(renjuType type, int renju, int i, int j) {

    if (type == RIGHT && board[j - 1][i] == EMPTY && board[j + renju][i] == EMPTY) {
        return true;
    } else if (type == DOWNRIGHT && board[j - 1][i - 1] == EMPTY && board[j + renju][i + renju] == EMPTY ) {
        return true;
    } else if (type == DOWN && board[j][i - 1] == EMPTY && board[j][i + renju] == EMPTY ) {
        return true;
    } else if (type == DOWNLEFT && board[j + 1][i - 1] == EMPTY && board[j - renju][i + renju] == EMPTY ) {
        return true;
    }

    return false;
}
