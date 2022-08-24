#pragma once
#include <QMainWindow>
#include <QWebEngineView>
#include <QPlainTextEdit>

namespace Ui { 
    class htmlEditor; 
}

class HtmlEditorMainWindow: public QMainWindow {
    Q_OBJECT
    Ui::htmlEditor* htmlEditorWindow = nullptr;
    QWebEngineView* htmlView = nullptr;
    QPlainTextEdit* textEdit = nullptr;

public:
    explicit HtmlEditorMainWindow(QWidget* parent = nullptr);
    ~HtmlEditorMainWindow();
};