#include "Simple_window.h"

Simple_window::Simple_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    next_button(Point(x_max()-70,0), 70, 20, "Next", cb_next),
    button_pushed(false)
{
    attach(next_button);
}

bool Simple_window::wait_for_button()
{
    show();
    button_pushed = false;
#if 1
    while (!button_pushed) Fl::wait();
    Fl::redraw();
#else
    Fl::run();
#endif
    return button_pushed;
}

void Simple_window::cb_next(Address, Address pw)
{
    reference_to<Simple_window>(pw).next();    
}

void Simple_window::next()
{
    button_pushed = true;
    hide();
}
