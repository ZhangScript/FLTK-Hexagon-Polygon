/*3.  （图形类，书中练习 P.286，18）
Define the Class named Poly to show the Polygon.
In the meantime, judge whether it is the polygon or not in the constructed function: 
Poly( vector<Point> points){ 
	if(points.size()<3) error("less than 3 points in a Polygon"); 
	try{ 
		for(int i=0; i<points.size(); i++){ 
		Polygon::add(points[i]); //这里由Polygon::add进行检查线条是否相交 
		} 
	}catch(runtime_error &e){ 
	cerr<<e.what(); // intersect in polygon 
	} 
}
*/

#include "Poly.h"
//the use of the example of the Poly
int main()
{
	try{
	//not special method, just draw the graph and the text and the line,and attach them to the screen 
	Point tl(100, 100);
	Simple_window win(tl, 700, 500, "zdl_window");
	vector<Point> v;
//it's the right using version of the Poly
	v.push_back(Point(10, 40));
	v.push_back(Point(20, 80));
	v.push_back(Point(200, 80));
	v.push_back(Point(30, 120));
	v.push_back(Point(333,300));
	v.push_back(Point(20, 400));

//it's the worry using version of the Poly
	//v.push_back(Point(10, 40));
	//v.push_back(Point(20, 80));
	//v.push_back(Point(30, 120));
	//v.push_back(Point(200, 80));	
	//v.push_back(Point(333,300));
	//v.push_back(Point(20, 400));
	Poly p(v);
	p.add_to_swin(win); 
	win.wait_for_button();
	}
	//the solution to the error
	catch (exception& e)
	{
		cout<<e.what()<<endl;
	}
	catch( runtime_error)
	{
		cout<<"something went worry with the poly"<<endl;
	}
	catch(...)
	{
		cout<<"Oops,something worry with the poly"<<endl;
	}
	system("pause");
 
}
