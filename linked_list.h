/* 
 * File:   linked_list.h
 * Author: austin
 *
 * Created on August 14, 2015, 9:44 AM
 */
#include "Node.h"
#include <stack>

#ifndef LINKED_LIST_H
#define	LINKED_LIST_H

template<typename T>
class linked_list {
private:
    Node<T>* head;
    Node<T>* tail;
    std::size_t size;
public:

    linked_list() : head(nullptr), tail(nullptr), size(0) {
    }
    // Here I had a undefined behavior: I forgot to initialize the variables in the 
    // constructor initializer list, which led to head pointer being randomly pointed

    linked_list(std::initializer_list<T> il) : head(nullptr), tail(nullptr), size(0) {
        for (auto & val : il) {
            insert(val);
        }
    }

    ~linked_list() {
        delete head;
        tail = nullptr;
    }

    void insert(const T& value) {
        if (head == nullptr) {
            head = new Node<T>(value);
            tail = head;
        } else {
            auto new_node = new Node<T>(value);
            tail->set_next(new_node);
            tail = new_node;
        }
    }

    void print() {
        for (auto temp = head; temp != nullptr; temp = temp->get_next()) {
            std::cout << temp->get_value() << std::endl;
        }
    }

    /**
     * Lessons Learned: 
     * 1.Initializing two variables of different types is not allowed in for loop
     * 2.be fucking careful when writing while-loops, since it's too easy to forget
     *   to increment
     */
    void reverse_list() {
        if (head == nullptr) return;
        // we push the node itself and its previous node to the stack
        std::stack<std::pair < Node<T>*, Node<T>*>> node_stack;
        Node<T>* prev = nullptr;
        for (auto tmp = head; tmp != nullptr; tmp = tmp->get_next()) {
            node_stack.push(std::pair<Node<T>*, Node<T>*>(tmp, prev));
            prev = tmp;
        }

        // now popping the nodes off the stack, reconstruct the list
        head = node_stack.top().first;
        while (!node_stack.empty()) {
            auto this_node = node_stack.top().first;
            auto prev_node = node_stack.top().second;
            this_node->set_next(prev_node);
            tail = this_node;
            // WTF, forgot to pop!
            node_stack.pop();
        }
    }

    void reverse_list_recursive_solution() {
        reverse_helper_2(head, nullptr);
    }

    Node<T>* reverse_helper(Node<T>* node) {
        if (node == nullptr) return nullptr;
        else {
            auto np = reverse_helper(node->get_next());
            node->set_next(np);
            return node;
        }
    }

    void reverse_helper_2(Node<T>* node, Node<T>* prev) {
        if (node == nullptr) return;
        if (node->get_next() == nullptr) {
            // means this is the last node, which should be the head node in the 
            // reversed list
            head = node;
        }
        reverse_helper_2(node->get_next(), node);
        node->set_next(prev);
    }

};


#endif	/* LINKED_LIST_H */

