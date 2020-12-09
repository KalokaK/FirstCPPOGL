#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;
layout (location = 2) in vec2 aTex;

out vec2 TexCoord;
out vec3 pos;

uniform int field;

void main() {
    gl_Position = vec4(aPos, 1);
    float scale = 2;
    TexCoord = (aTex * 8 - (vec2(field % 8, field / 8) - (1/scale))) / scale;
}