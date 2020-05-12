#version 330 core

out vec4 color;
in vec2 coord_im;

uniform sampler2D texture_1;
uniform sampler2D texture_2;

void main() {
    // color = vec4(0.2f, 0.0f, 0.0f, 1.0f);
    // color = texture(texture_1, coord_im);
    // color = texture(texture_2, coord_im);
    color = mix(texture(texture_1, coord_im), texture(texture_2, coord_im), 0.5);
}