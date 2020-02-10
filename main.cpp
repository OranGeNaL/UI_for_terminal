#include <iostream>
#include <string.h>
#include <string>
#include "UI.h"
#include "exper.h"

using namespace std;

int main()
{
    int x = 5, y = 4;
    Screen screen1 = *new Screen(50, 25);
    screen1.CreateWindow(0, 0, 30, 10);
    screen1.CreateWindow(25, 5, 30, 10);
    screen1.dotToDraw.push_back(*new Dot(x, y));
    int key = 0;

    while (true)
    {
        screen1.PrintScreen();
        cout << key;
        key = getch();
        if (key == 68)
            if (x > 0)
                x--;
        if (key == 67)
            x++;
        if (key == 65)
            if (y > 0)
                y--;
        if (key == 66)
            y++;
        screen1.dotToDraw.begin()->setX(x);
        screen1.dotToDraw.begin()->setY(y);
    }
}