
#include "Hexagon1.h"

//make the six points in the hexagon
Point Hexagon::center(point_of_Hexagon l)
{
	return Point(l.first, l.second);
}
Point Hexagon::p1(point_of_Hexagon l)
{
	return Point(l.first, l.second-distance);
}
Point Hexagon::p2(point_of_Hexagon l)
{
	return Point(l.first+sqrt(3.0) * distance/2,l.second-distance/2);
}
Point Hexagon::p3(point_of_Hexagon l)
{
	return Point(l.first+sqrt(3.0)*distance/2,l.second+distance/2);
}
Point Hexagon::p4(point_of_Hexagon l)
{
	return Point(l.first, l.second+distance);
}
Point Hexagon::p5(point_of_Hexagon l)
{
	return Point(l.first-sqrt(3.0)*distance/2,l.second+distance/2);
}
Point Hexagon::p6(point_of_Hexagon l)
{
	return Point(l.first-sqrt(3.0)*distance/2,l.second-distance/2);
}

//to judge if the hexagon can be created
Hexagon::Hexagon(point_of_Hexagon l,double dis)
	:location(l), distance(dis)
	{
		if (dis<=0) throw error2();
		center(l);
		hexagon.add (p1(l));
		hexagon.add (p2(l));
		hexagon.add (p3(l));
		hexagon.add (p4(l));
		hexagon.add (p5(l));
		hexagon.add (p6(l));
	}

//default constructor
Hexagon::Hexagon()
	:location(make_pair(0,0)),distance(0){}

//to fullfill the color of the hexagon
void Hexagon::set_full_color(Color x)
{
	hexagon.set_fill_color(x);
}
//add the hexagon to the window
void Hexagon::add_to_swin(Simple_window& win)
{
	win.attach(hexagon);
}
//to add the hexagon in the same row
void Hexagon::muti_add_to_swin(Simple_window& win,int x,Color y)
{
	double interval=sqrt(3.0)* distance;
	for(int i=0;i<x;i++)
	{
		Hexagon *h1=new Hexagon (make_pair(location.first+i*interval,location.second),distance);
		h1->set_full_color(y);
		h1->add_to_swin(win);
		Hexagon *h2=new Hexagon (make_pair(location.first-i*interval,location.second),distance);
		h2->set_full_color(y);
		h2->add_to_swin(win);
			
	}
}
//to add the hexagon in the neighborthood but not in the same row,'cause teh muti_add_to_swin has implenment this
void Hexagon::make_vicinity__hexagon(Simple_window& win,int x,Color col_down,Color col_up)
{
	double interval1=sqrt(3.0)*distance;
	double interval2=sqrt(3.0)*distance/2;
	double interval3=distance*3/2;
		 
	for (int i=1;i<x;i++)
	{
	double New_first_1=location.first+i*interval2;
	double New_second_1=location.second+i*interval3;
	Hexagon *h1=new Hexagon (make_pair(New_first_1,New_second_1),distance);
	h1->add_to_swin(win);
	h1->muti_add_to_swin(win,x,col_down);
	}

	for (int i=1;i<x;i++)
	{
	double New_first_1=location.first-+i*interval2;
	double New_second_1=location.second-i*interval3;
	Hexagon *h1=new Hexagon (make_pair(New_first_1,New_second_1),distance);
	h1->add_to_swin(win);
	h1->muti_add_to_swin(win,x,col_up);
	}
}
