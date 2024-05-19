#ifndef PLAYBOX_HPP_INCLUDED
#define PLAYBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class PlayBox : public Widget {
protected:
    bool _checked;
    int _filler;
public:
    PlayBox(Window* window, int x, int y, int sx, int sy);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual bool is_checked();
    virtual int data();
    virtual int data2();
};


#endif // PLAYBOX_HPP_INCLUDED
