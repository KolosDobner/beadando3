#ifndef WIDGETS_HPP
#define WIDGETS_HPP
#include <string>
#include "graphics.hpp"

#include "graphics.hpp"

struct Window;

class Widget{
protected:
    int _x, _y, _size_x, _size_y;
    Window* _window;
public:
    Widget(Window* window, int x, int y, int sx, int sy);
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void handle(genv::event ev) = 0;
    virtual void draw() = 0;
    virtual int data() = 0;
    virtual int data2() = 0;
};

#endif // WIDGETS_HPP
