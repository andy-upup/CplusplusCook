#include "graph.h"

namespace algo {

void Dag::AddNode(int node) {
    if (graph_.find(node) == graph_.end()) {
        graph_[node] = std::vector<int>();
    }
}

void Dag::AddEdge(int start, int end) {
    AddNode(start);
    AddNode(end);
    graph_[start].emplace_back(end);
}

std::vector<std::vector<int>> Dag::FindAllPaths(int start, int end) {
    std::vector<std::vector<int>> paths;
    std::vector<int> path;
    std::unordered_map<int, bool> visited;
    Dfs(start, end, visited, path, paths);
    return paths;
}

void Dag::Dfs(
    int current,
    int end,
    std::unordered_map<int, bool>& visited,
    std::vector<int>& path,
    std::vector<std::vector<int>>& paths) {
    visited[current] = true;
    path.emplace_back(current);
    if (current == end) {
        paths.emplace_back(path);
    } else {
        for (int next: graph_[current]) {
            if (!visited[next]) {
                Dfs(next, end, visited, path, paths);
            }
        }
    }
    visited[current] = false;
    path.pop_back();
}

} // namespace algo