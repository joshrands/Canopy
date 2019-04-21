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

protected:
    Ui::ContentWindow *ui;
};

class EmailContentWindow : public ContentWindow
{
public:
    EmailContentWindow();

};

class HtmlContentWindow : public ContentWindow
{
public:
    HtmlContentWindow();

};

#endif // CONTENTWINDOW_H
