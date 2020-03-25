#include <iostream> // Std. libary, gives us cout
using namespace std;
#define MAX 200 /* Largest polygon we consider has this many sides and points */
#define EPSILON 0.0001 /* Two floats are close enough for our purposes when
their values are within this distance */

struct point_t { /* Compound data structure to represent a point */
	float x, y;
};

struct poly_t { /* A data structure to represent a polygon */
	point_t verts[MAX];
	int vert_count;
};


bool points_equal(point_t a, point_t b)
{
	float first = b.x-a.x;
	float second = b.y-a.y;
	if(first < 0)
		first = -first;
	if(second < 0)
		second = -second;
	if(first <=EPSILON && second<=EPSILON)
		return true;
	return false;
}

bool two_polys_equal(poly_t a, poly_t b)
{
	if(a.vert_count != b.vert_count)
		return false;
	int count = 0;
	for(int i = 0; i < a.vert_count; i++)
	{
		for(int j = 0; j < b.vert_count;j++)
		{
			if(points_equal(a.verts[i],b.verts[j]))
			{
				cout << "this is a thing" << endl;
				count++;
			}
		}
	}
	if(count >= a.vert_count)
		return true;
	return false;
}


int main()
{
	poly_t a = {{{0,0},{4,0},{0,4},{-4,0}},4};
	poly_t b = {{{4,0},{0,0},{-4,0},{0,4}},4};
	if(two_polys_equal(a,b))
		cout << "It works";
	else
		cout << "fuck";
}