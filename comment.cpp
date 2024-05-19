#include "comment.hpp"
#include "graphics.hpp"
#include "window.hpp"
using namespace genv;
using namespace std;


Comment::Comment(Window* window, int x, int y, int sx, int sy) : Widget(window, x, y, sx, sy)
{

}

void Comment::draw()
{
    if (_window->fillere()==2) {
        gout << move_to(_x, _y-15) << color(0,0,0) << box(_size_x, _size_y);
        gout << color(255,0,0);
        gout << move_to(_x, _y) << text("X kovetkezik");
    }
    if (_window->fillere()==1) {
        gout << move_to(_x, _y-15) << color(0,0,0) << box(_size_x, _size_y);
        gout << color(255,0,255);
        gout << move_to(_x, _y) << text("O kovetkezik");
    }
    if(_window->checkWin()==2){
        gout << move_to(_x, _y-15) << color(0,0,0) << box(_size_x, _size_y);
        gout << color(255,0,0);
        gout << move_to(_x, _y) << text("X nyert");
    }
    if(_window->checkWin()==1){
        gout << move_to(_x, _y-15) << color(0,0,0) << box(_size_x, _size_y);
        gout << color(255,0,255);
        gout << move_to(_x, _y) << text("O nyert");
    }
}

void Comment::handle(event ev)
{

}
int Comment::data(){

}
int Comment::data2(){

}


