#pragma once
#include <QPushButton>
#include <QPixmap>
#include <QMediaPlayer>
#include <QMediaContent>

class SoundButton: public QPushButton {
    Q_OBJECT
public:
    SoundButton() = default;
    SoundButton(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent* e) override;
    void keyPressEvent(QKeyEvent* e) override;
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

public slots:
    void setUp();
    void setDown();
private:
    QMediaPlayer* qtPlayer;
    QMediaContent* clickSound;
    QPixmap mCurrentButton;
    QPixmap mButtonUp;
    QPixmap mButtonDown;
};
