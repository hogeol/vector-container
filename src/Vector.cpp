#include "Vector.hpp"
#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

namespace myvector {
	void Vector::Add(const int& add_number, const int& location)
	{
		mksize++;
		try {
			if (location > mksize)
				throw location;
			if (mksize == 1) {
				mbase_array = new int[mksize];
				mbase_array[mksize - 1] = add_number;
			}
			else {
				int* tmp = new int[mksize];
				for (int size_iter = 0; size_iter < (location - 1); size_iter++) {
					tmp[size_iter] = mbase_array[size_iter];
				}
				tmp[location - 1] = add_number;
				for (int size_iter = location; size_iter < mksize; size_iter++) {
					tmp[size_iter] = mbase_array[size_iter - 1];
				}
				delete[] mbase_array;
				mbase_array = nullptr;
				mbase_array = new int[mksize];
				for (int size_iter = 0; size_iter < mksize; size_iter++) {
					mbase_array[size_iter] = tmp[size_iter];
				}
				delete[] tmp;
			}
		}
		catch (int expn) {
			mksize--;
			cerr << "Error! your input location is bigger than vector's size\n";
		}
	}

	void Vector::Add(const int& add_number)
	{
		mksize++;
		if (mksize == 1) {
			mbase_array = new int[mksize];
			mbase_array[mksize - 1] = add_number;
		}
		else {
			auto tmp = make_unique<int[]>(mksize);
			for (int size_iter = 0; size_iter < mksize - 1; size_iter++)
			{
				tmp[size_iter] = mbase_array[size_iter];
			}
			tmp[mksize - 1] = add_number;
			delete[] mbase_array;
			mbase_array = nullptr;
			mbase_array = new int[mksize];
			for (int size_iter = 0; size_iter < mksize - 1; size_iter++)
			{
				mbase_array[size_iter] = tmp[size_iter];
			}
		}
	}

	void Vector::Delete(const int& location)
	{
		try {
			if (location > mksize) {
				throw location;
			}
			if (mksize == 1) {
				delete[] mbase_array;
				mksize--;
			}
			else {
				int* tmp = new int[mksize - 1];
				int tmp_size{};
				for (int size_iter = 0; size_iter < mksize; size_iter++)
				{
					if ((size_iter + 1) == location)
						continue;
					tmp[tmp_size++] = mbase_array[size_iter];
				}
				mksize--;
				delete[] mbase_array;
				mbase_array = nullptr;
				mbase_array = new int[mksize];
				for (int size_iter = 0; size_iter < mksize; size_iter++)
				{
					mbase_array[size_iter] = tmp[size_iter];
				}
				delete[] tmp;
			}
		}
		catch (int expn) {
			cerr << "Error! The vector container size is smaller than your input location\n";
		}
	}

	void Vector::Ascending_Sort()
	{
		if (mksize == 0) {
			cerr << "It's nothing in vector container!!\n";
		}
		else if (mksize == 1) {
			cout << "There are only one number in the container!!\n";
		}
		if (mksize > 1) {
			for (int base_location = 0; base_location < mksize - 1; base_location++)
			{
				for (int compare_iter = base_location + 1; compare_iter < mksize; compare_iter++)
				{
					if (mbase_array[base_location] > mbase_array[compare_iter]) {
						Swap(mbase_array[base_location], mbase_array[compare_iter]);
					}
				}
			}
		}
	}

	void Vector::Swap(int& number1, int& number2) {
		int tmp = number1;
		number1 = number2;
		number2 = tmp;
	}

	void Vector::Display()
	{
		cout << "values: ";
		if (mksize > 0) {
			for (int array_size_iter = 0; array_size_iter < mksize; array_size_iter++) {
				cout << mbase_array[array_size_iter] << " ";
			}
		}
		else {
			cout << "It's nothing in vector container!!";
		}
		cout << endl;
	}

	void Vector::WriteToFile()
	{
		if (mksize > 0) {
			ofstream fout("out.txt");
			for (int container_iter = 0; container_iter < mksize; container_iter++)
			{
				fout << mbase_array[container_iter] << " ";
			}
			fout.close();
		}
		else {
			cout << "It's nothing in vector container!!";
		}
	}

	int Vector::GetContainerSize()
	{
		return mksize;
	}
}

