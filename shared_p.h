/* 
 * File:   shared_pointer.h
 * Author: austin
 *
 * Created on August 24, 2015, 10:39 AM
 */

#ifndef SHARED_POINTER_H
#define	SHARED_POINTER_H
#include "ref_counter.h"

template <typename T>
class shared_p {
private:
    T* t_ptr;
    ref_counter* counter;
public:

    shared_p(T* t_ptr) : t_ptr(t_ptr), counter(new ref_counter()) {
        counter->increment();
    }

    shared_p(const shared_p& other) : t_ptr(other.t_ptr), counter(other.counter) {
        counter->increment();
    }

    ~shared_p() {
        if (counter->get_count() == 1) { // this is the last pointer, delete!
            delete t_ptr;
            t_ptr = nullptr;
            delete counter;
            counter = nullptr;
        } else {
            // not the last pointer, do nothing!
        }
    }

    T& operator*() {
        return *t_ptr;
    }

    shared_p& operator=(const shared_p& rhs) {
        // this assignment means the original pointer gives up ownership
        if (this->counter->get_count() == 1) {

        }
        t_ptr = rhs.t_ptr;
        counter = rhs.counter;
        counter->increment();
    }


};
#endif	/* SHARED_POINTER_H */
