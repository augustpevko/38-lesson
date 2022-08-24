#pragma once
#include <QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QLabel>

#include <QGraphicsScene>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QImage>

#include <QDir>
#include <QFileDialog>

namespace Ui { 
    class BlurWindow; 
}

class BlurMainWindow: public QMainWindow {
    Q_OBJECT
    Ui::BlurWindow* blurWindow = nullptr;
    QPushButton* openButton = nullptr;
    QSlider* blurSlider = nullptr;
    QLabel* imgLabel = nullptr;
    QImage qBlurImage;
    QString currentDir;

public:
    explicit BlurMainWindow(QWidget* parent = nullptr);
    ~BlurMainWindow();

    QImage blurImage(QImage source, int blurRadius);
public slots:
    void selectDir();
    void setBlurLevel(int value);

};