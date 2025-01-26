#include <iostream>
#include <SDL3/SDL.h>

int main (int argc, char *argv[]) {
  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;
  SDL_Surface* surface = nullptr;
  SDL_Texture* texture_h = nullptr;
  SDL_Texture* texture_v = nullptr;

  if(SDL_Init(SDL_INIT_EVENTS)) {
    SDL_Log("Window Initialization Successfull.");
  } else {
    SDL_Log(SDL_GetError());
  }

  window = SDL_CreateWindow("Simple Renderer", 1280, 720, SDL_WINDOW_VULKAN | SDL_WINDOW_HIGH_PIXEL_DENSITY);
  renderer = SDL_CreateRenderer(window, "vulkan");
  surface = SDL_LoadBMP("water_effect.bmp");

  texture_h = SDL_CreateTextureFromSurface(renderer, surface);
  texture_v = SDL_CreateTextureFromSurface(renderer, surface);

  SDL_DestroySurface(surface);

  bool is_active = true;
  SDL_FRect rectangle_a{0.0f, 0.0f, 1280.0f, 720.0f};
  SDL_FRect rectangle_b{-1279.0f, 0.0f, 1280.0f, 720.0f};
  SDL_FRect rectangle_c{0.0f, 0.0f, 1280.0f, 720.0f};
  SDL_FRect rectangle_d{0.0f, -720.0f, 1280.0f, 720.0f};

  while(is_active) {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_EVENT_QUIT) {
        is_active = false;
      }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0xFF, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    float width_h, height_h, width_v, height_v;
    SDL_GetTextureSize(texture_h, &width_h, &height_h);
    SDL_GetTextureSize(texture_v, &width_v, &height_v);

    SDL_Delay(18);

    rectangle_a.x++;
    if(rectangle_a.x > 1279) {
      rectangle_a.x = -1279;
    }

    rectangle_b.x++;
    if(rectangle_b.x > 1279) {
      rectangle_b.x = -1279;
    }

    rectangle_c.y++;
    if(rectangle_c.y > 719) {
      rectangle_c.y = -720;
    }

    rectangle_d.y++;
    if(rectangle_d.y > 719) {
      rectangle_d.y = -720;
    }

    SDL_SetTextureBlendMode(texture_h, SDL_BLENDMODE_NONE);
    SDL_SetTextureBlendMode(texture_v, SDL_BLENDMODE_MOD);
    SDL_RenderTexture(renderer, texture_h, nullptr, &rectangle_a);
    SDL_RenderTexture(renderer, texture_h, nullptr, &rectangle_b);

    SDL_RenderTexture(renderer, texture_v, nullptr, &rectangle_c);
    SDL_RenderTexture(renderer, texture_v, nullptr, &rectangle_d);

    SDL_RenderPresent(renderer);
  }


  SDL_DestroyTexture(texture_h);
  SDL_DestroyTexture(texture_v);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
