/* 
 * File:   main.cpp
 * Author: austin
 *
 * Created on July 30, 2015, 8:14 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
//#include "linked_list.h"
#include "graph.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    //    std::vector<int> v{10, 15, 10, 19, 9, 7, 20, 2, 12, 21};
    //    heap<int> hp(v);
    /*
    hp.push(10);
    hp.push(15);
    hp.push(10);
    hp.push(19);
    hp.push(9);
    hp.push(7);
    hp.push(20);
     */

    graph<int> my_graph;
    my_graph.add_node(1);
    my_graph.add_node(1);
    my_graph.add_node(1);
    my_graph.add_node(1);
    my_graph.add_node(1);
    my_graph.add_node(1);
    my_graph.add_node(1);
    my_graph.add_node(1);
    my_graph.add_node(1);
//    my_graph.add_edge(0, 1, true);
    my_graph.add_edge(0, 2, false);
    my_graph.add_edge(0, 3, false);
//    my_graph.add_edge(0, 4, true);
    //    my_graph.add_edge(1, 2, true);
    my_graph.add_edge(1, 3, true);
    //    my_graph.add_edge(1, 4, true);
    //    my_graph.add_edge(2, 3, false);
    my_graph.add_edge(2, 4, true);
    my_graph.add_edge(3, 4, true);
    my_graph.add_edge(5, 4, true);
    my_graph.add_edge(4, 6, true);
    my_graph.add_edge(6, 7, true);
    my_graph.add_edge(7, 8, true);
    //    std::cout<<DFS_recursive_sol(my_graph,0,5)<<std::endl;
    auto route = my_graph.DFS_iterative_sol( 0, 8);
    for (auto & node : route) {
        std::cout << node << std::endl;
    }
    return 0;
}

