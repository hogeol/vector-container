#ifndef _VECTOR_
#define _VECTOR_

namespace myvector {
	class Vector
	{
	private:
		int* mbase_array;
		int mksize;
	public:
		Vector() :mbase_array(nullptr), mksize(0) {}
		void Add(const int& add_number, const int& location);
		void Add(const int& add_number);
		void Delete(const int &location);
		void Ascending_Sort();
		void Display();
		void WriteToFile();
		void Swap(int& number1, int& number2);
		int GetContainerSize();
	};
}

#endif _VECTOR_

