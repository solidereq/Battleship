#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<cmath>
#include<vector>
#include <sstream>
#include"music.h"

using namespace std;

class Music {
    //soundtrack
    Music(const string folder) {this->folder= folder}
    Music(const strin folder, std::initializer_list <string> fileStringList){
        this->folder = folder;
        for (auto i=fileStringList.begin(); i != fileStringList.end(); i++) this->addFile(*i);
        sf::Listener::setGlobalVolume(100);
    }

    //dodawanie dŸwiêków
    void addFile(const string& file) {
        sf::SoundBuffer sb;
        if (!sb.loadFromFile(this->folder + "/" + file + "." + this->type)) cout << "Problem z ³adowaniem pliku.\n";
        this->files.push_back(file);
        this->bufor.push_back(sb);
    }
    //play sound na podstawie wolnego slotu i na podstawie bufora
    int play(string fileName, int volume=100, bool loop=false, float pitch=1.0, float att=1.0, const sf::Vector2f &vec = sf::Vector2f(400,300), float dist=5.f){
        bool isPlay=0;
        for(int i; i<MAX_SOUNDS;i++){
            if(this->sounds[i].getStatus() == sf::Sound::Playing) { continue; }
            else{
                unsigned int x;
                for (x=0;x<this->bufor.size();x) if (fileName == this_>files[x]) break;
                if (x==this->bufor.size()) { cout << "Nie ma pliku " + fileName + "\n"; return false}

            }
        }

    }
};
