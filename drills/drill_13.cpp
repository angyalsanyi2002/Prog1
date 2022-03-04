#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){
	try {
		Point t1 {300, 50};
		Simple_window win (t1, 800, 1000, "My window");
		win.wait_for_button();
		
		int x_size=800;		//800*800-as rács, 100 pixeles négyzetekkel
		int y_size=800;
		int x_grid = 100;
    		int y_grid = 100;
		Lines grid;		
		
		for(int i=0; i<=800; i+=100)
		{
			grid.add(Point(i,0), Point(i, y_size));
			grid.add(Point(0,i), Point(x_size, i));
		}
		
		win.attach(grid);
		win.wait_for_button();
		
		
		Vector_ref<Rectangle> rects;	//átló menti négyzetek pirosra festése
		for (int i = 0; i < x_size; i += x_grid) {
			rects.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
			rects[rects.size() - 1].set_color(Color::invisible);
			rects[rects.size() - 1].set_fill_color(Color::red);
			win.attach(rects[rects.size() - 1]);
		}

		win.wait_for_button();
		
		Image moon1{Point{0,300}, "moon.jpg"};	//3 kép beillesztése
		win.attach(moon1);
		Image moon2{Point{500,0}, "moon.jpg"};
		win.attach(moon2);
		Image moon3{Point{300,600}, "moon.jpg"};
		win.attach(moon3);
		win.set_label("My window");
		win.wait_for_button();
		
		Image kep{Point{0,0},"kep.jpg"};
		kep.set_mask(Point{0,0},100,100);	//kép méretre vágása
		win.attach(kep);
		win.set_label("My window");
		win.wait_for_button();
		
		for (int i=0 ; i<8; ++i){	//léptetés négyzetről-négyzetre
			for (int j=0; j<8; ++j){
				kep.move(100,0);
				win.wait_for_button();
			}
			kep.move(-700,100);
			win.wait_for_button();
			}

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
/*
g++ -w -Wall -std=c++11 ./GUI/Graph.cpp ./GUI/Window.cpp ./GUI/GUI.cpp ./GUI/Simple_window.cpp drill_13.cpp `fltk-config --ldflags --use-images` -o a.out
*/
