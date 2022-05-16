#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
try{
	Point tl {100,100}; //ablak ball felső sarka
	
	Simple_window win {tl,600,400,"My window #1"};
	
	// screen coordinate tl for top left corner
	// window size(600*400)
	// title: Canvas
	
	win.wait_for_button();
	
	Axis xa{Axis::x, Point{20,300}, 280, 10, "x axis"}; //tengely létrehozása
	// an Axis is a kind of Shape
	// Axis::x means horizontal
	// starting at (20,300)
	// 280 pixels long
	// 10 “notches”
	// label the axis "x axis"
	
	win.attach(xa);			//xa-t csatoljuk az ablakhoz
	win.set_label("My window #2"); //újranevezzük az ablakot
	win.wait_for_button();		//a gombbal megjelenítjük
	
	Axis ya{Axis::y, Point{20,300},280,10, "y axis"};
	ya.set_color(Color::cyan);	//y tengely színe
	ya.label.set_color(Color::dark_red); //szövge színe
	win.attach(ya);
	win.set_label("My window #3");
	win.wait_for_button();
	
	Function sine {sin,0,100,Point{20,150},1000,50,50}; //sinus görbe
	// plot sin() in the range [0:100) with (0,0) at (20,150)
	// using 1000 points; scale x values *50, scale y values *50
	
	win.attach(sine);
	win.set_label("My window #4");
	win.wait_for_button();
	
	sine.set_color(Color::blue);  //új színt adunk a sinusnak
	
	Polygon poly;		 //a polygon; a Polygon is a kind of shape
	poly.add(Point{300,200}); //3 pont a háromszöghöz
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	
	poly.set_color(Color::red);	//3szög vonal színe
	poly.set_style(Line_style::dash); //szagatott vonal
	win.attach(poly);
	
	//win.set_label("My window #5");
	win.wait_for_button();
	
	Rectangle r{Point{200,200}, 100, 50};  //bal felső sarok, szélesség, magasság
	win.attach(r);
	win.set_label("My window #6");
	win.wait_for_button();
	
	Closed_polyline poly_rect;	//téglalap kirajzolása, majd bővitjük 1 ponttal
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{50,75});
	win.attach(poly_rect);
	win.wait_for_button();
	
	r.set_fill_color(Color::yellow); 		//a háromszög kitöltőszíne
	poly.set_style(Line_style(Line_style::dash,4));	//3szög körvonala szagatott, vastagított
	poly_rect.set_style(Line_style(Line_style::dash,2)); //5szög vonala
	poly_rect.set_fill_color(Color::green);		//5szög színe
	win.set_label("My window #7");
	win.wait_for_button();
	
	Text t {Point{150,150}, "Hello, graphical world!"};  //szöveg
	win.attach(t);
	win.set_label("My window #8");
	win.wait_for_button();
	
	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.set_label("My window #9");
	win.wait_for_button();
	
	Image ii{Point{100,50},"shrek3.jpg"};
	win.attach(ii);
	win.set_label("My window #10");
	win.wait_for_button();
	
	ii.move(100,200);
	win.set_label("My window #11");
	win.wait_for_button();
	
	Circle c {Point{100,200},50};	//kör
	Ellipse e {Point{100,200}, 75,25}; //ellipszis
	e.set_color(Color::dark_red); 	//ellipszis színe
	Mark m {Point{100,200},'x'};    //x
	
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.set_label("Canvas #12");
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
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill_12.cpp `fltk-config --ldflags --use-images` -o a.out
*/
