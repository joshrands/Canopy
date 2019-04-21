#ifndef SESSIONWINDOW_H
#define SESSIONWINDOW_H

#include <QMainWindow>

namespace Ui {
class SessionWindow;
}

class SessionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SessionWindow(QWidget *parent = 0);
    ~SessionWindow();

private:
    Ui::SessionWindow *ui;
};

#endif // SESSIONWINDOW_H
