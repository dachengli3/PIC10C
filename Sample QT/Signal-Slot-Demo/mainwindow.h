#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:
    void TransmitValueOfSpinBox(int);

public slots:
    void HandleButtonPush();

private:

    void SetUpConnections();

    int times_button_was_pushed = 0;
    QPushButton* button = nullptr;
    QLabel* label = nullptr;
    QSpinBox* spin_box = nullptr;
    QVBoxLayout* layout = nullptr;
};

#endif // MAINWINDOW_H
