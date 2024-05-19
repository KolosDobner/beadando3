#include "graphics.hpp"
#include "widgets.hpp"
#include "textbox.hpp"
#include "numbox.hpp"
#include "playbox.hpp"
#include "comment.hpp"
#include "window.hpp"
#include <vector>
#include <string>
#include <fstream>
#include<iostream>

using namespace genv;
using namespace std;
const int box_size = 50;
const int window_size = 950;

class MyWindow : public Window{
    /*TextBox * t1;
    TextBox * t2;
    NumBox * n1 ;
    NumBox * n2;*/
    PlayBox * p1;
    Comment * c1;

public:
    void pakol(){
        /*if(t1->get_size()>0 && t1->get_value()!="null"){
            t2->new_item(t1->get_value());
            t1->remove_item(t1->get_value());
        }
    };
    void visszapakol(){
        if(t2->get_size()>0 && m2->get_value()!="null"){
            t1->new_item(t2->get_value());
            t2->remove_item(t2->get_value());
        }*/
    }
    MyWindow():Window(window_size, window_size){
        /*vector<string> text1{"valassz valamit","alma", "korte", "dinnye", "citrom", "banan"};
        vector<string> text2{"valassz valakit", "Bob", "Dzsonatan"};
        t1 = new TextBox(this, 50, 30, 200, 30, text1, 6); //x, y, size_x, yize_y, szoveg, maxdb
        t2 = new TextBox(this, 50, 250, 250, 30, text2, 3);
        n1 = new NumBox(this, 400, 30, 60, 30, 10, 200, -200); //x, y, size_x, size_y, szam, max, min
        n2 = new NumBox(this, 400, 250, 80, 30, 0, 100, -100);*/
        c1 = new Comment (this, window_size/2, 25, 150, 10);
        for (int x = box_size; x < window_size-box_size; x=x+box_size) {
            for (int y = box_size; y < window_size-box_size; y=y+box_size) {
                p1 = new PlayBox(this, x, y, box_size, box_size);
            }
        }
    }
};


int main(){
    gout << font("LiberationSans-Regular.ttf",20);
    MyWindow MW;
    MW.event_loop();
    return 0;
}
