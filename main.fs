#version 330

in vec2 fragTexCoord;
in vec4 fragColor;

uniform vec2 resolution;
uniform float time;

out vec4 finalColor;

// These functions come from https://iquilezles.org/articles/distfunctions2d/

float sdCircle( vec2 p, float r )
{
    return length(p) - r;
}

float sdBox( in vec2 p, in vec2 b )
{
    vec2 d = abs(p)-b;
    return length(max(d,0.0)) + min(max(d.x,d.y),0.0);
}

void main() {
    vec2 uv = fragTexCoord.xy;

    uv = vec2(uv.x, 1.0 - uv.y);
    uv = uv - 0.5;
    uv.y *= resolution.y / resolution.x;

    float x = abs(sin(time));
    float box = sdBox(uv, vec2(x * 0.5, x * 0.25));
    float circle = sdCircle(uv, 0.5 * x);
    float d = min(box, circle);
    d = step(d, 0.0);
    // finalColor = vec4(uv, 0.0, 1.0);
    finalColor = vec4(d * sin(x), d * sin(x), d, 1.0);
}
