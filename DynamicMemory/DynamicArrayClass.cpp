#include <iostream>
#include <cstddef>
#include <new>
#include <vector>

using namespace std;

class DynamicArray {
	int* numbers;
	int sizeOfArray;
public:
	
	// A.Constructor
	DynamicArray() {};
	DynamicArray(int size, int* data);
	DynamicArray(DynamicArray&& other);
	DynamicArray(const DynamicArray& other);

	// B. Destructor
	~DynamicArray();

	// C. Operator=
	DynamicArray& operator= (const DynamicArray& other);
	DynamicArray& operator= (DynamicArray&& other);

	// D. At
	int& at(int pos);
	const int& at(int pos) const;

	// E. Operator{]
	int& operator[] (int pos);
	const int& operator[] (int pos) const;

	// F. Front
	int & front () {
		return data_[0];
	}
	const int& front() const {
		return data_[0];
	}

	// G. Back
	int& back();
	const int& back() const;

	// H. Data
	int* data();
	const int* data() const;

	// I. Capacity
	int capacity() const;

	// J. Empty
	bool empty() const {
		if (size_ > 0) {
			return false;
		}
		else
			return true;
	}

	// K. Size
	int size() const {
		return size_;
	}

	// L. Reserve
	void reserve(int newCapacity) {
		if (newCapacity > capacity_)
			;
	}
	
	// M. Capacity
	int capacity() const {
		if (capacity_ == size_)
			;
	}

	// N. Shrink_to_fit
	// O. Clear
	void clear() {
		delete[] data_;
		size_ = 0;
	}

	// P. Insert
	// Q. Erase
	// R. Push_back
	void push_back(int value) {
		int* tmp = new int[size_ + 1];

		for (int i = 0; i < size_; i++) {
			tmp[i] = this->data_[i];
		}
		size_ += 1;
		for (int i = 0; i < this->size_ - 1; i++) {
			this->data_[i] = tmp[i];
		}
		data_[size_ - 1] = value;
		delete[] tmp;
	}

	// T. Pop_back
	// U. Resize
	// V. Swap
	void swap(DynamicArray& other, DynamicArray& other2) {
		DynamicArray tmp;
		tmp = other;
		other = other2;
		other2 = tmp;
	}

	// W. Swaps the contents
	


	// X. Operator==

	friend bool operator==(DynamicArray &arrInt, DynamicArray &arrInt2);
	friend bool operator==(DynamicArray & arrInt, DynamicArray &arrInt2)
	{
		if (arrInt.sizeOfArray != arrInt2.sizeOfArray) //сравниваем размеры массивов объектов
		{
			cout << "В массивах разное количество элементов\n";
			return 0;
		}
		else //проверяем равны ли данные в в ячейках массивов
		{
			for (int i = 0; i < arrInt.sizeOfArray; i++)
			{
				if (arrInt.numbers[i] != arrInt2.numbers[i])
				{
					cout << "Значения массивов не равны\n";
					return 0;
				}
			}
		}
		return 1;
	}


private:
	int* data_;
	int size_;
	int capacity_;
};

int main() {



	return 0;
}