#include"Window.h"

class IRenderer{
public:

    enum class type {OGL};

    virtual bool initialize(Window& window) = 0;
    virtual void beginDraw() = 0;
    virtual void draw() = 0;
    virtual void endDraw() = 0;
    virtual void close() = 0;
};