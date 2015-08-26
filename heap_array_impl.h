/* 
 * File:   heap_array_impl.h
 * Author: austin
 *
 * Created on August 6, 2015, 8:56 PM
 */

#ifndef HEAP_ARRAY_IMPL_H
#define	HEAP_ARRAY_IMPL_H
#include <iostream>
#include <vector>
#include <limits>
#include <math.h>
const unsigned NOT_A_CHILD = std::numeric_limits<unsigned>::max();

template <typename T>
class heap_array_impl {
public:
    heap_array_impl() = default;
    heap_array_impl(const heap_array_impl& orig) = default;
    virtual ~heap_array_impl() = default;

    void push(const T& t) {
        if (vec.size() == 0) {
            vec.push_back(t);
        } else {
            vec.push_back(t);
            auto new_node = vec.size() - 1;
            sift_up(new_node);
        }
    }

    T& top() {
        return vec[0];
    }

    void sift_down(unsigned node) {
        
        auto children = get_children(node);

        if(children.first >= vec.size() || children.second >= vec.size()) return;
        auto larger_child = vec[children.first] >= vec[children.second] ? children.first : children.second;

        if (vec[node] < vec[larger_child]) {
            std::swap(vec[larger_child], vec[node]);
            sift_down(larger_child);
        }
    }

    void pop() {
        if (vec.size() == 0) {
            return;
        } else {
            // first, swap the end element with the top 
            std::swap(vec[vec.size() - 1], vec[0]);
            // then get rid of the end 
            vec.pop_back();
            //Now we sift the top down to its appropriate position
            sift_down(0);
        }
    }

    void print() {
        if (vec.size() == 0) return;
        for (int i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << "   ";
//            if (i)
            }
    }

private:
    std::vector<T> vec;

    /**
     * given a node index, returns its two children
     * Note: if no children exists, the index will be denoted as NOT_A_CHILD
     * @param index
     * @return an std::pair<unsigned, unsigned> of its two children
     */
    std::pair<unsigned, unsigned> get_children(unsigned index) {

        return std::pair<unsigned, unsigned>(2 * index + 1 < vec.size() ? 2 * index + 1 : NOT_A_CHILD,
                2 * index + 2 < vec.size() ? 2 * index + 2 : NOT_A_CHILD);
    }

    /**
     * returns the parent of a given node, return -1 for root's parent
     * @param index
     * @return 
     */
    int get_parent(unsigned index) {
        if (index == 0) return -1;
        else return floor((index - 1) / 2);
    }

    void sift_up(std::size_t new_node) {
        auto parent = get_parent(new_node);
        if (vec[parent] >= vec[new_node] || parent == -1) return; // new node is already in the proper pos
        else {
            // need to swap this shit with its parent
            std::swap(vec[parent], vec[new_node]);
            // recurse on the parent again
            sift_up(parent);
        }
    }
};

#endif	/* HEAP_ARRAY_IMPL_H */

