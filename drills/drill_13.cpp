#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){
	try {
		Point t1 {300, 50};
		Simple_window win (t1, 1000, 800, "My window");
		win.wait_for_button();
		
		int x_size=800;
		int y_size=800;
		Lines grid;		
		
		for(int i=0; i<=800; i+=100)
		{
			grid.add(Point(i,0), Point(i, y_size));
			grid.add(Point(0,i), Point(x_size, i));
		}
		
		win.attach(grid);
		win.wait_for_button();
		
		/*kitölteni az átló négyzeteket
			rect r {Point(0,0), 100, 100};
			r.set_fill_color (Color::red);
		VAGY
			for(i=0...8)
			rect r {Point(i*100, i*100), 100, 100};
			win.attach(r);
		VAGY
			vector <Rectangle*> v;
			for(i=0...8)
			win.push_back(new Rectangle(Point(i*100,i*100),100,100));
			v[v.size()-1], set_fill_color (color::red);
			win.attach(v[v.size()-1]);
			
			new osztaly(constructor)
			new Rectangle (Point p, hh,ww)		
		*/
		//vector <Rectangle*> v;
		
		
		for(int i=0; i<=800; i+=100)
		{
		Rectangle r {Point{0+i, 0+i}, 100, 100};
    		win.attach(r);
    		r.set_fill_color(Color::red);
    		//r.set_style(Line_style(Line_style::solid, 0));
    		//r.set_style(Color(Color::invisible));
    		win.set_label("My 2nd window");
    		win.wait_for_button();
		
		}
		/*
		Vector_Ref<Graph_lib::Rectangle> vr;
		for(int i=0; i<8
		
		
		HÁZI
		200*200 jpeg v gif
		set_mask
		
		move fv.
		VAGY
		while(true{
		kép mozgatás
		wait_for_button();
		}
		*/
	}
	catch (exception& e) {
    	cerr << "exception: " << e.what() << '\n';
    	return 1;
	}
	catch(...) {
    	cerr << "error\n";
    	return 2;
	}
	}


