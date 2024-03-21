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

struct Edge {
   int source_;
   int target_;
   float weight_;
   Edge(const int source, const int target, const float weight) :
      source_(source), target_(target), weight_(weight) {}
};

struct Node {
   int id_;
   Node(int id) : id_(id) {}
};

class DaGraph {
 public:
   void AddNode(const int id);
   void AddEdge(const int source, const int target, const float weight);

 private:
   std::unordered_map<int, Node> nodes_;
   std::vector<Edge> edges_;
};

} // namespace algo

#endif