#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QLayout>

class SecondWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SecondWindow(QWidget *parent = nullptr);

signals:

public slots:
    void ChangeText(int spinbox_value);
private:
    QLabel* text = nullptr;
    QHBoxLayout* layout = nullptr;
};

#endif // SECONDWINDOW_H
