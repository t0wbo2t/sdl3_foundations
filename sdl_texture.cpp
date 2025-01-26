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
  const SDL_PixelFormatDetails* format_details = SDL_GetPixelFormatDetails(surface->format); 
  SDL_SetSurfaceColorKey(surface, true, SDL_MapRGB(format_details, nullptr, 0x0, 0xFF, 0x0));

  texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
  SDL_DestroySurface(surface);

  bool is_active = true;
  SDL_FRect rectangle;
  rectangle.x = 400.0f;
  rectangle.y = 150.0f;
  rectangle.w = 360.0f;
  rectangle.h = 360.0f;

  SDL_FRect rectangle_p;
  rectangle_p.x = 400.0f;
  rectangle_p.y = 150.0f;
  rectangle_p.w = 360.0f;
  rectangle_p.h = 360.0f;

  while(is_active) {
    SDL_Event event;
    
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_EVENT_QUIT) {
        is_active = false;
      }

      if(event.type == SDL_EVENT_MOUSE_MOTION){
        rectangle_p.x = event.motion.x;
        rectangle_p.y = event.motion.y;
      }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // SDL_RenderLine(renderer, 1.0f, 1.0f, 1279.0f, 719.0f);
    // SDL_RenderRect(renderer, &rectangle);
    SDL_RenderTexture(renderer, texture, nullptr, &rectangle);
    SDL_RenderTexture(renderer, texture, nullptr, &rectangle_p);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
