#include <iostream>
#include "graph.hpp"

int main() {
    Graph::WeightedGraph weightedGraph_1 = Graph::build_from_adjacency_matrix(
        {
            {0, 1, 0, 0, 1},
            {1, 0, 1, 1, 0},
            {0, 1, 0, 0, 0},
            {0, 1, 0, 0, 1},
            {1, 0, 0, 1, 0},
        }
    );

    Graph::WeightedGraph weightedGraph_2{};
    weightedGraph_2.add_vertex(0);
    weightedGraph_2.add_vertex(1);
    weightedGraph_2.add_vertex(2);
    weightedGraph_2.add_vertex(3);
    weightedGraph_2.add_vertex(4);

    weightedGraph_2.add_undirected_edge(0, 1, 1.f);
    weightedGraph_2.add_undirected_edge(0, 4, 1.f);
    weightedGraph_2.add_undirected_edge(1, 2, 1.f);
    weightedGraph_2.add_undirected_edge(1, 3, 1.f);
    weightedGraph_2.add_undirected_edge(3, 4, 1.f);

    if (weightedGraph_1 == weightedGraph_2) {
        std::cout << "Graph ==" << std::endl;
    }
    else {
        std::cout << "Graph !=" << std::endl;
    }

    std::cout << "DFS from node 0:" << std::endl << "Visited nodes: ";
    weightedGraph_1.DFS(0, [](int const node_id) { std::cout << node_id << " "; });
    std::cout << std::endl;

    // Dijkstra

    Graph::WeightedGraph dijkstraGraph{};

    int A_ID, B_ID, C_ID, D_ID, E_ID, F_ID;
    A_ID = 0;
    B_ID = 1;
    C_ID = 2;
    D_ID = 3;
    E_ID = 4;
    F_ID = 5;

    dijkstraGraph.add_vertex(A_ID);
    dijkstraGraph.add_vertex(B_ID);
    dijkstraGraph.add_vertex(C_ID);
    dijkstraGraph.add_vertex(D_ID);
    dijkstraGraph.add_vertex(E_ID);
    dijkstraGraph.add_vertex(F_ID);

    dijkstraGraph.add_directed_edge(A_ID, B_ID, 1.f);
    dijkstraGraph.add_directed_edge(A_ID, C_ID, 5.f);
    dijkstraGraph.add_directed_edge(A_ID, D_ID, 2.f);
    dijkstraGraph.add_directed_edge(B_ID, C_ID, 4.f);
    dijkstraGraph.add_directed_edge(B_ID, D_ID, 5.f);
    dijkstraGraph.add_directed_edge(D_ID, C_ID, 2.f);
    dijkstraGraph.add_directed_edge(D_ID, E_ID, 5.f);
    dijkstraGraph.add_directed_edge(C_ID, E_ID, 3.f);
    dijkstraGraph.add_directed_edge(C_ID, F_ID, 4.f);
    dijkstraGraph.add_directed_edge(E_ID, F_ID, 3.f);


    std::unordered_map<int, std::pair<float, int>> dijkstraResult = Graph::dijkstra(dijkstraGraph, A_ID, E_ID);

    for (std::pair<int, std::pair<float, int>> p : dijkstraResult)
    {
        std::cout << p.first << " : " << p.second.first << ", " << p.second.second << std::endl;
    }

    int beforeNode = E_ID;
    std::cout << "distance : " << dijkstraResult.at(beforeNode).first << std::endl;
    while (beforeNode != A_ID)
    {
        std::cout << beforeNode << ", ";
        beforeNode = dijkstraResult.at(beforeNode).second;
    }

    std::cout << std::endl;



    return 0;
}