#include <iostream>
#include <string>
#include <sstream>
#include "Vec.h"
using namespace std;

int main()
{
	Vec v;



	cout << "array_current_size = " << v.get_current_size()
			<< ", " << "array_limit = " << v.get_limit() << endl;
/*
	cout << "array_current_size = " << v.get_current_size()
			<< ", " << "array_limit = " << v.get_limit() << ", " << "pointer_to_data = " << v.get_pointer() << endl;


	cout << "Current size: "<< v.get_current_size() << endl;


*/

	double input;
	string line;

	while(1) {
		cout << "Enter some doubles to store in Vec (then Return; or Ctr-C to exit): ";

		getline(cin, line);
		istringstream iss(line);
		while (iss >> input) {
			v.push_back(input);
		}
		cin.clear();
		cout << "array_current_size = " << v.get_current_size()
				<< ", " << "array_limit = " << v.get_limit() <<endl;

		cout << "Output: " << endl;
		for (int i = 0; i != v.get_current_size(); ++i) {
			cout << "v[" << i << "] = " << v[i] << endl;
		}
	}

	return 0;
}
