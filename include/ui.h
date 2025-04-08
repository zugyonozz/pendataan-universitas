#ifndef UI_H
#define UI_H

#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_ttf.h>
#include <vector>
#include "database.h"

// Inisialisasi dan shutdown SDL
bool initSDL(SDL_Window** window, SDL_Renderer** renderer);
void shutdownSDL(SDL_Window* window, SDL_Renderer* renderer);

// Render daftar mahasiswa ke layar
void renderMahasiswa(SDL_Renderer* renderer, TTF_Font* font, const std::vector<Mahasiswa>& daftar);

#endif // UI_H
