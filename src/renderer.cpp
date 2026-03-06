#include "../headers/renderer.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}
void Renderer::Draw()
{
    glPointSize(20.0);

    glClear(GL_COLOR_BUFFER_BIT);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_POINTS, 0, 1);
    glDisableVertexAttribArray(0);
}