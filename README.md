# CS 126 FinalProject - Gomoku
## What is Gomoku?
Gomoku, also called Gobang or Five in a Row, is an abstract strategy board game. It is traditionally played with Go pieces (black and white stones) on a Go board, using 15×15 of the 19×19 grid intersections.

## What did I do for my project?
I did a frontend realization of a 15*15 game board for gomoku. Also, I designed an AI player to play with me.

## How did I do the user interface?
I set the background color to be the same as wood, the I draw lines in both horizontal and vertical directions. The intersections of the lines are points where we can place the Go pieces. <br>
The user can click at any point that has a distance within 5 from the intersection. So even if the user didn't click right on the intersection, the user can still draw a piece that at point. The program will automatically generate a piece at which is the closest to where the user clicks.  <br>

## How did I do the AI part?
I tried to read documentations of minimax trees and alpha-beta pruning, but I still found it hard to implement these techniques to my project. However, I still managed to create a simpler AI by myself. <br>
The first thing I did is to set up a function that giving a rating to the current turn. For instance, if one has three pieces in a row, one can have a 500 points for that turn. The higher the points, the more likely for that plater to achieve a five in a row. <br>
So for my AI, I simulated how the opponent will move, and suppose that the opponent will place his/her piece at the point that will create the highest points for that turn. Then, I place my piece at that position to prevent the opponent from achieving that situation. Hence, my AI is able to block most of the moves of the opponent's.

## Visual example of the Game:
![](https://github.com/uiuc-sp18-cs126/final-project-rickypeng99/raw/master/graph.jpg)<br>

## Library using:
math library <br>
I need to write equations with it. <br>
BigNumber - C++ class for creating and computing arbitrary-length integers
