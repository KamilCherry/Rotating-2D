#pragma once

#include <SDL2/SDL.h>

class Screen {

public:
  Screen(const char* p_title, const int p_width, const int p_height, const int p_scale = 1);
  ~Screen();
  void set_draw_color(uint8_t p_r, uint8_t p_g, uint8_t p_b, uint8_t p_a = 0xff);
  void display();
  void clear();
  void render_texture();
  void draw_line(SDL_Point p_p1, SDL_Point p_p2);

private:
  SDL_Window* m_window;
  SDL_Renderer* m_renderer;
  SDL_Texture* m_texture;
  int m_window_width;
  int m_window_height;
  int m_window_area;

};

