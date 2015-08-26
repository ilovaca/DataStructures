/* 
 * File:   graph.h
 * Author: austin
 *
 * Created on August 19, 2015, 5:39 PM
 */

#ifndef GRAPH_H
#define	GRAPH_H
#include "graph_node.h"
#include <stack>
#include <queue>

template<typename T>
class graph {
private:
    std::vector<graph_node<T>> nodes;
public:
    graph() = default;
    //    void construct_graph();
    void add_node(const T& data);
    void add_edge(unsigned from, unsigned to, bool is_one_way);

    unsigned get_size() {
        return nodes.size();
    }

    graph_node<T>& get_node(unsigned id) {
        return nodes[id];
    }

    std::vector<unsigned> DFS_iterative_sol(unsigned from, unsigned to);
    bool BFS(unsigned start, unsigned destination);
};
#endif	/* GRAPH_H */

template <typename T>
void graph<T>::add_node(const T& data) {
    nodes.push_back(graph_node<T>(data, nodes.size()));
}

template<typename T>
void graph<T>::add_edge(unsigned from, unsigned to, bool is_one_way) {
    if (is_one_way) {
        nodes[from].add_neighbor(to);
    } else {
        nodes[from].add_neighbor(to);
        nodes[to].add_neighbor(from);
    }
}

template<typename T>
std::vector<graph_node<T>> DFS_recursive_sol(graph<T> g, unsigned start, unsigned destination) {
    std::vector<graph_node < T>> route;
    std::vector<bool> visited(g.get_size(), false);
    bool found = DFS_recursive_helper(g, route, visited, start, destination);
    return route;
}

template <typename T>
bool DFS_recursive_helper(graph<T> g, std::vector<graph_node<T>> &route,
        std::vector<bool>& visited, unsigned current, unsigned destination) {

    if (g.get_node(current).get_neighbors().empty()) return false; // we've reached a dead end! meaning this route does not work
    if (current == destination) {
        route.push_back(g.get_node(current));
        return true; // or if we've reached the intended place
    }
    // mark we have visited this node
    visited[current] = true;
    // continue to its neighbors
    auto neighbors = g.get_node(current).get_neighbors();
    // for each unvisited neighbor, we recursively call it on    
    for (auto& n : neighbors) {
        if (!visited[n]) {
            route.push_back(g.get_node(current));
            return DFS_recursive_helper(g, route, visited, n, destination);
        }
    }
    return false;
}

template<typename T>
std::vector<unsigned> graph<T>::DFS_iterative_sol(unsigned from, unsigned to) {
    std::stack<unsigned> node_stack;
    std::vector<unsigned> route;
    node_stack.push(from);
    std::vector<bool> visited(nodes.size(), false);
    while (!node_stack.empty()) {
        auto top = node_stack.top();
        if (!visited[top]) {
            route.push_back(top);
            visited[top] = true;
            if (top == to) {
                return route;
            } else {
                auto neighbors = nodes[top].get_neighbors();
                for (auto & n : neighbors) {
                    node_stack.push(n);
                }
            }
        }
    }
    return std::vector<unsigned>();
}

template<typename T>
bool graph<T>::BFS(unsigned start, unsigned destination) {
    std::vector<bool> visited(nodes.size(), false);
    std::queue<unsigned> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        unsigned current = q.front();
        q.pop();
        if (current == destination) return true;
        else {
            auto neighbors = nodes[current].get_neighbors();
            for (auto & n : neighbors) {
                if (!visited[n]) q.push(n);
                visited[n] = true;
            }
        }
    }
}