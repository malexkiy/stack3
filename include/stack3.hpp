#ifndef _STACK_H_
#define _STACK_H_

#include <algorithm>
#include <utility>

template <typename T>
class stack {
private:
	void swap(stack<T>& first, stack<T>& second);

public:
	stack();
	~stack();
	stack(stack<T> const&);
	stack<T>& operator=(stack<T> const&);

	size_t count() const;
	void push(T const &);
	T pop();
	T top();
	bool empty();

	friend void stack_last(stack<int>* _stack);

	friend void stack_print(stack<int>* _stack);

private:
	T * array_;
	size_t array_size_;
	size_t count_;
};


template <typename T>
stack<T>::stack()
{
	count_ = 0;
	array_size_ = 0;
	array_ = new T[array_size_];
}


template <typename T>
stack<T>::~stack()
{
	count_ = 0;
	array_size_ = 0;
	delete[] array_;
}


template <typename T>
void stack<T>::swap(stack<T>& first, stack<T>& second)
{
	std::swap(first.count_, second.count_);
	std::swap(first.array_size_, second.array_size_);
	std::swap(first.array_, second.array_);
}


template <typename T>
stack<T>::stack(stack<T> const& other)
{
	count_ = other.count_;
	array_size_ = other.array_size_;
	array_ = new T[array_size_];

	std::copy(other.array_, other.array_ + count_, array_);
}


template <typename T>
stack<T>& stack<T>::operator=(stack<T> const& other)
{
	if (this != &other)
	{
		stack<T> tmp(other);
		swap(*this, tmp);
	}

	return *this;
}


template <typename T>
size_t stack<T>::count() const
{
	return count_;
}


template <typename T>
void stack<T>::push(T const& obj)
{
	if (array_size_ == 0)
	{
		delete[] array_;
		array_size_ = 1;
		array_ = new T[array_size_]();
	}
	else if (count_ + 1 >= array_size_)
	{
		array_size_ *= 2;
		T* narray = new T[array_size_]();
		std::copy(array_, array_ + count_, narray);

		delete[] array_;
		array_ = narray;
	}
	array_[count_++] = obj;
}


template <typename T>
T stack<T>::pop()
{
	if (count_ == 0)
		throw "Stack is empty!";

	count_--;
	T obj = array_[count_];

	return obj;
}


#endif
