#ifndef _POLY_
#define _Poly_
using namespace std;

class Poly{
	public:
		Poly();
		~Poly();

		void add_term(float,int);
		float eval(float);

		bool eq_deg(int);

};	
#endif