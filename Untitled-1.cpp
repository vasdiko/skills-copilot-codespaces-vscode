#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class GraphStructure {
public:
    // O grafoς apothikevei tis sindeseis se mia lista geitniasis
    unordered_map<int, vector<int>> adjList;

    // Pros8hki akmh metaxy dyo korufwn
    void addConnection(int node1, int node2) {
        adjList[node1].push_back(node2);  // Pros8etei thn akmh sto node1
        adjList[node2].push_back(node1);  // Pros8etei thn akmh sto node2 (mi katefthynomenos grafoς)
    }

    // Ektelesi BFS gia na broume diadromh mesa se zygoys komvous
    void breadthFirstSearch(int start, int goal) {
        unordered_map<int, bool> visitedNodes;  // Apothikeuei poioi komvoi exoun episkefthei
        unordered_map<int, int> levels;         // Apothikeuei ta epipeda kathe komvou
        queue<int> toExplore;                   // Xrhsimopoieitai gia tin anazhthsh katà platos

        visitedNodes[start] = true;  // Sigoura o komvos ekkinisis exei episkefthei
        levels[start] = 0;           // To epipedo tou komvou ekkinisis einai 0
        toExplore.push(start);       // Pros8hki ton komvo ekkinisis sthn oura

        while (!toExplore.empty()) {
            int currentNode = toExplore.front();  // Paizei ton trexonta kombo
            toExplore.pop();                      // Apokatharizei ton kombo apo tin oura

            // An vriskoume ton stoxo, ektypwnei to epipedo tou
            if (currentNode == goal) {
                cout << "H korufi stoxos vrethike sto epipedo: " << levels[currentNode] << endl;
                return;
            }

            // Diatrexoume tous geitones tou komvou
            for (int neighbour : adjList[currentNode]) {
                // Prospathoume mono se zygous komvous
                if (!visitedNodes[neighbour] && neighbour % 2 == 0) {
                    visitedNodes[neighbour] = true;          // Simainwnei oti o komvos episkeftike
                    levels[neighbour] = levels[currentNode] + 1;  // To epipedo tou geitona einai to epipedo tou trexontos + 1
                    toExplore.push(neighbour);  // Prosthiki tou geitona stin oura gia epomenh episkepsi
                }
            }
        }

        cout << "Den vrethike diadromi ston grafo." << endl;  // An den vriskoume diadromi
    }
};

int main() {
    GraphStructure graph;

    // Eisagwgh akmwn sto grafo
    graph.addConnection(1, 2);
    graph.addConnection(1, 3);
    graph.addConnection(1, 4);
    graph.addConnection(2, 5);
    graph.addConnection(2, 6);
    graph.addConnection(3, 4);
    graph.addConnection(3, 6);
    graph.addConnection(4, 7);
    graph.addConnection(4, 8);
    graph.addConnection(4, 9);
    graph.addConnection(5, 6);
    graph.addConnection(6, 7);
    graph.addConnection(7, 8);
    graph.addConnection(7, 10);
    graph.addConnection(7, 11);
    graph.addConnection(7, 12);
    graph.addConnection(8, 12);
    graph.addConnection(11, 12);
    graph.addConnection(13, 14);
    graph.addConnection(14, 15);

    // Eisagwgh twn korufwn ekkinisis kai stoxou gia tin anazhthsh
    int startVertex, goalVertex;
    cout << "Dose tin korifi ekkinisis: ";
    cin >> startVertex;
    cout << "Dose tin korifi stoxou: ";
    cin >> goalVertex;

    // Ektelesi BFS gia na vroume an iparxei diadromi apo tin arxh sthn stoxo
    graph.breadthFirstSearch(startVertex, goalVertex);

    return 0;
}
