#include <iostream>
#include <cmath>
using namespace std;

struct point_t { // Points with integer coordinates
    int x; 
    int y;
};


void print_point(point_t p)
{
	cout << "(" << p.x << ", " << p.y << ")" << endl;
}

struct triangle_t {
    point_t pt[3]; // Three points define a triangle
};

bool points_equal(point_t p1, point_t p2)
{
	if(p1.x == p2.x && p1.y == p2.y)
		return true;
	return false;
}

bool x_equal(point_t p1, point_t p2)
{
	if(p1.x == p2.x)
		return true;
	return false;
}

bool y_equal(point_t p1, point_t p2)
{
	if(p1.y == p2.y)
		return true;
	return false;
}


bool isdegenerate(triangle_t tri)
{
	if(points_equal(tri.pt[0],tri.pt[1]) || points_equal(tri.pt[1],tri.pt[2]) || points_equal(tri.pt[0],tri.pt[2]))
		return false;
	return true;
}



bool isright(triangle_t tri)
{
	if(!isdegenerate(tri))
		return false;
	point_t vector1; 
	vector1.x = tri.pt[0].x-tri.pt[1].x;
	vector1.y = tri.pt[0].y-tri.pt[1].y;
	point_t vector2;
	vector2.x = tri.pt[1].x-tri.pt[2].x;
	vector2.y = tri.pt[1].y-tri.pt[2].y;
	point_t vector3; 
	vector3.x = tri.pt[0].x-tri.pt[2].x;
	vector3.y = tri.pt[0].y-tri.pt[2].y;
	if(vector1.x*vector2.x+vector1.y*vector2.y == 0)
		return true;
	if(vector1.x*vector3.x+vector1.y*vector3.y == 0)
		return true;
	if(vector2.x*vector3.x+vector2.y*vector3.y == 0)
		return true;
	return false;
}

bool identical(triangle_t t1,triangle_t t2)
{
	if(!isdegenerate(t1) || !isdegenerate(t2))
		return false;
	int count = 0;
	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			if(points_equal(t1.pt[i],t2.pt[j]))
				count++;
		}
	}
	if(count == 3)
		return true;
	return false;	
}


bool congruent(triangle_t t1,triangle_t t2)
{
	if(!isdegenerate(t1) || !isdegenerate(t2))
		return false;
	point_t vector1; 
	vector1.x = abs(t1.pt[0].x-t1.pt[1].x);
	vector1.y = abs(t1.pt[0].y-t1.pt[1].y);
	point_t vector2;
	vector2.x = abs(t1.pt[1].x-t1.pt[2].x);
	vector2.y = abs(t1.pt[1].y-t1.pt[2].y);
	point_t vector3;
	vector3.x = abs(t1.pt[0].x-t1.pt[2].x);
	vector3.y = abs(t1.pt[0].y-t1.pt[2].y);
	point_t vector4; 
	vector4.x = abs(t2.pt[0].x-t2.pt[1].x);
	vector4.y = abs(t2.pt[0].y-t2.pt[1].y);
	point_t vector5;
	vector5.x =abs(t2.pt[1].x-t2.pt[2].x);
	vector5.y =abs(t2.pt[1].y-t2.pt[2].y);
	point_t vector6;
	vector6.x = abs(t2.pt[0].x-t2.pt[2].x);
	vector6.y = abs(t2.pt[0].y-t2.pt[2].y);

	if(points_equal(vector1,vector4) && points_equal(vector2,vector5) && points_equal(vector3,vector6))
		return true;
	if(points_equal(vector2,vector4) && points_equal(vector1,vector5) && points_equal(vector3,vector6))
		return true;
	if(points_equal(vector3,vector4) && points_equal(vector1,vector5) && points_equal(vector2,vector6))
		return true;
	if(points_equal(vector1,vector4) && points_equal(vector3,vector5) && points_equal(vector2,vector6))
		return true;
	if(points_equal(vector3,vector4) && points_equal(vector2,vector5) && points_equal(vector1,vector6))
		return true;
	if(points_equal(vector2,vector4) && points_equal(vector3,vector5) && points_equal(vector1,vector6))
		return true;
	return false;
}


bool similar(triangle_t t1,triangle_t t2)
{
	if(!isdegenerate(t1) || !isdegenerate(t2))
		return false;

	float lenTri1[3];
	float lenTri2[3];
	lenTri1[0] = sqrt(pow((t1.pt[0].x-t1.pt[1].x),2)+pow((t1.pt[0].y-t1.pt[1].y),2));
	lenTri1[1] = sqrt(pow((t1.pt[1].x-t1.pt[2].x),2)+pow((t1.pt[1].y-t1.pt[2].y),2));
	lenTri1[2] = sqrt(pow((t1.pt[0].x-t1.pt[2].x),2)+pow((t1.pt[0].y-t1.pt[2].y),2));
	lenTri2[0] = sqrt(pow((t2.pt[0].x-t2.pt[1].x),2)+pow((t2.pt[0].y-t2.pt[1].y),2));
	lenTri2[1] = sqrt(pow((t2.pt[1].x-t2.pt[2].x),2)+pow((t2.pt[1].y-t2.pt[2].y),2));
	lenTri2[2] = sqrt(pow((t2.pt[0].x-t2.pt[2].x),2)+pow((t2.pt[0].y-t2.pt[2].y),2));


	if((lenTri1[0]/lenTri2[0] == lenTri1[1]/lenTri2[1]) && (lenTri1[1]/lenTri2[1] == lenTri1[2]/lenTri2[2]) && (lenTri1[0]/lenTri2[0] == lenTri1[2]/lenTri2[2]))
		return true;
	if((lenTri1[0]/lenTri2[1] == lenTri1[1]/lenTri2[2]) && (lenTri1[1]/lenTri2[2] == lenTri1[2]/lenTri2[0]) && (lenTri1[0]/lenTri2[1] == lenTri1[2]/lenTri2[0]))
		return true;
	if((lenTri1[0]/lenTri2[2] == lenTri1[1]/lenTri2[3]) && (lenTri1[1]/lenTri2[3] == lenTri1[2]/lenTri2[1]) && (lenTri1[0]/lenTri2[2] == lenTri1[2]/lenTri2[1]))
		return true;
	return false;
}


int main()
{// Make sure you understand why are there three levels of braces, rather than two in the following:
    

	/*
    triangle_t t1 = { {{0, 0}, {4, 1}, {-1, 4}} }; 
    triangle_t t2 = { {{90, 0}, {90, -4}, {87, 0}} };
    
    if(isdegenerate(t1))
    	cout << "Triangle 1 is degenerate" << endl;
	if(isdegenerate(t2))
    	cout << "Triangle 2 is degenerate" << endl;

    if(isright(t1))
    	cout << "Triangle 1 is a right triangle." << endl;
    if(isright(t2))
    	cout << "Triangle 2 is a right triangle." << endl;
	*/


	triangle_t t3 =  { {{0, 0}, {4, 0}, {0, 4}} }; 
	triangle_t t4 =  { {{0, 0}, {8, 0}, {0, 8}} }; 

	if(identical(t3,t4))
		cout << "identical" << endl;
	if(congruent(t3,t4))
		cout << "congruent" << endl;
	if(similar(t3,t4))
		cout << "similar" << endl;
    return 0;
}