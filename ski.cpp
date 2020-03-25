#include <iostream> // For cin and cout
#include <stdlib.h> // The .h tells us this is a C include file
                    // We use this for the rand() function.
#include <unistd.h> // We're using it to get access to the sleep function call
                    // Uni = Unix; if on windows, or mac, you might need
                    //             something else for usleep()
#include "rawkb.h"  // Some ugly, non-portable code to get keypresses in Linux
using namespace std;

const int screen_width = 77; // How wide is the window? 
const int delay = 70000; // Change this to alter speed

void print_opening_banner() 
{
        cout << "=";
        for (int i = 0; i < (screen_width-3); i++)
            cout << "-";
        cout << "=" << endl;

        cout << endl << "\t D O W N H I L L     S K I     C H A L L E N G E" << endl << endl;
        cout << "\t\t  Use the '<' and '>' keys to steer!" << endl;
        cout << "\t\t   (less than)    (greater than)" << endl << endl;

        cout << "=";
        for (int i = 0; i < (screen_width-3); i++)
            cout << "-";
        cout << "=" << endl;
}

void printGameOver(int score)
{
    cout << " _______  _______  __   __  _______    _______  __   __  _______  ______ \n|       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |\n|    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||\n|   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_ \n|   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  |\n|   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | |\n|_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_|" <<endl;
    cout << "Y O U  S C O R E D: " << score << " points" << endl;
}

int main() 
{
    label:
    srand(4010); // random seed, so you can repeat a game

    print_opening_banner();

    int skill = -1;
    while ((skill < 1) || (skill > 10)) {   
        cout << "Please enter a difficulty level (between 1-10): ";
        cin >> skill;
    }   

    int gapsize = 25-skill; // Wide of the white stripe: 15 - 24 gives a good range
    int side_pos = screen_width/2 - gapsize/2; // Start ski run in the center
    int player_pos = gapsize/2; // Start player in the center of the run
    bool game_over = false; // Is the player alive?
    int score = 0;
    while (!game_over) {
        // This gives a uniform random number between 0 and 1 
        float random_num = ((float)rand())/RAND_MAX; 
        int delta = 0; // Describes how much the left wall shifts
        if (random_num < 0.133)  // Two steps left some of the time
            delta = -2;
        else if (random_num < 0.333)  // One step left some of the time
            delta = -1;
        else if (random_num > 0.867) // etc.
            delta = 2;
        else if (random_num > 0.667) // etc. (Note that order mattered here.)
            delta = 1;

        if ((side_pos < 2) && (delta < 0)) // We don't let side_pos get too small 
                delta = 0;
        if ((side_pos > screen_width-2) && (delta > 0))  // We don't let side_pos get toobig  
                delta = 0;

        side_pos = side_pos + delta; // Shift left wall
        player_pos = player_pos - delta; // Compensate to keep player straight

        if (_kbhit()) { // A key has been pressed.
            char c = cin.get(); // Which key?
            if ((c == ',') || (c == '<')) // Move player left
                player_pos--; 
            else if ((c == '.') || (c == '>')) // Move player right
                player_pos++;
            else
                return 0; // Take everything else as a quit signal.
            cout << "\b"; // Gobble the key
        }
        
        if ((player_pos <= 1) || (player_pos >= gapsize-1)) // collided into obstacles
            game_over = true;

        for (int i = 0; i < side_pos ; i++) // print obstacles on the left
            cout << ".";

        for (int i = 0; i < player_pos-1; i++) cout << " "; // print left space
        if (!game_over) // print character
            cout << "*";
        else 
            cout << "_"; // Show a faceplant!

        for (int i = 0; i < (gapsize-player_pos)-1; i++) // print right space
            cout << " ";

        for (int i = 0; i < screen_width - (side_pos + gapsize); i++) // print obstacles on the right 
            cout << ".";
        cout << endl;

        usleep(delay); // slow things down by waiting a bit
        score++;
    } // while not game over, loop
    printGameOver(score);
    cout << "Play again [Y/N]: ";
    char answer;
    cin >> answer;
    if(tolower(answer) == 'y')
    {
        cout << endl;
        goto label;
    }
    return 0;
}