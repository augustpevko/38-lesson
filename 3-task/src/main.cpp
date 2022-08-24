#include <QApplication>
#include "blurMainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    BlurMainWindow window(nullptr);
    window.show();
    
    return QApplication::exec();
}