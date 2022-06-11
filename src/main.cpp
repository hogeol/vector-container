#define _CRT_SECURE_NO_WARNINGS
#include "Vector.hpp"
#include <iostream>

using namespace std;
using namespace myvector;

int main(int argc, char** argv) {
	Vector myvector;
	int input{};
	int add_number{};
	int location{};
	do {
		cout << "Menu - add(1), delete(2), sort(3), display(4), save file(5), exit(0): ";
		cin >> input;
		switch (input) {
		case 0:
			break;
		case 1:
			cout << "Value, location(smaller than " << myvector.GetContainerSize() << "): ";
			cin >> add_number >> location;
			myvector.Add(add_number, location);
			break;
		case 2:
			cout << "Location: ";
			cin >> location;
			myvector.Delete(location);
			break;
		case 3:
			myvector.Ascending_Sort();
			break;
		case 4:
			myvector.Display();
			break;
		case 5:
			myvector.WriteToFile();
			break;
		}
	} while (input);
	return 0;
}
