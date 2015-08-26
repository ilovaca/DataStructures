/* 
 * File:   heap.h
 * Author: austin
 *
 * Created on August 4, 2015, 5:51 PM
 */

#ifndef HEAP_H
#define	HEAP_H
#include "node.h"
#include <iostream>

template <typename T>
class heap {
public:
    heap();
    heap(const heap & other);
    heap(const std::vector<T>& li);
    ~heap();
    T& top();
    void pop();
    void push(const T& t);
    void pop2();
private:
    node<T>* root;
    node<T>* last_level_right_most_node;

    /**
     * Function to reorder the elements in a tree to maintain the heap property
     * Algorithm Description:
     */
    void reorder(node<T>* np) {
        // if this node is null or it has no children(meaning we have come to the single node level), then we return
        if (np == nullptr || (!np->has_left() && !np->has_right())) return;
        if (np->has_left()) {
            reorder(np->get_left());
        }
        if (np->has_right()) {
            reorder(np->get_right());
        }
        if (np->has_left() && np->has_right()) {
            auto left_child = np->get_left()->get_val();
            auto right_child = np->get_right()->get_val();
            if (left_child > right_child && np->get_val() < left_child) {
                std::swap(np->get_val(), np->get_left()->get_val());
            }
            else if (right_child >= left_child && np->get_val() < right_child) {
                std::swap(np->get_val(), np->get_right()->get_val());
            }
        } else if (np->has_left() && !np->has_right()) {
            if (np->get_val() < np->get_left()->get_val()) std::swap(np->get_val(), np->get_left()->get_val());
        } else if (!np->has_left() && np->has_right()) {
            if (np->get_val() > np->get_right()->get_val()) std::swap(np->get_val(), np->get_right()->get_val());
        }

    }

    void insert(node<T>* p, const T& t) {
        if (p == nullptr) {
            p = new node<T>(t);
            return;
        } else if (p->has_left()) {
            insert(p->get_left(), t);
        } else if (p->has_right()) {
            insert(p->get_right(), t);
        }
    }

    /**
     * Randomly creates a complete binary tree, as a helper for constructing 
     * a heap from a list
     * @param il
     */
    void construct_tree(const std::vector<T> & il) {
        for (auto iter = il.begin(); iter != il.end(); iter++) {
            insert(root, *iter);
        }
    }

    void push_helper(const T& t, node<T>* node_p, node<T>* parent) {
        if (node_p == nullptr) {
            return;
        } else {
            if (node_p->get_val() >= t) {
                // the value is smaller than this node, so we see if there is any
                // space left in this node's children
                if (!node_p->has_left()) {
                    // this node has no left child, so we insert to its left
                    node_p->set_left(new node<T>(t));
                } else if (!node_p->has_right()) {
                    // this node has no right child
                    node_p->set_right(new node<T>(t));
                } else {
                    // this node has two children, so we have to look at its children
                    // to find a place to insert. Question: which children??
                    // left and right shouldn't matter I guess
                    // Followup: it's called a complete binary heap
                    push_helper(t, node_p->get_left(), node_p);
                }
            } else {
                // the value is greater than this node, so we need to make it as the 
                // parent of this node
                // approach: two cases, if the value is greater than the root, then 
                // we make this node as root
                if (parent == nullptr) {
                    // a node that does not have a parent means it's the root
                    root = new node<T>(t, root);
                } else {
                    // this is a regular node. need to do 2 things: first check if 
                    // this node is left or right node 
                    if (parent->get_left() == node_p) {
                        parent->set_left(new node<T>(t, node_p));

                    } else {
                        parent->set_right(new node<T>(t, node_p));
                    }
                }
            }
        }
    }
};


#endif	/* HEAP_H */

template <typename T>
heap<T>::heap() : root(nullptr), last_level_right_most_node(nullptr) {
}

template <typename T>
heap<T>::heap(const heap& other) : root(other.root) {
}

template <typename T>
heap<T>::~heap() {
    delete root;
}

template <typename T>
void heap<T>::push(const T& t) {
    if (root == nullptr) {
        root = new node<T>(t);
    } else {
        push_helper(t, root, nullptr);
    }
}

/**
 * Function to merge two trees into one, returns a pointer to the root of the tree
 * @param branch1, pointer to the root of a branch
 * @param branch2, same as above
 * @return node<T>*, pointer to the root 
 */
template <typename T>
node<T>* merge_two_trees(node<T>* tree1, node<T>* tree2) {
    /*
     Algorithm description: 
     * 1. flatten two trees into a sorted list
     * 2. 
     */

}

/**
 * pops the top element from the heap
 * Lessons Learned: Just like what i did in the binary tree assignment for ECE244 lab,
 * I was always thinking about really deleting some element and move an element to its
 * proper position. This is DUMB, remember one can always do SWAP! 
 */
template <typename T>
void heap<T>::pop() {
    if (root == nullptr) {
        return;
    } else {
        // to delete the root, we need to "null" it
        auto left_branch = root->get_left();
        auto right_branch = root->get_right();
        root->set_left(nullptr);
        root->set_right(nullptr);
        // get rid of the root
        delete root;
        // now the hard part: how to merge the smaller branch to the root branch
        // so the question becomes--> merge two trees
        root = merge_two_trees(left_branch, right_branch);
    }
}

template <typename T>
T& heap<T>::top() {
    return root->get_val();
}

/**
 * Function that pops the top element in a tree. 
 * Note this is a different implementation as the pop().
 * This function uses a swap algorithm: 
 * 
 */
template <typename T>
void heap<T>::pop2() {

}

template<typename T>
void print_heap(node<T>* root) {
    if (root == nullptr) {
        return;
    } else {
        std::cout << root->get_val() << std::endl;
        if (root->has_left()) print_heap(root->get_left());
        if (root->has_right()) print_heap(root->get_right());
    }
}

template <typename T>
heap<T>::heap(const std::vector<T>& li) : root(nullptr) {
    construct_tree(li);
    reorder(root);
}