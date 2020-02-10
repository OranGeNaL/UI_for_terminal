#include <termios.h>
#include <unistd.h>
#include <iostream>

int getch( ) {
   struct termios oldt,
   newt;
   int ch;
   tcgetattr( STDIN_FILENO, &oldt );
   newt = oldt;
   newt.c_lflag &= ~( ICANON | ECHO );
   tcsetattr( STDIN_FILENO, TCSANOW, &newt );
   ch = std::getchar();
   if(ch == 27)
   {
       ch = std::getchar();
       ch = std::getchar();
   }
   tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
   return ch;
}