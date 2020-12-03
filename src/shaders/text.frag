#version 330 core
out vec4 FragColor;

in vec3 VertexColor;
in vec2 TexCoord;
in vec3 pos;
uniform sampler2D text;

void main()
{
    vec4 texCol = texture(text, TexCoord);
    FragColor = texCol * vec4((pos + 1) / 2, 1);
}
