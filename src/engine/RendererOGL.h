#include"IRenderer.h"


class RendererOGL : public IRenderer{
public:
    RendererOGL();
    RendererOGL(const RendererOGL&) = delete;
    RendererOGL& operator = (const RendererOGL&) = delete;

    bool initialize();
    void beginDraw();
    void draw();
    void endDraw();
    void close();
};