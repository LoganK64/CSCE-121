class vehicle
{
	public:
		virtual vehicle();
		string getReg();
		void setReg();
		float getFee();
		virtual printType();

	protected:
		string reg;
	private:
		float fee;
};

class trailer :: public vehicle
{
	public:
		trailer();
		trailer(string);
		printType();
};

class car :: public vehicle
{
	public:
		car();
		car(string);
		virtual printType();	
};

class electricCar :: public car
{
	public:
		electricCar();
		electricCar(string);
		printType();
};

void printTaxDetails(vehicle *v)
{
	cout << v->getReg() << " Tax for" << v->printType() << " is $" << v->getFee();
}
