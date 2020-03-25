class Vector2{
	private:
		double x;
		double y;
	public:
		Vector2 operator+(const Vector2 b)
		{
			Vector2 a;
			a.x = this->length + b->length;
			a.x = this->length + b->length;
			return a;
		}
};