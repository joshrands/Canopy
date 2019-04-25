#ifndef EMAILCONTENTWINDOW_H
#define EMAILCONTENTWINDOW_H

#include <QFrame>

namespace Ui {
class EmailContentWindow;
}

class EmailContentWindow : public QFrame
{
    Q_OBJECT

public:
    explicit EmailContentWindow(QWidget *parent = 0);
    ~EmailContentWindow();

private:
    Ui::EmailContentWindow *ui;
};

#endif // EMAILCONTENTWINDOW_H
