#ifndef GRAPH_H__
#define GRAPH_H__
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
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
  void Dfs(int current, int end, std::unordered_map<int, bool>& visited,
           std::vector<int>& path, std::vector<std::vector<int>>& paths);
};

struct Edge {
  int source_;
  int target_;
  float weight_;
  Edge(const int source, const int target, const float weight)
      : source_(source), target_(target), weight_(weight) {}
};

struct Node {
  int id_;
  Node(int id) : id_(id) {}
};

class DaGraph {
 public:
  void AddEdge(const int source, const int target, const float weight);
  void BuildGraph(const int limit_num, const bool is_heap);
  void PrintGraph();

 private:
  std::unordered_map<int, std::vector<std::pair<int, float>>> graph_;
  std::vector<Edge> edges_;
};

class GraphNode;
class GraphEdge;

class GraphEdge {
 public:
  GraphEdge() {}
  GraphEdge(GraphNode* begin_node, GraphNode* end_node, int weight)
      : begin_node_(begin_node), end_node_(end_node), weight_(weight) {}
  GraphNode* begin_node_;
  GraphNode* end_node_;
  int weight_;
};

class GraphNode {
 public:
  GraphNode() {}
  GraphNode(int value) : value_(value) {
    in_ = 0;
    out_ = 0;
  }
  int value_;
  int in_;
  int out_;
  std::vector<GraphNode*> nexts_;
  std::vector<GraphEdge*> edges_;
};

class Graph {
 public:
  std::unordered_map<int, GraphNode*> nodes_;
  std::unordered_set<GraphEdge*> edges_;
};
}  // namespace algo

#endif