#include <gtest/gtest.h>
#include <time.h>

#include <cstdlib>
#include <iostream>

#include "graph.h"

TEST(test_algo_graph, path_find_unit_test) {
    algo::Dag dag;
    dag.AddEdge(1, 2);
    dag.AddEdge(1, 3);
    dag.AddEdge(2, 3);
    dag.AddEdge(2, 4);
    dag.AddEdge(3, 4);
    dag.AddEdge(3, 5);
    dag.AddEdge(4, 5);

    std::vector<std::vector<int>> paths = dag.FindAllPaths(1, 5);
    for (const auto& path: paths) {
        for (int node: path) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }
}