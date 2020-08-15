#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <vector>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr); //declaration of parents and setup of buttons/cnnections
        QPushButton* button = nullptr;
        void SetUpConnections();

signals:    //transmission of box values separately
    void TransmitValueOfFirstBox(int);
    void TransmitValueOfSecondBox(int);

public slots:   //sending info
    void HandleButtonPush();
    void keyPressEvent(QKeyEvent *event);   //enabling key controls

private:
    QLabel* label = nullptr;
    QSpinBox* spin_box = nullptr;
    QSpinBox* second_box = nullptr; //declaration of spinboxes
    QVBoxLayout* layout = nullptr;
};

#endif // MAINWINDOW_H
