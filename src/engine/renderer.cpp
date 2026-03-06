#include "../headers/engine/renderer.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}
void Renderer::Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);
}