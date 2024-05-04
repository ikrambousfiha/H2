#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <term.h>
#include <termios.h>
#include <iomanip>
#include <fcntl.h> // Include fcntl.h for file control options

using namespace std;

int height = 20;
int width = 60;
int cntAll = 0;
int cntCorrect = 0;
int Level = 0;

void hideCursor()
{
    printf("\033[?25l");
}

void showCursor()
{
    printf("\033[?25h");
}

void setColor(int foreColor, int backColor)
{
    printf("\033[%d;%dm", foreColor + 30, backColor + 40);
}

void setPosition(int x, int y)
{
    printf("\033[%d;%dH", y + 1, x + 1);
}

void showLevel()
{
    setPosition(0, height + 2);
    setColor(2, 7);
    cout << "\tCurrent Score: " << cntCorrect << "\\" << cntAll << "\t";
    if (cntAll != 0)
    {
        cout << setw(10) << right << "Level: " << Level << "\t";
    }
}

int kbhit()
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt); 
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    hideCursor();
    system("clear");
    int cursor_x, cursor_y;
    char chRandom;
    char chUserType;
    srand(unsigned(time(NULL)));
    while (true)
    {
        showLevel();
        chRandom = rand() % 26 + 'A';
        cntAll++;
        cursor_x = rand() % width;
        cursor_y = 0;
        setPosition(cursor_x, cursor_y);
        cout << chRandom << flush;
        while (cursor_y < height)
        {
            setPosition(cursor_x, cursor_y);
            setColor(rand() % 14, 7);
            cout << chRandom << flush;

            usleep(150000);
            setPosition(cursor_x, cursor_y);
            cout << " " << flush;
            cursor_y++;
            if (kbhit())
            {
                chUserType = getchar();
                if (chUserType == chRandom || chUserType + 32 == chRandom)
                {
                    cntCorrect++;
                    Level++;
                    break;
                }
                else
                {
                    Level = 0;
                }
            }
        }
    }
    showCursor();
    return 0;
}
