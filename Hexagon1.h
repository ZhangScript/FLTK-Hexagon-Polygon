// Getting access to the graphics system (don’t forget to install):
#include "Simple_window.h"  // stuff to deal with your system’s windows
#include "Graph.h"  // graphical shapes
#include <iostream>
#include <cmath>
#include <vector>
using namespace Graph_lib;
//make the it easy to understand ,so we use the pair
typedef pair<double, double> point_of_Hexagon ;
//error solution
class error2{};
//define a new class
class Hexagon {
private:
	point_of_Hexagon location;			//record the location of the Hexagon
	double distance;					//to get the size of the Hexagon
	Closed_polyline hexagon;			//create a polyline
	Point center(point_of_Hexagon l);	//the center of the hexagon
	//here are the six point of the hexagon
	Point p1 (point_of_Hexagon l) ;
	Point p2 (point_of_Hexagon l) ;
	Point p3 (point_of_Hexagon l) ;
	Point p4 (point_of_Hexagon l) ;
	Point p5 (point_of_Hexagon l) ;
	Point p6 (point_of_Hexagon l) ;

public:
	Hexagon(point_of_Hexagon l,double dis);
	Hexagon();
	int get_distance()const {return distance;}			//get the distance and get the size
	point_of_Hexagon get_location()const {return location;}	//get the location of the hexagon
	//already been proclaim in the encapsulation.cpp
	void set_full_color(Color x);					
	void add_to_swin(Simple_window& win);
	void muti_add_to_swin(Simple_window& win,int x,Color y);
	void make_vicinity__hexagon(Simple_window& win,int x,Color col_down,Color col_up);
	// the finalizer to delete the new space for the Hexagon we create in the function
	~Hexagon()
	{
		delete this;
	}
};

