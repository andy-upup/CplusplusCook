#ifndef GRAPH_H__
#define GRAPH_H__
#include <iostream>
#include <unordered_map>
#include <vector>

namespace algo {

class Dag {
 public:
    Dag() {}
    void AddNode(int node);
    void AddEdge(int start, int end);
    std::vector<std::vector<int>> FindAllPaths(int start, int end);
 private:
    std::unordered_map<int, std::vector<int>> graph_;
    void Dfs(
        int current,
        int end,
        std::unordered_map<int, bool>& visited,
        std::vector<int>& path,
        std::vector<std::vector<int>>& paths);
};
} // namespace algo

#endif