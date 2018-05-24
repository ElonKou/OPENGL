#version 330 core
in vec2 TexCoord;
out vec4 color;
uniform sampler2D ourTexture;

void main(){
    color = texture(ourTexture,TexCoord);
    // color = vec4(1.0f, 0.0f, 0.0f, 1.0f);
}