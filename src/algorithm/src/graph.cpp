#include "graph.h"

namespace algo {

static bool cmp(const std::pair<int, float>& a,
                const std::pair<int, float>& b) {
  return a.second > b.second;
}

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

void Dag::Dfs(int current, int end, std::unordered_map<int, bool>& visited,
              std::vector<int>& path, std::vector<std::vector<int>>& paths) {
  visited[current] = true;
  path.emplace_back(current);
  if (current == end) {
    paths.emplace_back(path);
  } else {
    for (int next : graph_[current]) {
      if (!visited[next]) {
        Dfs(next, end, visited, path, paths);
      }
    }
  }
  visited[current] = false;
  path.pop_back();
}

void DaGraph::AddEdge(const int source, const int target, const float weight) {
  edges_.emplace_back(source, target, weight);
}

// Directly emplace_back the edge, if the quantity exceeds the limit,
// delete the one with the smallest weight.
void DaGraph::BuildGraph(const int limit_num, const bool is_heap) {
  if (edges_.empty()) {
    return;
  }
  for (auto& edge : edges_) {
    const int key = edge.source_;
    if ((graph_.find(key) == graph_.end()) ||
        ((int)graph_[key].size() < limit_num) ||
        (graph_[key].back().second < edge.weight_)) {
      graph_[key].emplace_back(edge.target_, edge.weight_);
    }
    if (is_heap) {
      std::push_heap(graph_[key].begin(), graph_[key].end(), cmp);
    }
    if ((int)graph_[key].size() == limit_num + 1) {
      if (is_heap) {
        std::pop_heap(graph_[key].begin(), graph_[key].end(), cmp);
      } else {
        std::sort(graph_[key].begin(), graph_[key].end(), cmp);
      }
      graph_[key].pop_back();
    }
  }
}

void DaGraph::PrintGraph() {
  if (graph_.empty()) {
    return;
  }
  for (const auto& [key, val] : graph_) {
    int source = key;
    for (int i = 0; i < (int)val.size(); ++i) {
      std::cout << source << ": "
                << "{" << val[i].first << ", " << val[i].second << "}"
                << std::endl;
    }
    std::cout << std::endl;
  }
}

Graph* CreateGraph(std::vector<std::vector<int>>& matrix) {
  if (matrix.empty()) {
    return nullptr;
  }
  Graph* graph = new Graph;
  for (int i = 0; i < matrix.size(); ++i) {
    if (matrix[i].size() != 3) {
      return nullptr;
    }
    int begin_val = matrix[i][0];
    int end_val = matrix[i][1];
    int weight = matrix[i][2];
    if (graph->nodes_.find(begin_val) == graph->nodes_.end()) {
      graph->nodes_[begin_val] = new GraphNode(begin_val);
    }
    if (graph->nodes_.find(end_val) == graph->nodes_.end()) {
      graph->nodes_[end_val] = new GraphNode(end_val);
    }
    GraphNode* begin_node = graph->nodes_[begin_val];
    GraphNode* end_node = graph->nodes_[end_val];

    GraphEdge* edge = new GraphEdge(begin_node, end_node, weight);
    begin_node->nexts_.push_back(end_node);
    begin_node->out_++;
    begin_node->edges_.push_back(edge);
    end_node->in_++;
    graph->edges_.insert(edge);
  }
}

}  // namespace algo