#include "Poly.h"

//in the default constructor,it has no points in the poly_points
Poly::Poly ()
	:amount_of_point(0)
{
	poly_points.clear(); //to clear the points in the vector
}

Poly::Poly (vector<Point> p)
	:amount_of_point(p.size()),poly_points(p)	//the amount of the point is the size of the vector
{
	//if the is_poly return false,throw the error
	if (!(is_poly())) error("The points you enter is not enough or can't be print out well"); 
	for(int i=0;i<poly_points.size();i++)
	{
		polygon.add(poly_points[i]);		//to add the points in vector to a figure
	}
	//but the line of the last point and the first point should be judged 
	Polygon text_poly;	//use the text_poly to judge if it's right
	for(int i=1;i<poly_points.size();i++)
	{
		text_poly.add(poly_points[i]);
	}
	text_poly.add(poly_points[0]);	//the line between first and second must be right 'cause of the polygon
}

bool Poly::is_poly()
{
	if(poly_points.size() < 3)  return false;	//if the amount of the points is less than 3,cannot be a Poly,return false
	for (int i=0;i < poly_points.size();i++)
	{
		if(poly_points[i].x < 0||poly_points[i].y < 0)	//if the x or y of the point is less than nought,return false
			return false;
		for (int j=0;j < i;j++)
		{
			if(poly_points[i]==poly_points[j])	//if the vector has the same point, return false
				return false;
		}
	}
}

//add it to the window
void Poly::add_to_swin(Simple_window& win)
{
	win.attach(polygon);
}
