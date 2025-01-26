# SDL3 Tutorial Library

This is a simple SDL3-based tutorial library showcasing various SDL3 features and rendering techniques. It includes examples like rendering images, setting pixels, applying textures, and implementing water effects.

## Files Overview

### Source Code
- `sdl_renderer.cpp`: A utility to render graphical objects to the screen.
- `sdl_set_pixel.cpp`: A function to directly manipulate individual pixels on the screen.
- `sdl_texture.cpp`: Demonstrates how to load and render textures in SDL3.
- `sdl_water_effect.cpp`: Implements a water effect simulation using SDL3.
- `sdl_window.cpp`: A wrapper to create and manage SDL windows.


### Assets
- `test_image_0.bmp`: A test image used for rendering examples.
- `test_image.bmp`: Another test image for texture rendering.
- `water_effect.bmp`: An image used for the water effect simulation.

## Getting Started

1. **Install SDL3**:
   Ensure you have SDL3 installed on your system. You can download SDL3 from the official SDL website or install it using your system’s package manager.

2. **Build Instructions**:
   To compile and run the examples, you can use `g++` or any compatible C++ compiler with SDL3 support:

   ```bash
   g++ -std=c++17 -o sdl_renderer sdl_renderer.cpp `pkg-config sdl3--cflags --libs`
   g++ -std=c++17 -o sdl_set_pixel sdl_set_pixel.cpp `pkg-config sdl3--cflags --libs`
   g++ -std=c++17 -o sdl_texture sdl_texture.cpp `pkg-config sdl3--cflags --libs`
   g++ -std=c++17 -o sdl_water_effect sdl_water_effect.cpp `pkg-config sdl3--cflags --libs`
   g++ -std=c++17 -o sdl_window sdl_window.cpp `pkg-config sdl3--cflags --libs`
   ```

3. **Run the Examples**:
   After compiling, you can run the individual binaries:
   ```bash
   ./sdl_renderer
   ./sdl_set_pixel
   ./sdl_texture
   ./sdl_water_effect
   ./sdl_window
   ```

4. **Customizing**:
   You can modify the source code files (e.g., `sdl_renderer.cpp`, `sdl_set_pixel.cpp`, etc.) to suit your needs and experiment with SDL3's graphics and window management.

## Example Use Cases

- **Basic Rendering**: Use the `sdl_renderer` example to understand how to draw basic shapes and handle rendering.
- **Pixel Manipulation**: Use `sdl_set_pixel` to manipulate pixels directly for custom effects or graphics.
- **Texture Rendering**: The `sdl_texture` example shows how to load and render textures in your SDL3 projects.
- **Water Effect**: The `sdl_water_effect` example simulates a water-like effect using SDL3 for graphical experiments.
