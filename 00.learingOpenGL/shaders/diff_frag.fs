#version 330 core

in vec3 ourColor;
out vec4 color;

void main() {
    color = ourColor.xyzx * ourColor.yzxx * 10.0;
    color = 1 - color.xyzx * color.yzxy;
}
