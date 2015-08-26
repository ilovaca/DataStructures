/* 
 * File:   stack_array_impl.h
 * Author: austin
 *
 * Created on August 16, 2015, 9:09 PM
 */

#ifndef STACK_ARRAY_IMPL_H
#define	STACK_ARRAY_IMPL_H
#include "stack_interface.h"
#include <iostream>
#include "empty_container.h"

template<typename T>
class stack_array_impl : public stack_interface {
private:
    T* array;
    size_t size;
    size_t capacity;
    void reallocate();
public:

    stack_array_impl() : size(1000), capacity(2000), array(new T[size]) {
        std::cout << "stack created with initial size: " << size << std::endl;
    }

    ~stack_array_impl() {
        delete [] array;
    }

    void pop() {
        size--;
    }

    T& top() {
        if (size == 0) throw empty_container("empty stack");
        return array[size - 1];
    }

    void push(const T& t) {
        reallocate();
        array[size] = t;
        size++;
    }

    size_t size() {
        return size;
    }
    bool empty(){
        return size > 0;
    }
};

template<typename T>
void stack_array_impl<T>::reallocate() {
    if (size >= capacity) {
        auto temp = new T[capacity *= 2];
        std::copy(&array[0], &array[size - 1], temp);
        delete[] array;
        array = temp;
    }
}

#endif	/* STACK_ARRAY_IMPL_H */

