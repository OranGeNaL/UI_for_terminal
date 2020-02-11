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
    screen1.PrintScreen();
    int key = 0;
}