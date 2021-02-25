/*
    g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
	constexpr int xmax = 1000;
    constexpr int ymax = 800;

    Simple_window win {Point{100,100}, xmax, ymax, "grid"};

    constexpr int x_size = 800;
    constexpr int y_size= 800;

    constexpr int gridx = 100;
    constexpr int gridy = 100;

    Lines grid;
    for (int x = gridx; x <= 800; x+=gridx)
    {
    	grid.add(Point(x,0),Point(x,y_size));
    }

    for (int y = gridy; y <= 800; y+=gridy)
    {
    	grid.add(Point(0,y),Point(x_size,y));
    }
    win.attach(grid);

    Image img {Point{300,0}, "fat_cat.jpg"};
    Image img2 {Point{100,500}, "fat_cat.jpg"};
    Image img3 {Point{600,300}, "fat_cat.jpg"};

    win.attach(img);
    win.attach(img2);
    win.attach(img3);

    Vector_ref<Rectangle> vr;
    for (int i = 0; i < 8; ++i)
    {
    	vr.push_back(new Rectangle(Point(i*gridx, i*gridy),gridx,gridy));
    	vr[i].set_fill_color(Color::red);
    	vr[i].set_color(Color::invisible);
    	win.attach(vr[i]);
    }

    /*Image moving_pic (Point(0,0), "gradient_bilinear.jpg");

    win.attach(moving_pic);
    for (int i = 0; i < 8; ++i)
    {
    	for (int j = 0; j < 8; ++j)
    	{
    		win.wait_for_button();
    		if(j<7) moving_pic.move(100,0);
    		else moving_pic.move(-700,100);
    	}
    }*/
    win.wait_for_button();
}