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
    virtual void Draw(Vector2 vetcor2, string frame[SIZE_Y][SIZE_X]) = 0;
};

class Dot
{
    public:
    Vector2 position;
    Dot(int _X, int _Y) : position(_X, _Y)
    {
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

    void Draw(Vector2 vector2, string frame[SIZE_Y][SIZE_X]) override
    {
        cout << "draw\n";
    }
private:
};

class Screen
{
public:
    list<Window> windowsToDraw;
    list<UIElement*> draw;
    list<Dot> dotToDraw;
    Vector2 size;

    Screen(int _sizeX, int _sizeY) : size(_sizeX, _sizeY)
    {
    }

    void CreateWindow(int _X, int _Y, int _sizeX, int _sizeY)
    {
        Window newWindow = *new Window(_X, _Y, _sizeX, _sizeY);
        windowsToDraw.push_back(newWindow);
        draw.push_back(&newWindow);
    }

    void UpdateScreen()
    {
        // for (int i = 0; i < size.Y; i++)
        // {
        //     for (int j = 0; j < size.X; j++)
        //     {
        //         framePixels[i][j] = ' ';
        //     }
        // }
        // for(auto wtd : windowsToDraw)
        // {
        //     for(int i = wtd.position.Y; i < wtd.position.Y + wtd.size.Y; i++)
        //     {
        //         for(int j = wtd.position.X; j < wtd.position.X + wtd.size.X; j++)
        //         {
        //             if(i == wtd.position.Y || i == wtd.position.Y + wtd.size.Y - 1 || j == wtd.position.X || j == wtd.position.X + wtd.size.X - 1)
        //             {
        //                 framePixels[i][j] = WHITE_EMPTY;
        //             }
        //         }
        //     }
        // }
        // for(auto dtd : dotToDraw)
        // {
        //     framePixels[dtd.position.Y][dtd.position.X] = WHITE_EMPTY;
        // }

        for(auto etd : draw)
        {
            etd->Draw(size, &framePixels[0]);
        }
    }
    void PrintScreen()
    {
        UpdateScreen();
        //system("clear");
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
    string framePixels[SIZE_Y][SIZE_X];
};
