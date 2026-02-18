// raylib_native.c — C glue between Wyn and raylib
// Compile: cc -c raylib_native.c $(pkg-config --cflags raylib) -o raylib_native.o
// Link: $(pkg-config --libs raylib)

#include "raylib.h"
#include <stdio.h>

void Raylib_init(int width, int height, const char* title) {
    InitWindow(width, height, title);
    SetTargetFPS(60);
}

int Raylib_should_close(void) {
    return WindowShouldClose();
}

void Raylib_begin_drawing(void) { BeginDrawing(); }
void Raylib_end_drawing(void) { EndDrawing(); }

void Raylib_clear(int r, int g, int b) {
    ClearBackground((Color){r, g, b, 255});
}

void Raylib_draw_rect(int x, int y, int w, int h, int r, int g, int b) {
    DrawRectangle(x, y, w, h, (Color){r, g, b, 255});
}

void Raylib_draw_rect_lines(int x, int y, int w, int h, int r, int g, int b) {
    DrawRectangleLines(x, y, w, h, (Color){r, g, b, 255});
}

void Raylib_draw_circle(int cx, int cy, int radius, int r, int g, int b) {
    DrawCircle(cx, cy, (float)radius, (Color){r, g, b, 255});
}

void Raylib_draw_line(int x1, int y1, int x2, int y2, int r, int g, int b) {
    DrawLine(x1, y1, x2, y2, (Color){r, g, b, 255});
}

void Raylib_draw_text(const char* text, int x, int y, int size, int r, int g, int b) {
    DrawText(text, x, y, size, (Color){r, g, b, 255});
}

int Raylib_text_width(const char* text, int size) {
    return MeasureText(text, size);
}

// Input
int Raylib_is_key_pressed(int key) { return IsKeyPressed(key); }
int Raylib_is_key_down(int key) { return IsKeyDown(key); }
int Raylib_mouse_x(void) { return GetMouseX(); }
int Raylib_mouse_y(void) { return GetMouseY(); }
int Raylib_is_mouse_pressed(int button) { return IsMouseButtonPressed(button); }

// Timing
double Raylib_frame_time(void) { return GetFrameTime(); }
double Raylib_time(void) { return GetTime(); }
int Raylib_fps(void) { return GetFPS(); }

void Raylib_close(void) { CloseWindow(); }
