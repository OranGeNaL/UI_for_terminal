#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#define SIZE_X 52
#define SIZE_Y 27

using namespace std;

struct Screen
{
    public:
    void ClearScreen()
    {
        for(int i = 0; i < SIZE_Y; i++)
        {
            for(int j = 0; j < SIZE_X; j++)
            {
                if((i == 0 && j == 0) ||
                (i == SIZE_Y - 1 && j == 0) ||
                (i == SIZE_Y - 1 && j == SIZE_X - 1) ||
                (i == 0 && j == SIZE_X - 1))
                {
                    framePixels[i][j] = ' ';
                }

                else if(i == 0 || i == SIZE_Y - 1)
                {
                    framePixels [i][j] = '-';
                }
                else if(j == 0 || j == SIZE_X - 1)
                {
                    framePixels [i][j] = '|';
                }
                else
                {
                    framePixels[i][j] = ' ';
                }
            }
        }

        for(int i = 0; i < SIZE_Y; i++)
        {
            for(int j = 0; j < SIZE_X; j++)
            {
                frame += framePixels[i][j];
            }
            frame += '\n';
        }
    }
    void PrintScreen()
    {
        ClearScreen();
        cout << frame;
    }
    private:
    char framePixels[SIZE_Y][SIZE_X];
    string frame = "";
};