#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define NUM_OF_ROWS 16
#define NUM_OF_COLS 34

void static clearScreen() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD topLeft = {0, 0};
    DWORD written;

    // Fill the entire buffer with spaces
    FillConsoleOutputCharacter(hConsole, ' ', consoleSize, topLeft, &written);
    // Reset the text attributes (colors) too
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, consoleSize, topLeft, &written);
    // Move cursor back to top-left
    SetConsoleCursorPosition(hConsole, topLeft);
}

void static mainMenu() {
    printf(" * * * * * * * * * * * * * * * *\n");
    printf("*                               *\n");
    printf("*                               *\n");
    printf("*                               *\n");
    printf("*                               *\n");
    printf("*    & & &   &     &   &    &   *\n");
    printf("*    &       & &   &   &  &     *\n");
    printf("*    & & &   &  &  &   & &      *\n");
    printf("*        &   &   & &   &  &     *\n");
    printf("*    & & &   &     &   &    &   *\n");
    printf("*              GAME             *\n");
    printf("*                               *\n");
    printf("*        PRESS X TO START       *\n");
    printf("*                               *\n");
    printf("*                               *\n");
    printf(" * * * * * * * * * * * * * * * *\n");
}
void static currentSnake(int len) {

}

void static printGameFrame(int snakeCordX, int snakeCordY) {
    int len = 3;
    //inbetween top and bottom borders
    char frameLines[NUM_OF_ROWS][NUM_OF_COLS] = {
            " * * * * * * * * * * * * * * * *",
            "*                               *",
            "*                               *",
            "*                               *",
            "*                               *",
            "*                               *",
            "*                               *",
            "*                               *",
            "*                               *",
            "*                               *",
            "*                               *",
            "*                               *",
            "*                               *",
            "*                               *",
            "*                               *",
            " * * * * * * * * * * * * * * * *"
        };

    for (int currentRow = 0; currentRow < NUM_OF_ROWS; currentRow++) {
        //this is to print the snake
        if (currentRow != snakeCordY) {
            printf("%s \n",frameLines[currentRow]);
        }else {
            for (int currentX = 0; currentX < (snakeCordX - 3); currentX++) {
                printf("%c", frameLines[currentRow][currentX]);
            }
            //might be a seperate function call in the future but we'll see
            for ( int i = 0; i < 2; i ++) {
                printf("#");
            }
            printf("@");
            for (int currentX = snakeCordX; currentX < 34; currentX++) {
                printf("%c", frameLines[currentRow][currentX]);
            }
            printf("\n");
        }
    }

}
void static changePosition(int* x, int* y, int direction) {
    switch (direction) {
        default:
        case 119:
            *y -= 1;
            break;
        case 115:
            *y += 1;
            break;
        case 97:
            *x -= 1;
            break;
        case 100:
            *x += 1;
            break;
    }

}

int main() {
    //32x17 (middle is padded by 1 for aesthetics so middle is actually 33 wide)
    //get input that will make it stop if the button x is pressed, windows library?
    int currentScore = 0;
    int currentFrame = 0;
    int snakeCordX = 14;
    int snakeCordY = 8;

    //while (currentScore < 25) {

        printGameFrame(snakeCordX, snakeCordY);
        printf("START X = %i Y = %i \n", snakeCordX, snakeCordY);
        //printf("Score=%d \n",currentScore);
        //if (_kbhit()) {
          // currentScore++;
          // int direction = getch();

            int direction1 = 100;
            changePosition(&snakeCordX, &snakeCordY, direction1);
            printGameFrame(snakeCordX, snakeCordY);
            printf("RIGHT X = %i Y = %i Pressed D %i\n", snakeCordX, snakeCordY, direction1);

            int direction2 = 115;
            changePosition(&snakeCordX, &snakeCordY, direction2);
            printGameFrame(snakeCordX, snakeCordY);
            printf("DOWN X = %i Y = %i Pressed S %i\n", snakeCordX, snakeCordY, direction2);


        //}
        //currentFrame ++;
        //printf("frame %i", currentFrame);
        //Sleep(100);
        //clearScreen();
        //fflush(stdout);
    //}

    return 0;
}

