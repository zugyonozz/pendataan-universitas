#include "ui.h"
#include "database.h"
#include <iostream>

int main() {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    if (!initSDL(&window, &renderer)) {
        std::cerr << "Gagal inisialisasi SDL.\n";
        return 1;
    }

    // Load font
    TTF_Font* font = TTF_OpenFont("data/fonts/ARIAL.ttf", 20);
    if (!font) {
        std::cerr << "Gagal membuka font.\n";
        shutdownSDL(window, renderer);
        return 1;
    }

    // Buka database dan ambil data
    sqlite3* db = bukaDatabase("data/akademik.db");
    if (!db) {
        std::cerr << "Gagal membuka database.\n";
        TTF_CloseFont(font);
        shutdownSDL(window, renderer);
        return 1;
    }

    if (!initDatabase(db)) {
        std::cerr << "Gagal inisialisasi tabel database.\n";
        sqlite3_close(db);
        TTF_CloseFont(font);
        shutdownSDL(window, renderer);
        return 1;
    }

    auto daftar = ambilSemuaMahasiswa(db);

    // Event loop
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        renderMahasiswa(renderer, font, daftar);
        SDL_Delay(100);
    }

    // Cleanup
    sqlite3_close(db);
    TTF_CloseFont(font);
    shutdownSDL(window, renderer);

    return 0;
}
