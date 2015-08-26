/* 
 * File:   stack.h
 * Author: austin
 *
 * Created on August 16, 2015, 9:01 PM
 */

#ifndef STACK_H
#define	STACK_H

template <typename T>
class stack_interface {
public:
    virtual void pop() = 0;
    virtual void push(const T& t) = 0;
    virtual T& top() = 0;
    virtual size_t size() = 0;
};



#endif	/* STACK_H */

