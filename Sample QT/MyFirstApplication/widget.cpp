#include "widget.h"
#include <QLabel>
#include <QLayout>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent) {
    QHBoxLayout* main_layout = new QHBoxLayout();
    QLabel* label_hello = new QLabel("Hello");
    QLabel* label_world = new QLabel("World!");

    main_layout->addWidget(label_hello);
    main_layout->addWidget(label_world);

    QWidget* vertically_layout_widget = new QWidget;
    QLabel* label_1 = new QLabel("You are in ");
    QLabel* label_2 = new QLabel("A Vertical Layout");
    QVBoxLayout* v_layout = new QVBoxLayout;
    v_layout->addWidget(label_1);
    v_layout->addWidget(label_2);
    vertically_layout_widget->setLayout(v_layout);
    main_layout->addWidget(vertically_layout_widget);

    this->setLayout(main_layout);
}

Widget::~Widget()
{

}
