#ifndef CANOPYBUTTON_H
#define CANOPYBUTTON_H

#include <QPushButton>

class CanopyButton : public QPushButton
{
public:
    CanopyButton();

    void setPressed();
    void setDepressed();

private:
    bool pressed;
};

class FlagButton : public CanopyButton
{
public:
    FlagButton();

    void setOn();
    void setOff();

    bool isToggled() { return this->toggled; }
    void toggle() { this->toggled = !this->toggled; }

protected:
    bool toggled;
};

#endif // CANOPYBUTTON_H
