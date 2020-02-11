#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <list>
#define SIZE_X 200
#define SIZE_Y 200
#define WHITE_EMPTY "\033[47m \033[0m"

using namespace std;

class Vector2
{
private:
public:
    Vector2(int _X, int _Y) : X(_X), Y(_Y)
    {
    }
    int X, Y;
};

class UIElement
{
public:
    virtual void Draw(Vector2 vetcor2, string **frame) = 0;
};

class Dot : public UIElement
{
public:
    Vector2 position;
    Dot(int _X, int _Y) : position(_X, _Y)
    {
    }
    void Draw(Vector2 vector2, string **frame) override
    {
        frame[position.Y][position.Y] = WHITE_EMPTY;
    }

private:
};

class Text
{
public:
    string text = "";
    Vector2 position;
    Vector2 size;

private:
};

class Window : public UIElement
{
public:
    Vector2 position;
    Vector2 size;
    Window(int _X, int _Y, int _sizeX, int _sizeY) : position(_X, _Y), size(_sizeX, _sizeY)
    {
    }

    void Draw(Vector2 vector2, string **frame) override
    {
        for(int i = 0; i < size.Y; i++)
        {
            for(int j = 0; j < size.X; j++)
            {
                if(i == 0 || j == 0 || i == size.Y - 1 || j == size.X - 1)
                {
                    frame[i + position.Y][j + position.X] = WHITE_EMPTY;
                }
            }
        }
    }

private:
};

class Screen
{
public:
    list<UIElement *> draw;
    Vector2 size;

    Screen(int _sizeX, int _sizeY) : size(_sizeX, _sizeY)
    {
        framePixels = new string *[SIZE_Y];
        for (int i = 0; i < SIZE_Y; i++)
            framePixels[i] = new string[SIZE_X];
    }

    void CreateWindow(int _X, int _Y, int _sizeX, int _sizeY)
    {
        draw.push_back(new Window(_X, _Y, _sizeX, _sizeY));
    }

    void CreateDot(int _X, int _Y)
    {
        draw.push_back(new Dot(_X, _Y));
    }

    void UpdateScreen()
    {

        for (int i = 0; i < size.Y; i++)
        {
            for (int j = 0; j < size.X; j++)
            {
                framePixels[i][j] = ' ';
            }
        }

        for (auto etd : draw)
        {
            etd->Draw(size, framePixels);
        }
    }
    void PrintScreen()
    {
        UpdateScreen();
        system("clear");
        for (int i = 0; i < size.Y; i++)
        {
            for (int j = 0; j < size.X; j++)
            {
                cout << framePixels[i][j];
            }
            cout << endl;
        }
    }

private:
    string **framePixels;
};
