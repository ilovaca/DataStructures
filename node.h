/* 
 * File:   node.h
 * Author: austin
 *
 * Created on August 4, 2015, 6:25 PM
 */

#ifndef NODE_H
#define	NODE_H

template<typename T>
class node {
public:

    node() : left(nullptr), right(nullptr) {
    }

    node(const T& t, node<T>* lft = nullptr, node<T>* rht = nullptr) : val(t), left(lft), right(rht) {
    }

    ~node() {
        delete left;
        left = nullptr;
        delete right;
        right = nullptr;
    }

    bool has_left() {
        return left != nullptr;
    }

    bool has_right() {
        return right != nullptr;
    }

    T& get_val() {
        return val;
    }

    void set_left(node* p) {
        left = p;
    }

    void set_right(node *p) {
        right = p;
    }

    node * get_left() {
        return left;
    }

    node * get_right() {
        return right;
    }
    
    void insert_left(node<T> * lft){
        if(has_left()) return;
        left = lft;
    }
    void insert_right(node<T>* rht){
        
    }
    

private:
    T val;
    node<T> * left;
    node<T> * right;
};


#endif	/* NODE_H */

