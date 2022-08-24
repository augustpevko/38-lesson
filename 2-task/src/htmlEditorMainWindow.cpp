#include "htmlEditorMainWindow.h"
#include "./ui_htmlEditor.h"

HtmlEditorMainWindow::HtmlEditorMainWindow(QWidget* parent): QMainWindow(parent), htmlEditorWindow(new Ui::htmlEditor) {
    htmlEditorWindow->setupUi(this);
    htmlView = htmlEditorWindow->htmlView;
    textEdit = htmlEditorWindow->textEdit;
    QObject::connect(textEdit, &QPlainTextEdit::textChanged, [this]() {
        htmlView->setHtml(textEdit->toPlainText());
    });
};

HtmlEditorMainWindow::~HtmlEditorMainWindow() {
    delete htmlEditorWindow;
}