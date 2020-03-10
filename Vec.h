// Vec.h
// A minimal 1D array class to demonstrate memory management.

class Vec {
public:
	Vec();
	Vec(int);
	~Vec();
	Vec(const Vec&);
	Vec& operator=(const Vec&);
	double& operator[](int);
	void push_back(const double&);
	void grow();
	int get_current_size() { return array_current_size; }
	int get_limit() { return array_limit; }
	double get_pointer(){return *pointer_to_data; }
private:
	int array_current_size;
	int array_limit;
	double* pointer_to_data;
};
