#include "secondwindow.h"
#include <sstream>

SecondWindow::SecondWindow(QWidget *parent) : QWidget(parent) {
    text = new QLabel("The value of the spin down is unknown");
    layout = new QHBoxLayout();
    layout->addWidget(text);

    setLayout(layout);
}


void SecondWindow::ChangeText(int spinbox_value) {
    std::stringstream sstr;
    sstr << "The value of the spin box is: " << spinbox_value;
    std::string message = sstr.str();
    text->setText(QString::fromStdString(message));

}
