#include "button.h"
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>
#include <QCoreApplication>

SoundButton::SoundButton(QWidget* parent): QPushButton(parent) {
    qtPlayer = new QMediaPlayer(this);
    clickSound = new QMediaContent(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "/boing.mp3"));
    qtPlayer->setMedia(*clickSound);
    qtPlayer->setVolume(75);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mButtonUp = QPixmap("../data/buttonUp.png");
    mButtonDown = QPixmap("../data/buttonDown.png");
    mCurrentButton = mButtonUp;

    QObject::connect(this, &QPushButton::clicked, this, &SoundButton::setDown);
    setGeometry(mCurrentButton.rect());
    setFixedSize(200, 190);
}

void SoundButton::paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    painter.drawPixmap(e->rect(), mCurrentButton);
}

void SoundButton::keyPressEvent(QKeyEvent* e) {
    setDown();
}

QSize SoundButton::sizeHint() const {
    return QSize(200, 190); 
}

QSize SoundButton::minimumSizeHint() const {
    return sizeHint();
}

void SoundButton::setUp() {
    mCurrentButton = mButtonUp;
    update();
}

void SoundButton::setDown() {
    qtPlayer->play();
    mCurrentButton = mButtonDown;
    update();
    QTimer::singleShot(qtPlayer->duration(), this, &SoundButton::setUp);
}