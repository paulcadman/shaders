#include <raylib.h>

int main(void) {
    InitWindow(800, 600, "Shader");
    while (!WindowShouldClose()) {
        BeginDrawing();
        EndDrawing();
    }
    CloseWindow();
}
