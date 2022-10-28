// simpleSnake.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Josue Martinez

#include <iostream>
#include <conio.h>
using namespace std;
bool gameOver;

// Map Dimensions
// width of the game
const int width = 20;

//height of the game
const int height = 20;
//Snake and fruit headings (location)
int x, y, fruitX, fruitY, score;

// Will Control the direction of the snake
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

// holds direction of the snake
eDirection dir;

void Setup() {
    // Set the game to running
    gameOver = false;
    
    // Start the snakes direction to the stop position
    dir = STOP;
    
    // Set the snakehead to be in the middle of the width
    x = width/2;
    
    // Set the snakehead to be in the middle of the height
    y = height/2;

    //assign the x coordinate of fruits to a random space between 0 and width - 1
    fruitX = rand() % width;
    
    //assign the y coordinate of fruits to a random space between 0 and height - 1
    fruitY = rand() % height;
    score = 0;
}

void Draw() {
    // Clear the screen (the console window)
    system("cls");

    // Display the top border of the map
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    
    // Print The Map 

    // For each space in the height
    for (int i = 0; i < height; i++) {
        
        // For each space in the width
        for (int j = 0; j < width; j++) {
            
            // if j is the first field
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
                cout << " ";
            
            if (j == width-1)
                cout << "#";
        }

        cout << endl;
        
    }

    //display the bottom border of the map
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;

}

void Input() {
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        
        }
    }
}

void Logic() {
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x > width || x < 0 || y > height || y < 0)
        gameOver = true;
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
} 
int main()
{
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        //Sleep(10)
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
