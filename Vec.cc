// Vec.cc
#include "Vec.h"
#include <algorithm>
#include <iostream>
using namespace std;

Vec::Vec()
{
	array_current_size = array_limit = 0;
	pointer_to_data = 0;
}

// Constructor
Vec::Vec(int a)
{
	array_current_size = 0;
	array_limit = a;

	// Allocate new memory for array.
	pointer_to_data = new double[array_limit];

}
// Overloading the copy constructor.
Vec::Vec(const Vec& vec_to_copy)
{
	array_current_size = vec_to_copy.array_current_size;
	array_limit = vec_to_copy.array_limit;

	// Allocate new memory for array.
	pointer_to_data = new double[array_limit];

	// Copy data across.
	for (int i = 0; i != array_current_size; ++i) {
		pointer_to_data[i] = vec_to_copy.pointer_to_data[i];
	}
}
// Destructor
Vec::~Vec()
{
	// Free array memory
	delete[] pointer_to_data;
	// Set pointer to null
	pointer_to_data = 0;
	array_current_size = array_limit = 0;
}
// Overloading the assignment operator.
Vec& Vec::operator=(const Vec& rhs)
{
	// Check for self-assignment.
	if (&rhs != this) {
		// Free lhs array memory.
		delete[] pointer_to_data;

		// Allocate new memory for lhs array.
		array_current_size = rhs.array_current_size;
		array_limit = rhs.array_limit;
		pointer_to_data = new double[array_limit];

		// Copy rhs data across.
		for (int i = 0; i != array_current_size; ++i) {
			pointer_to_data[i] = rhs.pointer_to_data[i];
		}
	}

	return *this;
}
// Overloading the index operator
double& Vec::operator[](int i)
{
	return pointer_to_data[i];
}


//===================== New Member Functions =================

void Vec::push_back(const double& value){


	//Call the grow function if there is not enough space
	if (array_current_size==array_limit){
		cout << "executing grow" <<endl;
		this->grow();
		cout << "grow executed" <<endl;
		cout << pointer_to_data <<endl;
		cout << array_limit <<endl;





	}
	//Push the input to the last element of the vector
	pointer_to_data[array_current_size]=value;

	//Keep track of the size of vector
	array_current_size+=1;

}


void Vec::grow(){
//Allocate new Array with twice the original space
	int new_limit;
	//Increase the limit of data by two-fold if greater than 0
	if(array_limit == 0){
		new_limit = (array_limit+1);
	} else {
		new_limit = (array_limit*2);
	}

	//Declare the new array with appropriate space.
	Vec* new_vec;
	new_vec = new Vec(new_limit);

	//Copy Data to new Array
	if(pointer_to_data==NULL){
		pointer_to_data = new_vec->pointer_to_data;
		new_vec->~Vec();
	} else {
	for(int i = 0; i < (new_limit);++i){
			new_vec->pointer_to_data[i] = pointer_to_data[i];
		}
		pointer_to_data = new_vec->pointer_to_data;
		new_vec->~Vec();
	}


	//Assign New Limit
	array_limit = new_limit;

}
