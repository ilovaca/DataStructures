/* 
 * File:   Node.h
 * Author: austin
 *
 * Created on August 14, 2015, 9:27 AM
 */

#ifndef NODE_H
#define	NODE_H

template <typename T>
class Node {
private:
    T value;
    Node* next;
public:
    Node() = default;

    Node(const T& val, Node* node = nullptr) : value(val), next(node) {
    }

    ~Node() {
        delete next;
        next = nullptr;
    }

    void set_next(Node* node) {
        next = node;
    }
    // get the next node

    Node* get_next() {
        return next;
    }

    T& get_value() {
        return value;
    }

};


#endif	/* NODE_H */

