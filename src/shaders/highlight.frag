#version 330 core

in vec3 VertexColor;
in vec2 TexCoord;
in vec3 pos;
uniform sampler2D text;

void main() {
    vec4 textureT = texture(text, TexCoord);
    gl_FragColor = vec4(textureT.rgb, length(textureT.rgb)) * vec4(0.35, 0.78, 0, 0.7);
}
