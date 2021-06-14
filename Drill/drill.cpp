#include "Simple_window.h"
#include "Graph.h"


int main()
{

	Point tl {100,100}; // to become top left corner of window
	Simple_window win {tl,600,400,"My Window"}; // make a simple window

	//Axis
	Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"};
	Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
	ya.set_color(Color::cyan);
	xa.set_color(Color::cyan);

	//Function sine
	Function sine {sin,0,100,Point{20,150},1000,50,50};
	sine.set_color(Color::red);


	//Poly
	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	poly.set_color(Color::blue);


	//Rectangle
	Rectangle r {Point{200,200}, 100, 50};
	r.set_color(Color::red);


	//Closed_polyline
	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{50,75});


	//text
	Text t {Point{150,150}, "Hello, graphical world!"};
	t.set_font(Font::times_bold);
	t.set_font_size(20);


	//img
	//Image ii {Point{100,50},"badge.jpg"};
	//ii.move(100,200);

	//Colors and stuff
	r.set_fill_color(Color::yellow); // color the inside of the rectangle
	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::green);

	win.attach(xa);
	win.attach(ya);
	win.attach(sine);
	win.attach(poly);
	win.attach(r);
	win.attach(poly_rect);
	win.attach(t);
	//win.attach(ii);
	win.wait_for_button();
}

