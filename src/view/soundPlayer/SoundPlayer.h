//
// Created by Yuchen Shen on 24/1/21.
//

#ifndef RELICHUNTER_SOUNDPLAYER_H
#define RELICHUNTER_SOUNDPLAYER_H

#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QUrl>

class SoundPlayer {
private:
    QMediaPlaylist *playlist = nullptr;
    QMediaPlayer *music =  nullptr;

public:
    SoundPlayer(QString path){
        playlist = new QMediaPlaylist();
        playlist->addMedia(QUrl(path));
        music =  new QMediaPlayer();
        music->setPlaylist(playlist);
        music->setVolume(50);
    }

    QMediaPlaylist * get_playlist(){
        return this->playlist;
    }

    void play_sound(){
        music->play();
    }

    void stop(){
        music->stop();
    }

    void loop(){
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
    }

    void set_volume(float vol){
        music->setVolume(vol);
    }
};


#endif //RELICHUNTER_SOUNDPLAYER_H
