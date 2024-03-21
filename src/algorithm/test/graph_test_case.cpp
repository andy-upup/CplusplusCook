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

TEST(test_algo_graph, knn_unit_test) {
    algo::DaGraph dag;
    dag.AddEdge(1, 2, 0.5);
    dag.AddEdge(1, 3, 0.6);
    dag.AddEdge(1, 4, 0.7);
    dag.AddEdge(1, 5, 0.9);
    dag.AddEdge(2, 1, 0.8);
    dag.AddEdge(2, 3, 0.1);
    dag.AddEdge(2, 7, 0.3);
    dag.AddEdge(2, 9, 0.5);
    dag.BuildGraph(3);
    dag.PrintGraph();
}