#include "Audio.h"
#include <iostream>
void Audio::load_audio(const char* name , int id)
{
    SDL_Init(SDL_INIT_AUDIO);
    wv_map[id] = wave();
    SDL_LoadWAV(name , &wv_map[id].wavSpec , &wv_map[id].wavBuffer , &wv_map[id].wavLength);
    std::cout << SDL_GetError() << "\n";
}

void Audio::play_audio(int id)
{
    if(active == false) return;
    deviceID = SDL_OpenAudioDevice(NULL, 0, &wv_map[id].wavSpec, NULL, 0);
    int success = SDL_QueueAudio(deviceID , wv_map[id].wavBuffer , wv_map[id].wavLength);
    std::cout << SDL_GetError() << "\n";
    SDL_PauseAudioDevice(deviceID , 0);
}

void Audio::enable()
{
    SDL_UnlockAudio();
}

void Audio::disable()
{
    SDL_LockAudio();
}