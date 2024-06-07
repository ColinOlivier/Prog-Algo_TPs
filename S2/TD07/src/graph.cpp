#include <stack>
#include <queue>
#include <iostream>
#include "graph.hpp"

namespace Graph {

    void WeightedGraph::add_vertex(int const id) {
        if (adjacency_list.find(id) != adjacency_list.end()) {
            adjacency_list.insert({ id, std::vector<WeightedGraphEdge>{} });
        }
    }

    void WeightedGraph::add_directed_edge(int const from, int const to, float const weight) {
        add_vertex(to);
        adjacency_list[from].push_back(WeightedGraphEdge{ to, weight });
    }

    void WeightedGraph::add_undirected_edge(int const from, int const to, float const weight) {
        add_directed_edge(from, to, weight);
        add_directed_edge(to, from, weight);
    }

    WeightedGraph build_from_adjacency_matrix(std::vector<std::vector<float>> const& adjacency_matrix)
    {
        WeightedGraph weightedGraph{};
        for (size_t i = 0; i < adjacency_matrix.size(); i++)
        {
            for (size_t j = 0; j < adjacency_matrix[i].size(); j++)
            {
                if (adjacency_matrix[i][j] != 0)
                    weightedGraph.add_directed_edge(i, j, adjacency_matrix[i][j]);
            }
        }
        return weightedGraph;
    }

    void WeightedGraph::print_DFS(int const start) const {
        std::vector<int> visitedVertex{};
        std::stack<int> vertexIdStack;

        vertexIdStack.push(start);
        while (!vertexIdStack.empty())
        {
            int topVertexId = vertexIdStack.top();
            vertexIdStack.pop();
            if (std::find(visitedVertex.begin(), visitedVertex.end(), topVertexId) == visitedVertex.end())
            {
                visitedVertex.push_back(topVertexId);
                std::cout << topVertexId;
            }

            for (WeightedGraphEdge edge : adjacency_list.at(topVertexId)) {
                if (std::find(visitedVertex.begin(), visitedVertex.end(), edge.to) == visitedVertex.end())
                    vertexIdStack.push(edge.to);
            }
        }

        std::cout << std::endl;
    }

    void WeightedGraph::print_BFS(int const start) const {
        std::queue<int> vertexIdQueue;
        std::vector<int> visitedVertex{};

        vertexIdQueue.push(start);
        while (!vertexIdQueue.empty())
        {
            int frontVertexId = vertexIdQueue.front();
            vertexIdQueue.pop();

            if (std::find(visitedVertex.begin(), visitedVertex.end(), frontVertexId) == visitedVertex.end()) {
                visitedVertex.push_back(frontVertexId);
                std::cout << frontVertexId << " ";
            }

            for (WeightedGraphEdge edge : adjacency_list.at(frontVertexId))
                if (std::find(visitedVertex.begin(), visitedVertex.end(), edge.to) == visitedVertex.end())
                    vertexIdQueue.push(edge.to);
        }
        std::cout << std::endl;
    }

    void WeightedGraph::DFS(int const start, std::function<void(int const)> const& callback) const {
        std::vector<int> visitedVertex{};
        std::stack<int> vertexIdStack;

        vertexIdStack.push(start);
        while (!vertexIdStack.empty())
        {
            int topVertexId = vertexIdStack.top();
            vertexIdStack.pop();
            if (std::find(visitedVertex.begin(), visitedVertex.end(), topVertexId) == visitedVertex.end())
            {
                visitedVertex.push_back(topVertexId);
                callback(topVertexId);
            }

            for (WeightedGraphEdge edge : adjacency_list.at(topVertexId)) {
                if (std::find(visitedVertex.begin(), visitedVertex.end(), edge.to) == visitedVertex.end())
                    vertexIdStack.push(edge.to);
            }
        }
    }

    std::unordered_map<int, std::pair<float, int>> dijkstra(WeightedGraph const& graph, int const& start, int const end) {
        // On crée un tableau associatif pour stocker les distances les plus courtes connues pour aller du sommet de départ à chaque sommet visité
        // La clé est l'identifiant du sommet et la valeur est un pair (distance, sommet précédent)
        std::unordered_map<int, std::pair<float, int>> distances{};

        // On crée une file de priorité pour stocker les sommets à visiter
        // la pair contient la distance pour aller jusqu'au sommet et l'identifiant du sommet

        // Ce type compliqué permet d'indiquer que l'on souhaite trier les éléments par ordre croissant (std::greater) et donc les éléments les plus petits seront au début de la file (top) (Min heap)
        std::priority_queue<std::pair<float, int>, std::vector<std::pair<float, int>>, std::greater<std::pair<float, int>>> to_visit{};

        std::vector<int> visited{};

        to_visit.push(std::make_pair(0.f, start));

        while (!to_visit.empty())
        {
            float currentDistanceToStart = to_visit.top().first;
            int currentNodeVisited = to_visit.top().second;

            to_visit.pop();

            if (currentNodeVisited == end)
                return distances;

            if (graph.adjacency_list.find(currentNodeVisited) == graph.adjacency_list.end())
                continue;

            std::vector<Graph::WeightedGraphEdge> currentAdjacencyList = graph.adjacency_list.at(currentNodeVisited);

            for (size_t i = 0; i < currentAdjacencyList.size(); i++)
            {
                Graph::WeightedGraphEdge adjacencyEdge = currentAdjacencyList[i];
                // Already visit
                if (std::find(visited.begin(), visited.end(), adjacencyEdge.to) != visited.end())
                    continue;

                float adjacencyDistanceToStart = currentDistanceToStart + adjacencyEdge.weight;

                // Distance a l'infini
                if (distances.find(adjacencyEdge.to) == distances.end()) {
                    distances.insert(std::make_pair(adjacencyEdge.to, std::make_pair(adjacencyDistanceToStart, currentNodeVisited)));
                    to_visit.push(std::make_pair(adjacencyDistanceToStart, adjacencyEdge.to));
                }
                else {
                    if (distances.at(adjacencyEdge.to).first > adjacencyDistanceToStart) {
                        distances[adjacencyEdge.to] = std::make_pair(adjacencyDistanceToStart, currentNodeVisited);
                        to_visit.push(std::make_pair(adjacencyDistanceToStart, adjacencyEdge.to));
                    }
                }
            }
            visited.push_back(currentNodeVisited);
        }
        return distances;
    }
}

