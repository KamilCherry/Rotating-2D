#include <iostream>
#include <array>
#include <vector>
#include <cmath>

#include <SDL2/SDL.h>

#include <Screen.hpp>

struct vertex {
  float x, y;
  vertex(float p_x, float p_y) : x(p_x), y(p_y) {}
};

struct triangle {
  std::array<vertex, 3> vertices;
  triangle(vertex p1, vertex p2, vertex p3) : vertices({p1, p2, p3}) {

  }
};

struct mesh {
  std::vector<triangle> triangles;
};

void handle_events(bool& is_running);
vertex rotate_vertex(vertex& to_rotate, float angle_radians);

int main() {
  constexpr const char*  TITLE         {"Program"};
  constexpr const int    WIDTH         {1280};
  constexpr const int    HEIGHT        {720};
  constexpr const int    SCALE         {1};

  constexpr const float  ASPECT_RATIO = (float)HEIGHT / (float)WIDTH;

  Screen scr(TITLE, WIDTH, HEIGHT, SCALE);


  mesh square;
  square.triangles.reserve(2);
  square.triangles.emplace_back(triangle(vertex(-0.45f, -0.45f), vertex(0.45f, -0.45f), vertex(-0.45f, 0.45f)));
  square.triangles.emplace_back(triangle(vertex(0.45f, -0.45f), vertex(-0.45f, 0.45f), vertex(0.45f, 0.45f)));

  

  bool gameloop = true;
  while (gameloop) {
    handle_events(gameloop);

    scr.set_draw_color(0x00, 0x00, 0x00);
    scr.clear();
    scr.set_draw_color(0xff, 0xff, 0xff);
    
    for (triangle& t : square.triangles) {
      for (vertex& v : t.vertices) {
        v = rotate_vertex(v, M_PI/128);
      }
      scr.draw_line(SDL_Point((t.vertices[0].x * ASPECT_RATIO + 1.0f)*0.5f * WIDTH, (t.vertices[0].y + 1.0f)*0.5f * HEIGHT), SDL_Point((t.vertices[1].x * ASPECT_RATIO + 1.0f)*0.5f * WIDTH, (t.vertices[1].y + 1.0f)*0.5f * HEIGHT));
      scr.draw_line(SDL_Point((t.vertices[1].x * ASPECT_RATIO + 1.0f)*0.5f * WIDTH, (t.vertices[1].y + 1.0f)*0.5f * HEIGHT), SDL_Point((t.vertices[2].x * ASPECT_RATIO + 1.0f)*0.5f * WIDTH, (t.vertices[2].y + 1.0f)*0.5f * HEIGHT));
      scr.draw_line(SDL_Point((t.vertices[0].x * ASPECT_RATIO + 1.0f)*0.5f * WIDTH, (t.vertices[0].y + 1.0f)*0.5f * HEIGHT), SDL_Point((t.vertices[2].x * ASPECT_RATIO + 1.0f)*0.5f * WIDTH, (t.vertices[2].y + 1.0f)*0.5f * HEIGHT));
    }


    scr.render_texture();
    scr.display();
    SDL_Delay(30);
  }

  return 0;
}

void handle_events(bool& is_running) {
  SDL_Event ev;
  while(SDL_PollEvent(&ev)) {
    switch (ev.type) {
      case SDL_QUIT:
        is_running = false;
      break;
    }
  }
}

vertex rotate_vertex(vertex& to_rotate, float angle_radians) {
  return vertex(to_rotate.x * std::cos(angle_radians) - to_rotate.y * std::sin(angle_radians), to_rotate.x * std::sin(angle_radians) + to_rotate.y * std::cos(angle_radians));
}
