#include <iostream>
#include <SDL3/SDL.h>

void setPixel(SDL_Surface* surface, int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
  SDL_LockSurface(surface);

  uint8_t* pixel_bytes = (uint8_t*) surface->pixels;
  auto s_format = SDL_GetPixelFormatDetails(surface->format);
  pixel_bytes[y * surface->pitch + x * s_format->bytes_per_pixel + 0] = blue;
  pixel_bytes[y * surface->pitch + x * s_format->bytes_per_pixel + 1] = green;
  pixel_bytes[y * surface->pitch + x * s_format->bytes_per_pixel + 2] = red;

  SDL_UnlockSurface(surface);
}

int main (int argc, char *argv[]) {
  bool is_active = true;
  
  SDL_Window* window = nullptr;
  SDL_Surface* surface = nullptr;

  if(SDL_Init(SDL_INIT_EVENTS)) {
    SDL_Log("Window initialization is successfull.");
  } else {
    SDL_Log(SDL_GetError());
  }

  window = SDL_CreateWindow("SDL3 Practice", 1280, 720, SDL_WINDOW_VULKAN | SDL_WINDOW_HIGH_PIXEL_DENSITY);
  surface = SDL_GetWindowSurface(window);

  while(is_active) {
    SDL_Event event;
    
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_EVENT_QUIT) {
        is_active = false;
      }

      if(event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        float x, y;
        SDL_MouseButtonFlags button_flag = SDL_GetMouseState(&x, &y);
        if(button_flag == SDL_BUTTON_LEFT) {
          SDL_PumpEvents();
          setPixel(surface, x, y, 255, 0, 0);
        }
      }
    }
    SDL_UpdateWindowSurface(window);
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
} 
