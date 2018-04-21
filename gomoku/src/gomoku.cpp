#include "gomoku.h"
#include <math.h>


//--------------------------------------------------------------
void gomoku::setup(){

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            board[i][j] = EMPTY;
        }
    }


    ofSetBackgroundColor(182, 155, 76);

    intersection.r = 169;
    intersection.g = 169;
    intersection.b = 169;

    current_draw = MAKE_BLACK;
    current_state = START;
    
    unit_width = ofGetWindowWidth() / size;
    unit_height = ofGetWindowHeight() / size;


}

//--------------------------------------------------------------
void gomoku::update(){

}

//--------------------------------------------------------------
void gomoku::draw(){
    if (current_state == START) {
        drawBoard();
    }
    
        if (current_state == PLACE) {
            
            if (current_draw == MAKE_BLACK) {
                ofSetColor(0, 0, 0);
                ofDrawCircle(xPos, yPos, 25);
                board[(xPos / unit_width) - 1][(yPos / unit_height) - 1] = BLACK;

            } else if (current_draw == MAKE_WHITE) {
                ofSetColor(255, 255, 255);
                ofDrawCircle(xPos, yPos, 25);
                board[(xPos / unit_width) - 1][(yPos / unit_height) - 1] = WHITE;


            }
        }
    
       else if (current_state == END) {
        ofSetColor(0, 0, 0);
        ofDrawBitmapString(winner + " has won!\nPress R to restart!", ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
    }

}

//--------------------------------------------------------------
void gomoku::keyPressed(int key){
    int upper_key = toupper(key); // Standardize on upper case
    
    if (upper_key == 'R' && current_state == END) {
        // Pause or unpause
        current_state = START;
        ofClear(182, 155, 76);
        memset(board, 0, sizeof(board));
        draw();
    }
}

//--------------------------------------------------------------
void gomoku::keyReleased(int key){

}

//--------------------------------------------------------------
void gomoku::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void gomoku::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void gomoku::mousePressed(int x, int y, int button){
    if (button == 0) {
        if (autoDraw(x, y)) {
            current_state = PLACE;
            draw();
            //printBoard();
            
            if (isWin()) {
                //std::cout << "win!" << std::endl;
                current_state = END;
                draw();
            }
            
            
            if (current_state != END) {
                changeTurn();
                placeUnder((xPos / unit_width), (yPos / unit_height));
                current_state = NO_PLACE;
            }

        }
    }
}

//--------------------------------------------------------------
void gomoku::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void gomoku::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void gomoku::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void gomoku::windowResized(int w, int h){

}

//--------------------------------------------------------------
void gomoku::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void gomoku::dragEvent(ofDragInfo dragInfo){

}

void gomoku::drawBoard(){
    for (int y = 0; y < ofGetWindowHeight(); y += ofGetWindowHeight()/size) {
        ofSetColor(0, 0, 0);
        ofDrawLine(0, y, ofGetWindowWidth() , y);
    }

    for (int x = 0; x < ofGetWindowWidth(); x+=ofGetWindowWidth()/size) {
        ofSetColor(0, 0, 0);
        ofDrawLine(x, 0, x , ofGetWindowHeight());
    }

    for (int x = 0; x < ofGetWindowWidth(); x++) {
        for (int y = 0; y < ofGetWindowHeight(); y++) {
            if (isIntersection(x, y)){
                ofSetColor(intersection);
                ofDrawCircle(x, y, 5);
            }
        }
    }
}

Boolean gomoku::isIntersection(int x, int y) {
    if (x == 0 || y == 0) {
        return false;
    }
    return ((x % (ofGetWindowWidth() / size) == 0) && (y % (ofGetWindowHeight() / size) == 0));
}

Boolean gomoku::autoDraw(int x, int y) {
    if (current_state == END) {
        return false;
    }
    if (isIntersection(x, y)){
        xPos = x;
        yPos = y;
        if (board[(xPos / unit_width) - 1][(yPos / unit_height) - 1] == EMPTY) {
            return true;
        } else {
            return false;
        }
    }
    for (int xp = 0; xp < ofGetWindowWidth(); xp++) {
        for (int yp = 0; yp < ofGetWindowHeight(); yp++) {
            if (isIntersection(xp, yp) && (sqrt(pow((xp - x), 2) + pow((yp-y), 2))) <= 5){
                xPos = xp;
                yPos = yp;
                if (board[(xPos / unit_width) - 1][(yPos / unit_height) - 1] == EMPTY) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
    return false;
}

void gomoku::changeTurn() {
    if (current_draw == MAKE_BLACK) {
        current_draw = MAKE_WHITE;

    } else {
        current_draw = MAKE_BLACK;

    }
}

//printing the trasnpose of the matrix, which digitally visulizes the game board and stones.
void gomoku::printBoard() {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            std::cout << board[j][i];
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
}

void gomoku::getWinnerName(int num) {
    if (num == BLACK) {
        winner = "Black";
    } else {
        winner = "White";
    }
}

Boolean gomoku::isWin() {
    
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            int current_color = board[j][i];

            //skip the ones that are in the middle of a connection (only validate the ones that are at front)

            
                
            //check right - connect 5
            if (board[j][i] != EMPTY && (j + 4) <= (size - 2)) {
                for (int count = 1; count < 5; count++) {
                    if (board[j + count][i] == current_color) {
                        if (count == 4) {
                            getWinnerName(current_color);
                            return true;
                        }
                    } else {
                        break;
                    }
                }
            }
            
            //check downward right - connect 5
            if (board[j][i] != EMPTY && (i + 4) <= (size - 2) && (j + 4) <= (size - 2)) {
                int current_color = board[j][i];
                for (int count = 1; count < 5; count++) {
                    if (board[j + count][i + count] == current_color) {
                        if (count == 4) {
                            getWinnerName(current_color);
                            return true;
                        }
                    } else {
                        break;
                    }
                }
            }
            
            //check downward - connect 5
            if (board[j][i] != EMPTY && (i + 4) <= (size - 2)) {
                int current_color = board[j][i];
                for (int count = 1; count < 5; count++) {
                    if (board[j][i + count] == current_color) {
                        if (count == 4) {
                            getWinnerName(current_color);
                            return true;
                        }
                    } else {
                        break;
                    }
                }
            }
            
            //check downward left - connect 5
            
            if (board[j][i] != EMPTY && (i + 4) <= (size - 2) && (j - 4) >= 0) {
                int current_color = board[j][i];
                for (int count = 1; count < 5; count++) {
                    if (board[j - count][i + count] == current_color) {
                        if (count == 4) {
                            getWinnerName(current_color);
                            return true;
                        }
                    } else {
                        break;
                    }
                }
            }
        }
    }
    return false;
}
