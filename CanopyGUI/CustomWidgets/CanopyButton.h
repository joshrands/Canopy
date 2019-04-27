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

#endif // CANOPYBUTTON_H
