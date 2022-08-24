#include <QApplication>
#include "htmlEditorMainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    HtmlEditorMainWindow window(nullptr);
    window.show();
    
    return QApplication::exec();
}