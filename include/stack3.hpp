#ifndef _STACK_H_
#define _STACK_H_

#include <algorithm>
#include <utility>

template <typename T>
class stack {
private:
	void swap(stack<T>& first, stack<T>& second) noexcept;

public:
	stack();
	~stack() noexcept;
	stack(stack<T> const&);
	stack<T>& operator=(stack<T> const&) noexcept;

	size_t count() const noexcept;
	void push(T const &);
	void pop();
	T top() const;
	bool empty() const noexcept;

	friend void stack_print(stack<int>* _stack);

private:
	T * array_;
	size_t array_size_;
	size_t count_;
};


template <typename T>
stack<T>::stack() 
	:count_(0), array_size_(0)
{
	count_ = 0;
	array_size_ = 0;
	array_ = new T[array_size_];
}


template <typename T>
stack<T>::~stack() noexcept
{
	delete[] array_;
}


template <typename T>
void stack<T>::swap(stack<T>& first, stack<T>& second) noexcept
{
	using std::swap;

	swap(first.count_, second.count_);
	swap(first.array_size_, second.array_size_);
	swap(first.array_, second.array_);
}


template <typename T>
stack<T>::stack(stack<T> const& other)
	:count_(other.count_), array_size_(other.array_size_)
{
	array_ = new T[array_size_];

	std::copy(other.array_, other.array_ + count_, array_);
}


template <typename T>
stack<T>& stack<T>::operator=(stack const& other) noexcept
{
	if (this != &other)
	{
		stack tmp(other);
		swap(*this, tmp);
	}

	return *this;
}


template <typename T>
size_t stack<T>::count() const noexcept
{
	return count_;
}


template <typename T>
bool stack<T>::empty() const noexcept
{
	return count_ == 0;
}


template <typename T>
void stack<T>::push(T const& obj) /*strong*/
{
	if (count_ == array_size_)
	{
		auto array_size = array_size_ == 0 ? 1 : array_size_ * 2;
		T* narray = new T[array_size];
		std::copy(array_, array_ + count_, narray);

		array_size_ = array_size;
		delete[] array_;
		array_ = narray;
	}

	array_[count_] = obj;
	++count_;
}


template <typename T>
T stack<T>::top() const
{
	if (count_ == 0)
	{
		throw "Stack is empty!";
	}

	return array_[count_ - 1];
}


template <typename T>
void stack<T>::pop()
{
	if (count_ == 0)
	{
		throw "Stack is empty!";
	}

	count_--;
}


#endif
