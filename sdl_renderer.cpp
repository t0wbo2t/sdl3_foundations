#include <iostream>
#include <SDL3/SDL.h>

int main (int argc, char *argv[]) {
  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;
  SDL_Surface* surface = nullptr;
  SDL_Texture* texture = nullptr;

  if(SDL_Init(SDL_INIT_EVENTS)) {
    SDL_Log("Window Initialization Successfull.");
  } else {
    SDL_Log(SDL_GetError());
  }

  window = SDL_CreateWindow("Simple Renderer", 1280, 720, SDL_WINDOW_VULKAN | SDL_WINDOW_HIGH_PIXEL_DENSITY);
  renderer = SDL_CreateRenderer(window, "vulkan");
  surface = SDL_LoadBMP("test_image_0.bmp");
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_DestroySurface(surface);

  bool is_active = true;
  SDL_FRect rectangle;
  rectangle.x = 512.0f;
  rectangle.y = 150.0f;
  rectangle.w = 360.0f;
  rectangle.h = 360.0f;

  while(is_active) {
    SDL_Event event;
    
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_EVENT_QUIT) {
        is_active = false;
      }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // SDL_RenderLine(renderer, 1.0f, 1.0f, 1279.0f, 719.0f);
    // SDL_RenderRect(renderer, &rectangle);
    SDL_RenderTexture(renderer, texture, nullptr, &rectangle);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
