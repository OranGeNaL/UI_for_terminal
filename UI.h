#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <list>
#include "Draw.h"
#define SIZE_X 200
#define SIZE_Y 200
#define WHITE_EMPTY "\033[47m \033[0m"

using namespace std;

class IElement
{
public:
    virtual Vector2 *GetComponent(Vector2 _Vector2, string componentName) = 0;
    virtual int *GetComponent(int _int, string componentName) = 0;
    virtual string *GetComponent(char _char, string componentName) = 0;
    virtual bool *GetComponent(bool _bool, string componentName) = 0;
    virtual void Draw(Vector2 vetcor2, string **frame) = 0;
};

class Dot : public IElement
{
public:
    Vector2 position;
    string name;
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

class Window : public IElement
{
public:
    Color color;
    Vector2 position;
    Vector2 size;
    string name;
    string backgroud = "white";
    string textColor = "black";
    bool fill = false;
    Window(int _X, int _Y, int _sizeX, int _sizeY, string _name) : position(_X, _Y), size(_sizeX, _sizeY), name(_name)
    {
    }

    void Draw(Vector2 vector2, string **frame) override
    {
        for (int i = 0; i < size.Y; i++)
        {
            for (int j = 0; j < size.X; j++)
            {
                if (!fill)
                {
                    if (i == 0 || j == 0 || i == size.Y - 1 || j == size.X - 1)
                    {
                        frame[i + position.Y][j + position.X] = color.Paint(backgroud, textColor, " ");
                    }
                }

                else
                {
                    frame[i + position.Y][j + position.X] = WHITE_EMPTY;
                }
            }
        }
    }

    string *GetComponent(char _char, string componentName) override
    {
        if (componentName == "name")
        {
            return &name;
        }

        return NULL;
    }

    int *GetComponent(int _int, string componentName) override
    {
    }

    Vector2 *GetComponent(Vector2 _Vector2, string componentName) override
    {
        if (componentName == "position")
        {
            return &position;
        }

        if (componentName == "size")
        {
            return &size;
        }

        return NULL;
    }

    bool *GetComponent(bool _bool, string componentName) override
    {
        if (componentName == "fill")
        {
            return &fill;
        }
        return NULL;
    }

private:
};

class Screen
{
public:
    list<IElement *> draw;
    Vector2 size;

    Screen(int _sizeX, int _sizeY) : size(_sizeX, _sizeY)
    {
        framePixels = new string *[SIZE_Y];
        for (int i = 0; i < SIZE_Y; i++)
            framePixels[i] = new string[SIZE_X];
    }

    void CreateWindow(int _X, int _Y, int _sizeX, int _sizeY, string _name)
    {
        draw.push_back(new Window(_X, _Y, _sizeX, _sizeY, _name));
    }

    void CreateDot(int _X, int _Y)
    {
        // draw.push_back(new Dot(_X, _Y));
    }

    IElement *FindElement(string _name)
    {
        for (auto el : draw)
        {
            if (*el->GetComponent(' ', "name") == _name)
            {
                return el;
            }
        }

        return NULL;
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
