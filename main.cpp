#include <iostream>
#include <string.h>
#include <string>
#include "UI.h"
#include "exper.h"
#include "Draw.h"

using namespace std;

int main()
{
    int x = 5, y = 4;
    Screen screen1 = *new Screen(100, 25);
    screen1.CreateWindow(0, 0, 30, 10, "Window1");
    screen1.CreateWindow(25, 5, 50, 10, "Window2");
    //screen1.CreateDot(15, 20);
    screen1.PrintScreen();
    getch();
    screen1.FindElement("Window1")->GetComponent(Vector2(0,0), "position")->Set(15, 20);
    screen1.PrintScreen();
    getch();
    screen1.FindElement("Window1")->GetComponent(Vector2(0,0), "position")->Set(screen1.FindElement("Window2")->GetComponent(Vector2(0,0), "position")->Get());
    screen1.PrintScreen();
    int key = 0;
}