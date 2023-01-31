//
// Created by Raffael on 30/01/2023.
//

#include <QApplication>
#include "SoundPlayer.h"

void SoundPlayer::playBackgroundMusic(QApplication &application) {
    auto *mediaPlayer = new QMediaPlayer;
    auto *audioOutput = new QAudioOutput;
    mediaPlayer->setAudioOutput(audioOutput);
    application.connect(mediaPlayer, SIGNAL(positionChanged(qint64)), reinterpret_cast<const QObject *>(this), SLOT(positionChanged(qint64)));
    mediaPlayer->setSource(QUrl("file:/assets/sounds/belle_musique.mp3"));
    audioOutput->setVolume(50);
    mediaPlayer->play();
}
