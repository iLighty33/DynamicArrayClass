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
		size_ = this->size_;
		int* tmp = new int[size_];
		for (int i = 0; i < size_; i++) {
			tmp[i] = data_[i];
		}
		delete[] data_;
		this->capacity_ = size_ + newCapacity;
		this->size_ = this->capacity_;
		data_ = new int[capacity_] {};
		for (int i = 0; i < capacity_ - newCapacity; i++) {
			data_[i] = tmp[i];
		}
		delete[] tmp;
		
	}
	
	// M. Capacity
	int capacity() const {
		if (capacity_ == size_)
			;
	}

	// N. Shrink_to_fit
	void shrinkToFit() {
		int* tmp = new int[size_];

		for (int i = 0; i < size_; i++) {
			tmp[i] = data_[i];
		}
		capacity_ = size_;
		delete[]data_;
		data_ = new int[capacity_];
		for (int i = 0; i < capacity_; i++) {
			data_[i] = tmp[i];
		}
		delete[] tmp;
	}

	// O. Clear
	void clear() {
		delete[] data_;
		size_ = 0;
	}

	// P. Insert
	void insert(int index, int value, int count) {
		if (capacity_ < size_ + count)
			this->reserve(count);
		size_ += count;
		int* tmp = new int[size_];
		for (int i = 0; i < index; i++) {
			tmp[i] = data_[i];
		}
		for (int i = index; i < index + count; i++) {
			tmp[i] = value;
		}
		for (int i = index + count; i < size_; i++) {
			tmp[i] = data_[i];
		}
		delete[]data_;
		data_ = new int[capacity_];
		for (int i = 0; i < size_; i++) {
			data_[i] = tmp[i];
		}
		delete[]tmp;
	}

	// Q. Erase
	void erase(int begin, int end) {
		int count = 0;
		int* tmp = new int[size_];
		for (int i = 0; i < size_; i++) {
			tmp[i] = data_[i];
		}
		delete[]data_;
		data_ = new int[size_ - (end - begin)];
		for (int i = 0; i < size_; i++) {
			if (i >= begin && i <= end) {
				count++;
				continue;
			}
			data_[i - count] = tmp[i];
		}
		size_ -= (end - begin + 1);
	}
	
	// R. Push_back
	void pushBack(int value) {
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
	void popBack() {
		int* tmp = new int[size_];
		for (int i = 0; i < size_; i++) {
			tmp[i] = data_[i];
		}
		delete[]data_;
		size_ -= 1;
		data_ = new int[size_] {};
		for (int i = 0; i < size_; i++) {
			data_[i] = tmp[i];
	}

	// U. Resize
	void resize(int newSize) {
		if (newSize > capacity_)
			this->reverse(newSize - capacity_);
		else
		{
			int* tmp = new int[size];
			for (int i = 0; i < size_; i++) {
				tmp[i] = data_[i];
			}
			delete[]data_;
			capacity_ = newSize;
			data_ = new int[capacity_];
			if (size_ > capacity_)
				size_ = capacity_;
			for (int i = 0; i < size; i++) {
				data_[i] = tmp[i];
			}
		}
	}

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

class iterator {
public:
	int* operator->()const;
	int* operator->()const {
		return place_;
	}

	int& operator*()const;
	int& operator*()const {
		return *place_;
	};

	operator int* ()const;
	operator int* ()const {
		return place_;
	}

	iterator& operator+(int i)const;
	iterator& operator+(int i)const {
		iterator result(*this);
		result.place_ += i;
		return result;
	}

	iterator& operator+=(int i);
	iterator& operator+=(int i) {
		place_ += i;
		return *this;
	}

	iterator& operator-(int i)const;
	iterator& operator-(int i)const {
		iterator result(*this);
		result.place_ -= i;
		return result;
	}

	iterator& operator-=(int i);
	iterator& operator-=(int i) {
		place_ -= i;
		return *this;
	}

	iterator& operator--();
	iterator& operator--() {
		place_ -= 1;
		return *this;
	}

	iterator& operator--(int);
	iterator& operator--(int) {
		iterator tmp{ *this };
		place_ -= 1;
		return tmp;
	}

	iterator& operator++();
	iterator& operator++() {
		place_ += 1;
		return *this;
	}

	iterator& operator++(int);
	iterator& operator++(int) {
		iterator tmp{ *this };
		place_ += 1;
		return tmp;
	}

	operator bool()const;
	operator bool()const {
		return static_cast<bool>(place_);
	}

	bool operator==(const iterator&& other)const;
	bool operator==(const iterator&& other)const {
		return place_ == other.place_;
	}

	bool operator!=(const iterator&& other)const;
	bool operator!=(const iterator&& other)const {
		return place_ != other.place_;
	}

	bool operator<(const iterator&& other)const;
	bool operator<(const iterator&& other)const {
		return place_ < other.place_;
	}

	bool operator<=(const iterator&& other)const;
	bool operator<=(const iterator&& other)const {
		return place_ <= other.place_;
	}

	bool operator>(const iterator&& other)const;
	bool operator>(const iterator&& other)const {
		return place_ > other.place_;
	}

	bool operator>=(const iterator&& other)const;
	bool operator>=(const iterator&& other)const {
		return place_ >= other.place_;
	}

	int& operator[](int i)const;
	const DynamicArray const* from()const {
		return &collection_;
	}
	int& operator[](int i)const {
		return place_[i];
	}


private:
	iterator() = delete;
	iterator(const DynamicArray&& position, int* place) :collection_(position), place_(place) {}
	friend class MyDinArr;
	const DynamicArray& collection_;
	int* place_;
	int size_{ 0 };
	int capacity_{ 0 };
	int* data_ = nullptr;
};

int main() {



	return 0;
}