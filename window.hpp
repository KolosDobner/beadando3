#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <vector>

class Widget;

class Window {
private:
    std::vector<Widget*> _widgets;
    bool _open;
    int _XX;
    int _YY;
public:
    Window(int xx, int yy);
    void add_widget(Widget* w) { _widgets.push_back(w); }
    void event_loop();
    void set_title(std::string title);
    void open();
    void close();
    int fillere();
    int checkWin();
};

#endif // WINDOW_H
