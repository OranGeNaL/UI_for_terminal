#include <string.h>
#include <string>
#include <map>

class Vector2
{
private:
public:
    int X, Y;
    Vector2()
    {

    }
    Vector2(int _X, int _Y) : X(_X), Y(_Y)
    {
    }
    void Set(int _X, int _Y)
    {
        X = _X;
        Y = _Y;
    }
    void Set(Vector2 _Vector2)
    {
        X = _Vector2.X;
        Y = _Vector2.Y;
    }
    void Set(Vector2* _Vector2)
    {
        X = _Vector2->X;
        Y = _Vector2->Y;
    }
    Vector2 * Get()
    {
        return this;
    }
};

class Switch
{
    private:
    public:
    bool switchValue = false;
    Switch()
    {
    }
    Switch(bool value) : switchValue(value)
    {
    }

    void Set(bool value)
    {
        switchValue = value;
    }
    void Set(Switch _switch)
    {
        switchValue = _switch.switchValue;
    }
    void Set(Switch *_switch)
    {
        switchValue = _switch->switchValue;
    }
    Switch *Get()
    {
        return this;
    }
};

class Color
{
    public:
    std::map<std::string, std::string> textColor = {
        {"black", "30"},
        {"red", "31"},
        {"green", "32"},
        {"yellow", "33"},
        {"blue", "34"},
        {"magenta", "35"},
        {"cyan", "36"},
        {"white", "37"}
    };
    std::map<std::string, std::string> background = {
        {"black", "40"},
        {"red", "41"},
        {"green", "42"},
        {"yellow", "43"},
        {"blue", "44"},
        {"magenta", "45"},
        {"cyan", "46"},
        {"white", "47"}
    };
    Color()
    {

    }
    std::string Paint(std::string _background, std::string _textColor, std::string text)
    {
        std::string result = "";
        result += "\033[" + textColor.find(_textColor)->second + ';' + background.find(_background)->second + 'm' + text + "\033[0m";
        return result;
    }
};