#include "ui.h"
#include <iostream>

bool initSDL(SDL_Window** window, SDL_Renderer** renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL Init error: " << SDL_GetError() << "\n";
        return false;
    }

    if (TTF_Init() < 0) {
        std::cerr << "TTF Init error: " << SDL_GetError() << "\n";
        return false;
    }

    *window = SDL_CreateWindow("Daftar Mahasiswa", 800, 600, SDL_WINDOW_RESIZABLE);
    if (!*window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << "\n";
        return false;
    }

    *renderer = SDL_CreateRenderer(*window, nullptr);
    if (!*renderer) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << "\n";
        return false;
    }

    return true;
}

void shutdownSDL(SDL_Window* window, SDL_Renderer* renderer) {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

void renderMahasiswa(SDL_Renderer* renderer, TTF_Font* font, const std::vector<Mahasiswa>& daftar) {
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);

    SDL_Color color = {255, 255, 255, 255};
    int y = 20;

    for (const auto& m : daftar) {
        std::string text = m.nama + " - " + m.nim + " - " + m.jurusan;
        SDL_Surface* surf = TTF_RenderText_Blended(font, text.c_str(), text.length(), color);
        if (!surf) continue;

        SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);
        SDL_FRect dst = { 20.0f, static_cast<float>(y), static_cast<float>(surf->w), static_cast<float>(surf->h) };
        SDL_RenderTexture(renderer, tex, nullptr, &dst);

        SDL_DestroyTexture(tex);
        SDL_DestroySurface(surf);
        y += surf->h + 10;
    }

    SDL_RenderPresent(renderer);
}
