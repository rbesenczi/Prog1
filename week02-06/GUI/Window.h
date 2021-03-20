#ifndef WINDOW_GUARD
#define WINDOW_GUARD 1

#include "fltk.h"

#include "std_lib_facilities.h"

#include "Point.h"

namespace Graph_lib {

class Shape;
class Widget;

class Window : public Fl_Window { 
public: 
	Window(int w, int h, const string& title );
	Window(Point xy, int w, int h, const string& title );
	virtual ~Window() { }

	int x_max() const { return w; }
	int y_max() const { return h; }

	void resize(int ww, int hh) { w=ww, h=hh; size(ww,hh); }

	void set_label(const string& s) { label(s.c_str()); }

	void attach(Shape& s);
	void attach(Widget& w);

	void detach(Shape& s);
	void detach(Widget& w);

	void put_on_top(Shape& p);

protected:
	void draw();
     
private:
	  vector<Shape*> shapes;
	  int w,h;

	  void init();
}; 

int gui_main();

inline int x_max() { return Fl::w(); }
inline int y_max() { return Fl::h(); }

}
#endif
