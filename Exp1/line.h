#pragma once
#include<string>
using namespace std;
class line {
public:
	line(int a, int b, int c, int d, string e);
	int a, b, fx, fy, fx1, fy1;
	string color;
	
};
line::line(int a, int b, int c, int d, string e) {
	fx = a * 10;
	fx1 = c * 10;
	fy = b * 10;
	fy1 = d * 10;
	color = e;

}