#include <QApplication>
#include <QPalette>
#include <iostream>
#include "button.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    SoundButton button(nullptr);

    button.show();
    return QApplication::exec();
}