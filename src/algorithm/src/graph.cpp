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

void DaGraph::AddEdge(
    const int source,
    const int target,
    const float weight) {
    edges_.emplace_back(source, target, weight);
}

void DaGraph::BuildGraph(const int limit_num) {
    if (edges_.empty()) {
        return;
    }
    for (auto& edge: edges_) {
        const int key = edge.source_;
        if (graph_.find(key) != graph_.end()) {
            graph_[key].emplace_back(edge.target_, edge.weight_);
            if ((int)graph_[key].size() == limit_num + 1) {
                std::sort(graph_[key].begin(), graph_[key].end(),
                    [](const std::pair<int, float>& a, const std::pair<int, float>& b) {
                        return a.second > b.second;}
                );
                graph_[key].pop_back();
            }
        } else {
            graph_[key].emplace_back(edge.target_, edge.weight_);
        }
    }
}

void DaGraph::PrintGraph() {
    if (graph_.empty()) {
        return;
    }
    for (const auto& [key, val]: graph_) {
        int source = key;
        for (int i = 0; i < (int)val.size(); ++i) {
            std::cout << source << ": " <<
                "{" << val[i].first << ", " <<
                    val[i].second << "}" << std::endl;
        }
        std::cout << std::endl;
    }
}

} // namespace algo