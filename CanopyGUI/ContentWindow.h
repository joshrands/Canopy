#ifndef CONTENTWINDOW_H
#define CONTENTWINDOW_H

#include <QFrame>

namespace Ui {
class ContentWindow;
}

class ContentWindow : public QFrame
{
    Q_OBJECT

public:
    explicit ContentWindow(QWidget *parent = 0);
    ~ContentWindow();

private:
    Ui::ContentWindow *ui;
};

class EmailContentWindow : public ContentWindow
{

};

class HtmlContentWindow : public ContentWindow
{

};

#endif // CONTENTWINDOW_H
