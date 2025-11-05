#pragma once
#include <string>

enum NodeType { AMBULANCE, HOUSE, HOSPITAL, INTERSECTION ,DISASTER};

struct Node {
    int id;
    NodeType type;
    std::string name;
    int drain;
};

struct Edge {
    int to;
    int weight;
};
