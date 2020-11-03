#version 450 core

layout (location = 0) in vec3 aPos;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    /*
    NOTE: normally these are not already in NDC so this would do the preprocessing
    */
}