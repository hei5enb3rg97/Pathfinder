#pragma once
#include "NodeStructures.h"
#include <vector>

class GridGraph {
public:
    int n;
    std::vector<Node> nodes;
    std::vector<std::vector<Edge>> adj;

    GridGraph(int size);
    int nodeID(int row, int col);
    void addEdge(int u, int v, int weight);
    void buildGrid();
    void assignNodeType(int id, NodeType type, std::string name = "");
    std::vector<int> dijkstra(int src, int dest, int& total_cost);
    int findNearest(int from, NodeType type);
    void emergency(int from);
    void printPath(const std::vector<int>& path);
    void simulateearthquake(int epicenterID);
    void simulateRain();
    void damage();
};
