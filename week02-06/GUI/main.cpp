/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;

    constexpr int xmax = 1024;
    constexpr int ymax = 768;

    constexpr int x_orig = xmax/2;
    constexpr int y_orig = ymax/2;

    int rmin = -11;
    int rmax = 11;
    
    int n_points = 400;

    Simple_window win {Point{100,100}, xmax, ymax, "My label"};

	Point origo {x_orig, y_orig};

	int xlength = xmax - 40;
	int ylength = ymax - 40;

	int xscale = 30, yscale = 30;

	Function s (one, rmin, rmax, origo, n_points, xscale, yscale);
	Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
	Function cos_func ( [] (double x) { return cos(x); },
						rmin, rmax, origo, n_points, xscale, yscale);

	Axis x_axis {Axis::x, Point{20, y_orig}, xlength, xlength/xscale, "x"};
	Axis y_axis {Axis::y, Point{x_orig, ylength + 20}, ylength, ylength/yscale, "y"};

	Rectangle rect {Point{200,200}, 100, 50};

	rect.set_fill_color(Color::yellow);
	rect.set_style(Line_style(Line_style::dash, 4));

	Text text {Point{200,400}, "This is my text"};
	text.set_font(Font::times_bold);
	text.set_font_size(20);

	Image img {Point{100,100}, "badge.jpg"};

	Circle circ {Point{700,700}, 100};

	Polygon poly;
	poly.add(Point(300,200));
	poly.add(Point(350,100));
	poly.add(Point(400,200));
	poly.set_color(Color::red);
	poly.set_style(Line_style(Line_style::dashdotdot,2));
	poly.set_fill_color(Color::dark_yellow);

	Closed_polyline poly_rect;
	poly_rect.add(Point(100,50));
	poly_rect.add(Point(200,50));
	poly_rect.add(Point(200,100));
	poly_rect.add(Point(100,100));
	poly_rect.add(Point(50,75));

	Mark mark {Point(100,200), 'x'};

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
		<< "window size: " << win.x_max() << "*" << win.y_max();

	Text sizes {Point(500,500), oss.str()};

	//Exercises

	//1
	Rectangle blue_rect ({Point(50,50)}, 100, 40);
	blue_rect.set_color(Color::blue);

	Polygon red_rect;

	red_rect.add(Point(200,50));
	red_rect.add(Point(300,50));
	red_rect.add(Point(300,90));
	red_rect.add(Point(200,90));
	red_rect.set_color(Color::red);

	win.attach(blue_rect);
	win.attach(red_rect);


	//2
	Rectangle howdy_rect ({Point(50,140)},100,30);

	Text howdy ({Point(65,160)}, "Howdy!");

	howdy.set_font(Font::courier);
	howdy.set_font_size(20);

	win.attach(howdy_rect);
	win.attach(howdy);


	//3
	Text init_C ({Point(400,200)}, "C");

	init_C.set_font_size(150);
	init_C.set_color(Color::red);
	init_C.set_font(Font::times_bold);

	Text init_S ({Point(510,200)}, "S");

	init_S.set_font_size(150);
	init_S.set_color(Color::dark_green);
	init_S.set_font(Font::times_bold);

	Text init_B ({Point(610,200)}, "B");

	init_B.set_font_size(150);
	init_B.set_color(Color::dark_magenta);
	init_B.set_font(Font::times_bold);

	win.attach(init_C);
	win.attach(init_S);
	win.attach(init_B);


	//4 ezt tuti nagyon tulbonyolitottam, okosabb megoldas nem jutott az eszembe :(

	constexpr int checker_start_x = 50;
	constexpr int checker_start_y = 220;
	constexpr int checker_size = 50;

	Rectangle box((Point(checker_start_x,checker_start_y)),400,400);

	Vector_ref<Rectangle> checker;

	int current_x = 50;
	int current_y = 220;
	int row = 0;

    for (int i = 0; i < 64; ++i)
    {
    	checker.push_back(new Rectangle(Point(current_x,current_y),checker_size,checker_size));

    	current_x += checker_size;
    	if (i % 2 == 0)
    	{
    		if (row % 2 == 0)
    		{
    			checker[i].set_fill_color(Color::red);
    		}
    		else checker[i].set_fill_color(Color::white);
    	}
    	else
    	{
    		if (row % 2 == 0)
    		{
    			checker[i].set_fill_color(Color::white);
    		}
    		else checker[i].set_fill_color(Color::red);
    	}
    	checker[i].set_color(Color::invisible);
    	if (i % 8 == 7)
    	{
    		current_x -= 400;
    		current_y += 50;
    		row++;
    	}

    	win.attach(checker[i]);
    }


	//5 ezt lehet szebben? :(

	Rectangle frame_rect(Point(xmax/6,ymax/8),2*xmax/3,3*ymax/4);

	/*Polygon frame;

	frame.add(Point(xmax/6-24,ymax/8-24));
	frame.add(Point(2*xmax/3+xmax/6+24,ymax/8-24));
	frame.add(Point(2*xmax/3+xmax/6+24,ymax/8+24+3*ymax/4));
	frame.add(Point(xmax/6-24,ymax/8+24+3*ymax/4));*/

	Lines frame;
	frame.add(Point(xmax/6-48,ymax/8-24),Point(2*xmax/3+xmax/6+48,ymax/8-24));
	frame.add(Point(2*xmax/3+xmax/6+24,ymax/8-24),Point(2*xmax/3+xmax/6+24,ymax/8+24+3*ymax/4));
	frame.add(Point(2*xmax/3+xmax/6+48,ymax/8+24+3*ymax/4),Point(xmax/6-48,ymax/8+24+3*ymax/4));
	frame.add(Point(xmax/6-24,ymax/8+24+3*ymax/4),Point(xmax/6-24,ymax/8-24));

	frame.set_color(Color::red);
	frame.set_style(Line_style(Line_style::solid,48));

	win.attach(frame_rect);
	win.attach(frame);


	//6

	Circle doesnt_fit(Point(6000,5000),100); //gondolom odateszi, csak nem latjuk

	Simple_window big {Point{100,100}, 4800,2400, "tul nagy"}; //aranyosan lekicsinyiti az ablakot

	big.attach(doesnt_fit);
	//big.wait_for_button();

	//7

	Simple_window house {Point{100,100}, 600,800, "haziko"};

	Rectangle base(Point(150,400),300,300);
	base.set_fill_color(Color::yellow);

	Polygon roof;

	roof.add(Point(150,400));
	roof.add(Point(450,400));
	roof.add(Point(300,200));
	roof.set_fill_color(Color::dark_red);

	Rectangle door(Point(200,600),50,100);
	door.set_fill_color(Color::dark_yellow);

	Circle knob(Point(240,660),3);
	knob.set_fill_color(Color::black);

	Rectangle bottom_window(Point(300,610),100,50);
	bottom_window.set_fill_color(Color::cyan);

	Lines window_bars;
	window_bars.add(Point(350,610),Point(350,659));
	window_bars.add(Point(300,635),Point(400,635));

	Circle top_window1(Point(225,500),35);
	Circle top_window2(Point(375,500),35);
	top_window1.set_fill_color(Color::cyan);
	top_window2.set_fill_color(Color::cyan);

	house.attach(base);
	house.attach(roof);
	house.attach(door);
	house.attach(knob);
	house.attach(bottom_window);
	house.attach(window_bars);
	house.attach(top_window1);
	house.attach(top_window2);
	

	house.wait_for_button();

	//win.attach(img);
	//win.attach(circ);
	//win.attach(text);
	//win.attach(rect);
	//win.attach(s);
	//win.attach(sq);
	//win.attach(cos_func);
	//win.attach(x_axis);
	//win.attach(y_axis;
	//win.attach(poly);
	//win.attach(poly_rect);
	//win.attach(mark);
	//win.attach(sizes);
	
	

	win.attach(box);
    //win.wait_for_button();

}
