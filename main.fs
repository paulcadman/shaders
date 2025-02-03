#version 330

in vec2 fragTexCoord;
in vec4 fragColor;

uniform vec2 resolution;

out vec4 finalColor;

void main() {
    vec2 uv = fragTexCoord.xy;

    uv = vec2(uv.x, 1.0 - uv.y);
    uv = uv - 0.5;
    uv.x *= resolution.x / resolution.y;

    float d = length(uv);
    // finalColor = vec4(uv.x, uv.y, 0.0, 1.0);
    finalColor = vec4(d, d, 0.0, 1.0);
}
