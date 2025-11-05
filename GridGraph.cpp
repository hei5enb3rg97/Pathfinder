#include "GridGraph.h"
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <random>
#include <algorithm>
#include <time.h>

using namespace std;

// constructor for the graph
    GridGraph::GridGraph(int size) : n(size) {
        int total = n * n;
        adj.resize(total);
        nodes.resize(total);
        for (int i = 0; i < total; i++) {
            nodes[i].id = i;
            nodes[i].type = INTERSECTION;
            nodes[i].name = "Intersection_" + to_string(i);
        }
    }
    // creates the base for nxn grid graph

    int GridGraph::nodeID(int row, int col) {
        return row * n + col;
    }
    // returns node number based on rows and columns

    void GridGraph::addEdge(int u, int v, int weight) {
        adj[u].push_back({ v, weight });
        adj[v].push_back({ u, weight }); // undirected
    }
    // connects u to v and v to u (bidirectional edge)

    void GridGraph::buildGrid() {
        // random number generator and seeding it with time to get true randomness
        mt19937 gen(time(0));
        //range 
        uniform_int_distribution<> dis(1, 10);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int current = nodeID(r, c);
                if (r > 0) addEdge(current, nodeID(r - 1, c),dis(gen));
                if (c > 0) addEdge(current, nodeID(r, c - 1),dis(gen));
            }
        }
        // drain is a member which gives the elevation of a place(node) and the drainage conditions (1- low elevation/bad drainage, 10- high elevation/good drainage)
        uniform_int_distribution<> drain(1,10);
        for(auto &node : nodes) node.drain=drain(gen);
    }
    // creates edges between adjacent nodes and randomly generates a number from 1-10 and assigns it as weight to the nodes to simulate distance and traffic

    void GridGraph::assignNodeType(int id, NodeType type, string name) {
        nodes[id].type = type;
        if (!name.empty()) nodes[id].name = name;
    }
    // node type is set as intersection by default unless explicitly mentioned, name of the node is an empty string by default

    // Dijkstra returns path from src to dest and total cost
    vector<int> GridGraph::dijkstra(int src, int dest, int& total_cost) {
        int V = n * n;
        vector<int> dist(V, numeric_limits<int>::max());
        vector<int> vis(V);
        vector<int> prev(V, -1);
        dist[src] = 0;

        // Min-heap (cost, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> path;

        if(nodes[src].type == DISASTER || src == -1 || dest == -1) return path;
        pq.push({ 0, src });

        while (!pq.empty()) {
            auto d= pq.top().first;
            auto u= pq.top().second;
            pq.pop();

            if (vis[u]==1) continue;
            //if the current pair is an old pair whose shortest path from the source was already determined we skip it
            vis[u]=1;

            for (auto& edge : adj[u]) {
                int v = edge.to;
                int weight = edge.weight;
                // if the node is damaged we dont travel through that node
                if(nodes[v].type == DISASTER) continue;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    pq.push({ dist[v], v });
                }
            }
        }

        total_cost = dist[dest];

        // if the dist value of the node is INF the node cant be reached
        if (total_cost == numeric_limits<int>::max()) return path; // No path found

        // we recreate the path by using prev vector and reversing the resultant sequence 
        for (int at = dest; at != -1; at = prev[at]) path.push_back(at);
        reverse(path.begin(), path.end());
        return path;
    }

    // To find the nearest node of a particular type from the current node
    int GridGraph::findNearest(int from, NodeType type) {
        int best = -1;
        int minDist = numeric_limits<int>::max();
        int dummyCost;
        for (auto& node : nodes) {
            // Skip nodes of other types and damaged nodes
            if (node.type == type && node.type != DISASTER) {
                vector<int> path = dijkstra(from, node.id, dummyCost);
                if (!path.empty() && dummyCost < minDist) {
                    minDist = dummyCost;
                    best = node.id;
                }
            }
        }
        return best;
    }

    // To find the nearest ambulance and route it to the target
    void GridGraph::emergency(int from) {
        int costToHouse;
        // finds nearest ambulance
        int nearestAmbulance = findNearest(from, AMBULANCE);
        // if target node is damaged cannot access it
        if(nodes[from].type == DISASTER) {
            cout << "The node is damaged cannot access it" << endl;
            return;
        }
        // No ambulances are roaming at the moment so we find the nearest hospital instead
        if(nearestAmbulance == -1) {
            cout << "There are no Ambulances roaming at the moment" << endl;
            nearestAmbulance = findNearest(from, HOSPITAL);
        }
        
        // Finding the shortest path by calling dijkstra
        cout << "Finding shortest path from ambulance to emergency house..." << endl;
        vector<int> pathToHouse = dijkstra(nearestAmbulance, from, costToHouse);
        cout << "Path: ";
        printPath(pathToHouse);
        cout << "Distance: " << costToHouse << endl;
        
        // After reaching the house we find the nearest hospital and find the route
        cout << "Finding nearest hospital from the emergency house..." << endl;
        int nearestHospital = findNearest(from, HOSPITAL);
        // If there are no hospitals or if they were destroyed during the disaster
        if(nearestHospital == -1) {
            cout << "Cannot access any hospitals" << endl;
            return;
        }
        else{
            int costToHospital;
            // Finding the shortest path by calling dijkstra
            vector<int> pathToHospital = dijkstra(from, nearestHospital, costToHospital);
            cout << "Path: ";
            printPath(pathToHospital);
            cout << "Distance: " << costToHospital << endl;
        }
        cout << endl;
    }

    // Prints the path
    void GridGraph::printPath(const vector<int>& path) {
        for (size_t i = 0; i < path.size(); i++) {
            cout << nodes[path[i]].name;
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }

    // Earthquake simulation with an epicenter
    void GridGraph::simulateearthquake(int epicenterID) {
        int V = n * n;
        vector<int> dist(V, numeric_limits<int>::max());
        dist[epicenterID] = 0;
        
        // randomly generate the scale of the earthquake (dis indicates the damage radius)
        mt19937 gen(time(0));
        uniform_int_distribution<> dis(5.0, 10.0);
        int maxDistance = dis(gen);
        
        // Min-priority queue stores pairs (distance, nodeID)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, epicenterID});
        
        // Finding all nodes with distance less than dis using dijkstra and marking them as damaged
        while (!pq.empty()) {
            auto currDist = pq.top().first;
            auto currNode = pq.top().second;
            pq.pop();
            
            if (currDist > maxDistance) break;  // Stop if outside earthquake scale
            if (nodes[currNode].type != DISASTER) {
                nodes[currNode].type = DISASTER;  // Mark node as damaged
            }
            
            for (auto& edge : adj[currNode]) {
                int neighbor = edge.to;
                int nextDist = currDist + edge.weight;
                
                if (nextDist <= maxDistance && nextDist < dist[neighbor]) {
                    dist[neighbor] = nextDist;
                    pq.push({nextDist, neighbor});
                }
            }
        }
        damage(); // shows all the damaged nodes
    }

    // Rain simulation
    void GridGraph::simulateRain(){

        // Randomly generate the severity of rainfall (severity indicates the drain value below which the nodes will be flooded)
        mt19937 gen(time(0));
        uniform_int_distribution<> ran(1, 4);
        int severity = ran(gen);

        for(auto &node : nodes) {
            if(node.drain <= severity) node.type = DISASTER; // if the elevation/drainage (indicated by drain) is bad the node is marked as flooded 
        }
        damage(); // show all damaged nodes
    }

    // prints all the damaged nodes
    void GridGraph::damage(){
        cout << "Damaged nodes:" << endl;
        for (auto& node : nodes) {
            if (node.type == DISASTER) {
                cout << node.name << " (ID " << node.id << ")" << endl;
            }
        }
        cout << endl;
    }
