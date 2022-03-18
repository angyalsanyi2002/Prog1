#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
try{
	Point tl {100,100}; //ablak ball felső sarka
	
	Simple_window win {tl,600,600,"Function graphs."};
	
	Axis x{Axis::x, Point{100,300}, 400, 20, "1 == 20 pixels"};
	win.attach(x);
	x.set_color(Color::red);
	
	Axis y{Axis::y, Point{300,500}, 400, 20, "1 == 20 pixels"};
	win.attach(y);
	y.set_color(Color::red);
	
    	constexpr int min = -10;
    	constexpr int max = 11;

	constexpr int num_points = 400;

	constexpr int x_scale = 20;
	constexpr int y_scale = 20;

	const Point orig {300, 300};

	Function f1 {one, min, max, orig, num_points, x_scale, y_scale};
	Function f2 {slope, min, max, orig, num_points, x_scale, y_scale};
	Function f3 {[](double x) { return x * x; }, min, max, orig, num_points, x_scale, y_scale};
	Function f4 {cos, min, max, orig, num_points, x_scale, y_scale};
	f4.set_color(Color::blue);
	Function f5 {[](double x) { return cos(x) + slope(x); }, min, max, orig, num_points, x_scale, y_scale};
	Text t {Point{90,400}, "x/2"}; 
	t.set_font(Font::times_bold);
	t.set_font_size(12);
	
	win.attach(t);
	win.attach(f1);
	win.attach(f2);
	win.attach(f3);
	win.attach(f4);
	win.attach(f5);

	win.wait_for_button();
}
catch(exception&e){
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch(...){
	cerr << "error: \n";
	return 2;
}

/*
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill_15_2.cpp `fltk-config --ldflags --use-images` -o a.out
*/
