#ifndef GUI_GUARD
#define GUI_GUARD

#include "Window.h"
#include "Graph.h"

namespace Graph_lib {

typedef void* Address;
typedef void(*Callback)(Address, Address);

template<class W> W& reference_to(Address pw)
{
    return *static_cast<W*>(pw);
}

class Widget {
public:
    Widget(Point xy, int w, int h, const string& s, Callback cb)
        : loc(xy), width(w), height(h), label(s), do_it(cb)
    {}

    virtual void move(int dx,int dy) { hide(); pw->position(loc.x+=dx, loc.y+=dy); show(); }
    virtual void hide() { pw->hide(); }
    virtual void show() { pw->show(); }
    virtual void attach(Window&) = 0;

    Point loc;
    int width;
    int height;
    string label;
    Callback do_it;

    virtual ~Widget() { }

protected:
    Window* own;
    Fl_Widget* pw;
private:
    Widget& operator=(const Widget&);
    Widget(const Widget&);
};

struct Button : Widget {
    Button(Point xy, int w, int h, const string& label, Callback cb)
        : Widget(xy,w,h,label,cb)
    {}

    void attach(Window&);
};

struct In_box : Widget {
    In_box(Point xy, int w, int h, const string& s)
        :Widget(xy,w,h,s,0) { }
    int get_int();
    string get_string();

    void attach(Window& win);
};

struct Out_box : Widget {
    Out_box(Point xy, int w, int h, const string& s)
        :Widget(xy,w,h,s,0) { }
    void put(int);
    void put(const string&);

    void attach(Window& win);
};

struct Menu : Widget {
    enum Kind { horizontal, vertical };
    Menu(Point xy, int w, int h, Kind kk, const string& label);

    Vector_ref<Button> selection;
    Kind k;
    int offset;
    int attach(Button& b);
    int attach(Button* p);

    void show()
    {
        for (unsigned int i = 0; i<selection.size(); ++i)
            selection[i].show();
    }
    void hide()
    {
        for (unsigned int i = 0; i<selection.size(); ++i) 
            selection[i].hide(); 
    }
    void move(int dx, int dy)
    {
        for (unsigned int i = 0; i<selection.size(); ++i) 
            selection[i].move(dx,dy);
    }

    void attach(Window& win)
    {
        for (int i=0; i<selection.size(); ++i) win.attach(selection[i]);
        own = &win;
    }
};

}

#endif
