#include <SDL.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "display.h"

bool is_running = false;

void setup(void) {
    color_buffer = (uint32_t *)malloc(window_width * window_height * sizeof(uint32_t));

    if (!color_buffer) {
        fprintf(stderr, "Error allocating color buffer.\n");
        return;
    }

    color_buffer_texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        window_width,
        window_height);
}

void process_input(void) {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            is_running = false;
            break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                is_running = false;
            break;
    }
}

void update(void) {
}

void render(void) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);

    draw_grid(10);
    draw_rect(window_height / 2, window_width / 2, 800, 200, 0xFFFFAA88);

    render_color_buffer();
    clear_color_buffer(0xFF000000);

    SDL_RenderPresent(renderer);
}

int main(int argc, char *args[]) {
    is_running = initialize_window();

    setup();

    while (is_running) {
        process_input();
        update();
        render();
    }

    destroy_window();

    return 0;
}