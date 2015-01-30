#include "Hexagon1.h"
//here's an example of the class Hexagon
int main()
{
	try{
		using namespace Graph_lib;
		Point tl(100, 100);
		Simple_window win(tl, 1000, 600, "zdl_window");
		Hexagon t1(make_pair(200,300),30);
		t1.add_to_swin(win);	
		t1.muti_add_to_swin(win,20,Color::blue);
		t1.make_vicinity__hexagon(win,20,Color::magenta,Color::yellow);
		win.wait_for_button();
	}
	catch (error2)
	{
		cout<<"something went worry"<<endl;
	}
}
