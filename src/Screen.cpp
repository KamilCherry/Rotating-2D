#include <iostream>
#include <SDL2/SDL.h>
#include <Screen.hpp>

Screen::Screen(const char* p_title, const int p_width, const int p_height, const int p_scale) : m_window(nullptr), m_renderer(nullptr), m_texture(nullptr), m_window_width(p_width), m_window_height(p_height) {

  m_window_area = m_window_width * m_window_height;

  if (!SDL_WasInit(SDL_INIT_EVENTS))
  if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
    std::cerr << "Couldn't initialize events. Error: " << SDL_GetError() << std::endl;
  
  if (!SDL_WasInit(SDL_INIT_VIDEO))
  if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
    std::cerr << "Couldn't initialize video. Error: " << SDL_GetError() << std::endl;

  m_window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_width * p_scale, p_height * p_scale, SDL_WINDOW_SHOWN);
  if (m_window == NULL) std::cerr << "Couldn't create window. Error: " << SDL_GetError() << std::endl;

  m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
  if (m_renderer == NULL) std::cerr << "Couldn't create renderer. Error: " << SDL_GetError() << std::endl;

  m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, p_width, p_height);
  if (m_texture == NULL) std::cerr << "Couldn't create texture. Error: " << SDL_GetError() << std::endl;

  if (SDL_RenderSetScale(m_renderer, p_scale, p_scale) < 0) std::cerr << "Couldn't set render scale. Error: " << SDL_GetError() << std::endl;

  SDL_SetRenderTarget(m_renderer, m_texture);
  SDL_RenderClear(m_renderer);
  SDL_SetRenderTarget(m_renderer, NULL);
}

Screen::~Screen() {
  SDL_DestroyWindow(m_window);
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyTexture(m_texture);
}

void Screen::set_draw_color(uint8_t p_r, uint8_t p_g, uint8_t p_b, uint8_t p_a) {
  SDL_SetRenderDrawColor(m_renderer, p_r, p_g, p_b, p_a);
}

void Screen::display() {
  SDL_RenderPresent(m_renderer);
}

void Screen::clear() {
  SDL_RenderClear(m_renderer);
  SDL_SetRenderTarget(m_renderer, m_texture);
  SDL_RenderClear(m_renderer);
  SDL_SetRenderTarget(m_renderer, NULL);
}

void Screen::render_texture() {
  SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
}

void Screen::draw_line(SDL_Point p_p1, SDL_Point p_p2) {
  SDL_SetRenderTarget(m_renderer, m_texture);
  SDL_RenderDrawLine(m_renderer, p_p1.x, p_p1.y, p_p2.x, p_p2.y);
  SDL_SetRenderTarget(m_renderer, NULL);
}

