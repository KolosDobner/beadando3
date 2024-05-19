#include "widgets.hpp"
#include "window.hpp"
#include <set>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
using namespace genv;

Window::Window(int XX, int YY) {
    gout.open(XX,YY);
}
    bool start = true;
    int filler = 0;
int Window::fillere(){
    if (filler%2==0){
        return 1;
    }else{
        return 2;
    }
}

vector<vector<int>>table(18, vector<int>(18, 0));
bool checkDirection( int row, int col, int dr, int dc, int player) {
    for (int i = 0; i < 5; ++i) {
        int r = row + i * dr;
        int c = col + i * dc;
        if (r < 0 || r >= table.size() || c < 0 || c >= table[0].size() || table[r][c] != player) {
            return false;
        }
    }
    return true;
}

int Window::checkWin() {
    int n = table.size();
    int m = table[0].size();
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
            if (table[row][col] != 0) {
                int player = table[row][col];
                if (checkDirection(row, col, 0, 1, player) ||
                    checkDirection(row, col, 1, 0, player) ||
                    checkDirection(row, col, 1, 1, player) ||
                    checkDirection(row, col, 1, -1, player))
                {
                    return player;
                }
            }
        }
    }
    return 0;
}
bool Window::full(){
    int counter = 0;
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j <= 18 ; ++j) {
            if(table[i][j] != 0){
                counter++;
            }
        }
    }
    if(counter == 17*17){
        return true;
    }
    else{
        return false;
    }
}
void Window::event_loop() {
    event ev;
    set<int>v;
    bool checked=false;
    int focus = -1;
    while(gin >> ev) {
        if(!full()){
        if (ev.type == ev_mouse && ev.button == btn_left) {
            for (size_t i = 0; i<_widgets.size(); i++) {
                if (_widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                    focus = i;
                    checked=false;
                    table[_widgets[focus]->data()][_widgets[focus]->data2()]=fillere();
                    for(auto j:v){
                        if (j==i){
                            checked=true;
                        }
                    }
                    if(!checked){
                        filler++;
                        v.insert(i);
                        break;
                    }
                }
            }
        }
        if (focus!=-1) {
            _widgets[focus]->handle(ev);
        }

        for (auto* w : _widgets) {
            w->draw();
        }
        gout << refresh;
    }
    }
    ofstream f("ellenorzes.txt");
    for(int a = 0; a<18;a++){{
            for(int b = 0;b<18;b++){
                f << table[a][b] << " ";
            }
            f << endl;
        }
    }


    f.close();
}
