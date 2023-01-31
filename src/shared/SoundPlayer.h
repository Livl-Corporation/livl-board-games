//
// Created by Raffael on 30/01/2023.
//

#ifndef LIVL_SOUNDPLAYER_H
#define LIVL_SOUNDPLAYER_H

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QObject>


class SoundPlayer {
    public:
        void playBackgroundMusic(QApplication &application);
};


#endif //LIVL_SOUNDPLAYER_H
