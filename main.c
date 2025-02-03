#include <raylib.h>

int main(void) {
    const int screenWidth = 500;
    const int screenHeight = 500;
    InitWindow(screenWidth, screenHeight, "Shader");
    Shader shader = LoadShader(0, "main.fs");

    int resolutionLoc = GetShaderLocation(shader, "resolution");

    float resolution[2] = {(float) screenWidth, (float) screenHeight};
    SetShaderValue(shader, resolutionLoc, resolution, SHADER_UNIFORM_VEC2);

    // Load blank texture to draw on using shader
    Image imBlank = GenImageColor(screenWidth, screenHeight, BLANK);
    Texture2D texture = LoadTextureFromImage(imBlank);
    UnloadImage(imBlank);

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        BeginShaderMode(shader);
        DrawTexture(texture, 0, 0, BLANK);
        EndShaderMode();
        DrawFPS(700, 15);
        EndDrawing();
    }
    CloseWindow();
}
