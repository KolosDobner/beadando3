#ifndef COMMENT_HPP
#define COMMENT_HPP


#include "graphics.hpp"
#include "widgets.hpp"

class Comment : public Widget {
public:
    Comment(Window* window, int x, int y, int sx, int sy);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual int data();
    virtual int data2();
};

#endif // COMMENT_HPP
