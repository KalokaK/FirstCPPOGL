#version 330 core
out vec4 FragColor;

in vec3 VertexColor;
in vec3 pos;
uniform sampler2D text;

void main()
{
    FragColor = vec4(VertexColor, 1);
}
