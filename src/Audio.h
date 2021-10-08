#ifndef AUDIO_H
#define AUDIO_H

#include <SDL2/SDL.h>
#include <map>

struct wave
{
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;

};


class Audio
{
    public:
        void load_audio(const char*  , int id);
        void play_audio(int id);
        void enable();
        void disable();
    private:
    SDL_AudioDeviceID deviceID;
    std::map<int , wave> wv_map;
    bool active = true;
    


};

#endif