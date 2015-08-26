/* 
 * File:   ref_counter.h
 * Author: austin
 *
 * Created on August 24, 2015, 10:50 AM
 */

#ifndef REF_COUNTER_H
#define	REF_COUNTER_H

class ref_counter {
private:
    unsigned count;
public:

    ref_counter() : count(0) {
    }

    ref_counter(unsigned c) : count(c) {
    }

    void increment() {
        count++;
    }

    void decrement() {
        count--;
    }

    bool is_zero() {
        return count == 0;
    }

    unsigned get_count() {
        return count;
    }
};
#endif	/* REF_COUNTER_H */

