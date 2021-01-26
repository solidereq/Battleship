#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
using namespace std;

class Music{
    public:
    string folder;
    string type="mp3";
    vector <string> files;
    vector <sf::SoundBuffer> bufor;
    sf::Sound sounds[MAX_SOUNDS];

}
