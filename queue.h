/* 
 * File:   queue.h
 * Author: austin
 *
 * Created on August 16, 2015, 11:13 PM
 */

#ifndef QUEUE_H
#define	QUEUE_H

template<typename T>
class queue {
private:
    T* array;
    size_t back;
    size_t front;
public:

    queue() : array(new T[1000]) {
    }
    
    ~queue(){
        delete [] array;
    }
    
    void push(const T& t) {
        array[back] = t;
        back++;
    }

    T& top() {
        return array[front];
    }

    void pop() {
        front++;
    }

};


#endif	/* QUEUE_H */

