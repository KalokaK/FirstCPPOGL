#version 330 core
out vec4 FragColor;

in vec3 VertexColor;
in vec2 TexCoord;
in vec3 pos;
uniform sampler2D text;

void main()
{
    vec2 origin = vec2(-1, 1); // light origin
    vec2 offset = (origin - pos.xy); // this is opposite dir, I'm aware.
    vec2 scaled = 0.5 * (offset / length(offset)); // scale light direction to local texture scale
    vec2 localOrigin = vec2(0.5, 0.5) + scaled; // local "gloss" origin
    float decayedLocal = 1 / ((distance(localOrigin, TexCoord) + 1) * 0.9); // intensity. 1/x but shifted and scaled
    vec3 lightColor = vec3(1, 0.95, 0.95); // dugh
    vec4 texCol = texture(text, TexCoord); // dugh
    float lightStrenght = 1.5 / ((distance(origin, pos.xy) + 1) * 1.1) * decayedLocal; // same thing, just global
    vec3 result = VertexColor * 1.5 * lightStrenght * lightColor; // COMBIIINEEEE
    FragColor = texCol * vec4(result, 1); //
} 
