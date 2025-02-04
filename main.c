#include <raylib.h>

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Shader");
    Shader shader = LoadShader(0, "main.fs");

    int resolutionLoc = GetShaderLocation(shader, "resolution");
    int timeLoc = GetShaderLocation(shader, "time");

    float resolution[2] = {(float) screenWidth, (float) screenHeight};
    SetShaderValue(shader, resolutionLoc, resolution, SHADER_UNIFORM_VEC2);

    // Load blank texture to draw on using shader
    Image imBlank = GenImageColor(screenWidth, screenHeight, BLANK);
    Texture2D texture = LoadTextureFromImage(imBlank);
    UnloadImage(imBlank);

    float time = 0.0;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        time += GetFrameTime();
        SetShaderValue(shader, timeLoc, &time, SHADER_UNIFORM_FLOAT);
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
