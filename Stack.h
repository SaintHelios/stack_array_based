#pragma once

class Empty_Stack {};

template <typename T>
class stack
{
private:
	T* arr;
	int top;
	size_t size;
public:
	stack();
	stack(size_t s);
	bool is_empty() { return top == -1; };
	void push(T t);
	T pop();
	~stack();
};

template<typename T> stack<T>::stack() {
	size = 5;
	arr = new T[size];
	top = -1;
}
template<typename T> stack<T>::stack(size_t s) {
	size = s;
	arr = new T[size];
	top = -1;
}
template<typename T> void stack<T>::push(T t) {
	if (top == size - 1) {
		size *= 2;
		T* copy_to = new T[size];
		for (size_t i = 0; i < size; ++i) {
			copy_to[i] = arr[i];
		}
		delete[] arr;
		arr = copy_to;
		copy_to = nullptr;
	}
	else {
		arr[top + 1] = t;
		top++;
	}
}
template<typename T> T stack<T>::pop() {
	if (!is_empty()) {
		return arr[top--];
	}
	else {
		throw Empty_Stack();
	}
}

template<typename T> stack<T>::~stack() {
	delete[] arr;
}