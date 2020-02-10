#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

struct ProgressBar
{
public:
    ProgressBar(int newVerSize, int newHorSize, int newMax, int *newCur)
    {
        verSize = newVerSize;
        horSize = newHorSize;
        maxValue = newMax;
        curValue = newCur;
        UpdateBar();
    }
    void UpdateBar()
    {
        ClearBar();
        for (int i = 0; i < horSize + 2; i++)
        {
            if (i == 0 || i == horSize + 1)
                lines[0][i] = ' ';
            else
                lines[0][i] = '-';
        }
        lines[0][horSize + 2] = '\0';

        partSize = *curValue * horSize / maxValue;
        for (int i = 0; i < horSize + 2; i++)
        {
            if (i == 0 || i == horSize + 1)
            {
                lines[1][i] = '|';
            }
            else
            {
                if (i <= partSize)
                    lines[1][i] = '#';
                else
                    lines[1][i] = ' ';
            }
        }
        lines[1][horSize + 2] = '\0';
    }
    void PrintBar()
    {
        UpdateBar();
        cout << lines[0] << endl;
        for (int i = 1; i <= verSize; i++)
            cout << lines[1] << endl;
        cout << lines[0] << endl;
    }
    void ClearBar()
    {
        int len = strlen(lines[0]);
        for (int i = 0; i < len; i++)
        {
            lines[0][i] = '\0';
            lines[1][i] = '\0';
        }
    }

private:
    char lines[2][1003]; //0 is for horizontal lines
    int verSize;
    int horSize;
    int maxValue;
    int *curValue;
    int partSize;
};

struct TextProgressBar
{
public:
    TextProgressBar(int newVerSize, int newHorSize, int newMax, int *newCur, string newText)
    {
        text = newText;
        verSize = newVerSize;
        horSize = newHorSize;
        maxValue = newMax;
        curValue = newCur;
        UpdateBar();
        int i;
    }
    void UpdateBar()
    {
        ClearBar();
        for (int i = 0; i < horSize + 2; i++)
        {
            if (i == 0 || i == horSize + 1)
                lines[0][i] = ' ';
            else
                lines[0][i] = '-';
        }
        lines[0][horSize + 2] = '\0';

        partSize = *curValue * horSize / maxValue;

        for (int i = 0; i < horSize + 2; i++)
        {
            if (i == 0 || i == horSize + 1)
            {
                lines[1][i] = '|';
                lines[2][i] = '|';
            }
            else
            {
                if (i <= partSize)
                {
                    lines[1][i] = '#';
                    lines[2][i] = '#';
                }
                else
                {
                    lines[1][i] = ' ';
                    lines[2][i] = ' ';
                }
            }
        }
        lines[1][horSize + 2] = '\0';
        lines[2][horSize + 2] = '\0';

        string outputText = text + to_string(*curValue) + '/' + to_string(maxValue);
        int shift = (horSize - outputText.length()) / 2;
        for (int i = 0; i < outputText.length(); i++)
        {
            lines[2][i + shift] = outputText[i];
        }
        int i;
    }
    void PrintBar()
    {
        UpdateBar();
        cout << lines[0] << endl;
        for (int i = 1; i <= verSize; i++)
        {
            if(verSize != 1)
            {
                if (i == verSize / 2 + 1)
                    cout << lines[2] << endl;
                else
                    cout << lines[1] << endl;
            }
            else
            {
                cout << lines[2] << endl;
            }
            
        }
        cout << lines[0] << endl;
    }
    void ClearBar()
    {
        int len = strlen(lines[0]);
        for (int i = 0; i < len; i++)
        {
            lines[0][i] = '\0';
            lines[1][i] = '\0';
        }
    }

private:
    char lines[3][1003]; //0 is for horizontal lines
    //char text[1003];
    string text;
    int verSize;
    int horSize;
    int maxValue;
    int *curValue;
    int partSize;
};

struct PercentProgressBar
{
public:
    PercentProgressBar(int newVerSize, int newHorSize, int *newMax, int *newCur, string newText)
    {
        text = newText;
        verSize = newVerSize;
        horSize = newHorSize;
        maxValue = newMax;
        curValue = newCur;
        UpdateBar();
        int i;
    }
    void UpdateBar()
    {
        ClearBar();
        for (int i = 0; i < horSize + 2; i++)
        {
            if (i == 0 || i == horSize + 1)
                lines[0][i] = ' ';
            else
                lines[0][i] = '-';
        }
        lines[0][horSize + 2] = '\0';

        partSize = *curValue * horSize / *maxValue;

        for (int i = 0; i < horSize + 2; i++)
        {
            if (i == 0 || i == horSize + 1)
            {
                lines[1][i] = '|';
                lines[2][i] = '|';
            }
            else
            {
                if (i <= partSize)
                {
                    lines[1][i] = '#';
                    lines[2][i] = '#';
                }
                else
                {
                    lines[1][i] = ' ';
                    lines[2][i] = ' ';
                }
            }
        }
        lines[1][horSize + 2] = '\0';
        lines[2][horSize + 2] = '\0';

        int percents = 0;
        percents = *curValue * 100 / *maxValue;

        string outputText = text + to_string(percents) + "%";
        int shift = (horSize - outputText.length()) / 2;
        for (int i = 0; i < outputText.length(); i++)
        {
            lines[2][i + shift] = outputText[i];
        }
        int i;
    }
    void PrintBar()
    {
        UpdateBar();
        cout << lines[0] << endl;
        for (int i = 1; i <= verSize; i++)
        {
            if(verSize != 1)
            {
                if (i == verSize / 2 + 1)
                    cout << lines[2] << endl;
                else
                    cout << lines[1] << endl;
            }
            else
            {
                cout << lines[2] << endl;
            }
            
        }
        cout << lines[0] << endl;
    }
    void ClearBar()
    {
        int len = strlen(lines[0]);
        for (int i = 0; i < len; i++)
        {
            lines[0][i] = '\0';
            lines[1][i] = '\0';
        }
    }

private:
    char lines[3][1003]; //0 is for horizontal lines
    //char text[1003];
    string text;
    int verSize;
    int horSize;
    int *maxValue;
    int *curValue;
    int partSize;
};

int main()
{
    int value = 1;
    int maxValue = 50;
    ProgressBar bar1 = *new ProgressBar(1, 20, maxValue, &value);
    TextProgressBar bar2 = *new TextProgressBar(1, 20, maxValue, &value, "Sample: ");
    PercentProgressBar bar3 = *new PercentProgressBar(1, 20, &maxValue, &value, "Sample: ");

    bar1.PrintBar();
    bar2.PrintBar();
    bar3.PrintBar();

    value = 25;

    bar1.PrintBar();
    bar2.PrintBar();
    bar3.PrintBar();
}