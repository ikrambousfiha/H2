#include <iostream>
#include <unistd.h> // for usleep() function
#include <termios.h> // for tcgetattr() and tcsetattr() functions
using namespace std;
#include <unistd.h> // sleeeep
#include <cstdlib> // Random
#include <ctime> 


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Function to set text color
void setcolor(const char* color) {
    std::cout << color;
}
void sleeppp(int milliseconds) {
    usleep(milliseconds * 100); 
}
char getRandomLetter() {
    return 'A' + rand() % 26; 
}
// Function to set cursor position
void setPosition(int x, int y) {
    std::cout << "\x1b[" << y << ";" << x << "H";
}

// Function to clear the screen
void clearScreen() {
    std::cout << "\x1b[2J\x1b[H";
}

// Function to disable input buffering
void disableInputBuffering() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

// Function to restore input buffering
void restoreInputBuffering() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

int main() {
    disableInputBuffering(); 
srand(time(0)); 
    char letter = getRandomLetter(); //get letterrrr
    for (int i = 0; i < 10; ++i) { 
        setcolor(ANSI_COLOR_GREEN);
        setcolor(ANSI_COLOR_RED);
        for (int j = 0; j < 5; ++j) { 
            setPosition(10, 5);
            cout << letter << std::endl;
            clearScreen();
            sleeppp(500); 
            setcolor(ANSI_COLOR_RESET);
        }
    }

    return 0;
}
