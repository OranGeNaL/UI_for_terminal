#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <list>
#define SIZE_X 200
#define SIZE_Y 200
#define WHITE_EMPTY "\033[47m \033[0m"

using namespace std;

class Text
{
public:
private:
    string text = "";
    int X, Y;
    int sizeX, sizeY;
};

class Dot
{
    public:
    Dot(int _X, int _Y)
    {
        X = _X;
        Y = _Y;
    }
    void setX(int _X)
    {
        X = _X;
    }
    void setY(int _Y)
    {
        Y = _Y;
    }
    int getX()
    {
        return X;
    }
    int getY()
    {
        return Y;
    }
    private:
    int X, Y;
};

class Window
{
public:
    Window(int _X, int _Y, int _sizeX, int _sizeY)
    {
        X = _X;
        Y = _Y;
        sizeX = _sizeX;
        sizeY = _sizeY;
    }
    int getX()
    {
        return X;
    }
    int getY()
    {
        return Y;
    }
    int getSizeX()
    {
        return sizeX;
    }
    int getSizeY()
    {
        return sizeY;
    }
private:
    //X and Y coorfinates of upper-left corner
    int X, Y;
    //X and Y size from upper-left corner
    int sizeX, sizeY;
};

class Screen
{
public:
    list<Window> windowsToDraw;
    list<Dot> dotToDraw;

    Screen(int _sizeX, int _sizeY)
    {
        sizeX = _sizeX;
        sizeY = _sizeY;
    }

    void CreateWindow(int _X, int _Y, int _sizeX, int _sizeY)
    {
        Window newWindow = *new Window(_X, _Y, _sizeX, _sizeY);
        windowsToDraw.push_back(newWindow);
    }

    void UpdateScreen()
    {
        for (int i = 0; i < sizeY; i++)
        {
            for (int j = 0; j < sizeX; j++)
            {
                framePixels[i][j] = ' ';
            }
        }
        for(auto wtd : windowsToDraw)
        {
            for(int i = wtd.getY(); i < wtd.getY() + wtd.getSizeY(); i++)
            {
                for(int j = wtd.getX(); j < wtd.getX() + wtd.getSizeX(); j++)
                {
                    if(i == wtd.getY() || i == wtd.getY() + wtd.getSizeY() - 1 || j == wtd.getX() || j == wtd.getX() + wtd.getSizeX() - 1)
                    {
                        framePixels[i][j] = WHITE_EMPTY;
                    }
                }
            }
        }
        for(auto dtd : dotToDraw)
        {
            framePixels[dtd.getY()][dtd.getX()] = WHITE_EMPTY;
        }
    }
    void PrintScreen()
    {
        UpdateScreen();
        system("clear");
        for (int i = 0; i < sizeY; i++)
        {
            for (int j = 0; j < sizeX; j++)
            {
                cout << framePixels[i][j];
            }
            cout << endl;
        }

        /*for (int i = 0; i < sizeY; i++)
        {
            for (int j = 1; j <= LEFT_BORDER; j++)
            {
                cout << WHITE_EMPTY;
            }

            for (int j = 0; j < sizeX; j++)
            {
                cout << framePixels[i][j];
            }

            for (int j = 1; j <= RIGHT_BORDER; j++)
            {
                cout << WHITE_EMPTY;
            }

            cout << endl;
        }*/
    }

private:
    string framePixels[SIZE_Y][SIZE_X];
    int sizeX, sizeY;
};
