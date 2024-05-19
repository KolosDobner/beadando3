#include "playbox.hpp"
#include "graphics.hpp"
#include "window.hpp"
#include <cmath>
using namespace genv;
const double pi = 3.14159265358979323846;


PlayBox::PlayBox(Window* window, int x, int y, int sx, int sy) : Widget(window, x, y, sx, sy)
{
    _filler = 0;
    _checked=false;
}

void PlayBox::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    if (_filler==1) {
        gout << color(255,0,0);
        gout << move_to(_x+4, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+5, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+_size_x-4, _y+4) << line(-_size_x+8, _size_y-8);
        gout << move_to(_x+_size_x-5, _y+4) << line(-_size_x+8, _size_y-8);
    }
    if (_filler==2) {
        gout << color(255,0,255);
        int radius = _size_x / 2.3;
        int x = _x + _size_x / 2;
        int y = _y + _size_x / 2;

        for (int i = 0; i < 360; i++) {
            int x1 = x + radius * cos(i * pi / 180);
            int y1 = y + radius * sin(i * pi / 180);
            int x2 = x + radius * cos((i+1) * pi / 180);
            int y2 = y + radius * sin((i+1) * pi / 180);
            gout << move_to(x1, y1) << line(x2 - x1, y2 - y1);
        }
    }
}
void PlayBox::handle(event ev)
{
    //X,O
    if(!_checked){
        if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left && _window->fillere()==1) {
            _filler=1;
            _checked=true;
        }
        if(ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left && _window->fillere()==2){
            _filler=2;
            _checked=true;
        }
    }
}
bool PlayBox::is_checked()
{
    return _checked;
}
int PlayBox::data(){ //x
    return (_x/50);
}
int PlayBox::data2(){ //y
    return (_y/50);
}

