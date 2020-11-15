#version 330 core
layout (location = 0) in vec3 aPos;

out vec4 VertexColor;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    VertexColor = vec4((aPos.x + 1.f) / 2, (aPos.y + 1) / 2, (aPos.z +1) / 2, 1.0f);
}
