/*
    g++ mandelbrot.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o mandelbrot `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }


int main
{
	vector <int> mandelbrot;
}