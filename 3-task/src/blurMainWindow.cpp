#include "blurMainWindow.h"
#include "./ui_BlurWindow.h"
#include <iostream>

BlurMainWindow::BlurMainWindow(QWidget* parent): QMainWindow(parent), blurWindow(new Ui::BlurWindow) {
    blurWindow->setupUi(this);
    openButton = blurWindow->openButton;
    blurSlider = blurWindow->blurSlider;
    imgLabel = blurWindow->imgLabel;
};

BlurMainWindow::~BlurMainWindow() {
    delete blurWindow;
}

void BlurMainWindow::selectDir() {
    std::cout << "clicked" << std::endl;
    currentDir = QFileDialog::getOpenFileName(nullptr,
                                              "open png img",   
                                              "/home/", 
                                              "png file (*.png)");
    qBlurImage = QImage(currentDir);
    imgLabel->setPixmap(QPixmap::fromImage(blurImage(qBlurImage, 0).scaled(
                                    imgLabel->width(),
                                    imgLabel->height(), Qt::KeepAspectRatio)));
                                              
}

QImage BlurMainWindow::blurImage(QImage source, int blurRadius) {
    if (currentDir.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));

    auto* blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurRadius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(),    
                 QRectF(0, 0, source.width(), source.height()));
    return result;                 
}

void  BlurMainWindow::setBlurLevel(int value) {
    imgLabel->setPixmap(QPixmap::fromImage(blurImage(qBlurImage, value).scaled(
                                imgLabel->width(),
                                imgLabel->height(), Qt::KeepAspectRatio)));
}
