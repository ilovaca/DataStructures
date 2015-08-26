/* 
 * File:   graph_node.h
 * Author: austin
 *
 * Created on August 19, 2015, 5:44 PM
 */

#ifndef GRAPH_NODE_H
#define	GRAPH_NODE_H
#include <vector>

template<typename T>
class graph_node {
private:
    std::vector<unsigned> neighbor_nodes;
    unsigned node_ID;
    T data;
public:
    graph_node() = delete;

    graph_node(const T& data, unsigned node_ID)
    : data(data), node_ID(node_ID), neighbor_nodes(0) {
    }

    std::vector<unsigned> get_neighbors() {
        return neighbor_nodes;
    }

    unsigned get_nodeID() {
        return node_ID;
    }

    void add_neighbors(const std::vector<unsigned> & neighbors) {
        neighbor_nodes.insert(neighbor_nodes.end(), neighbors.begin(), neighbors.end());
    }

    void add_neighbor(unsigned id) {
        neighbor_nodes.push_back(id);
    }
};


#endif	/* GRAPH_NODE_H */

