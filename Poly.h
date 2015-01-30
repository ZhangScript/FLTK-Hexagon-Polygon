#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include <iostream>
using namespace Graph_lib;
using namespace std;

//first we need to use the function in the Polygon,so the poly inherits the Polygon
class Poly :public Polygon
{
private:
	int amount_of_point;
	vector<Point> poly_points;
	Polygon polygon;
public:
	int get_amount_of_point()const{return amount_of_point;} //get the amount of the points in the vector
	bool is_poly();								//to judge if it's a Poly with new criterion
	Poly();										//the default constructor
	Poly(vector<Point> p);						//the Poly constructor with a vector of the points 						
	void add_to_swin (Simple_window& win);		//attach the Poly to the screen
};
