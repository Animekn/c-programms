#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100

// Structure to represent a graph
struct Graph {
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function prototypes
struct Graph* createGraph(int numVertices);
void addEdge(struct Graph* graph, int src, int dest, int weight);
int findMinKey(int key[], bool mstSet[], int numVertices);
void printMST(int parent[], struct Graph* graph, int numVertices);
void primMST(struct Graph* graph);

int main() {
    int numVertices, numEdges;
    int src, dest, weight;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the details of each edge (source, destination, weight):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    primMST(graph);

    return 0;
}

// Create a graph with given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Initialize adjacency matrix with all values as 0
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    graph->adjacencyMatrix[src][dest] = weight;
    graph->adjacencyMatrix[dest][src] = weight;
}

// Find the vertex with the minimum key value
int findMinKey(int key[], bool mstSet[], int numVertices) {
    int minKey = INT_MAX;
    int minIndex;

    for (int v = 0; v < numVertices; v++) {
        if (mstSet[v] == false && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Print the Minimum Spanning Tree
void printMST(int parent[], struct Graph* graph, int numVertices) {
    printf("Minimum Spanning Tree:\n");
    for (int v = 1; v < numVertices; v++) {
        printf("%d - %d (%d)\n", parent[v], v, graph->adjacencyMatrix[v][parent[v]]);
    }
}

// Prim's algorithm to find the Minimum Spanning Tree
void primMST(struct Graph* graph) {
    int parent[MAX_VERTICES];   // Array to store constructed MST
    int key[MAX_VERTICES];      // Key values used to pick minimum weight edge in cut
    bool mstSet[MAX_VERTICES];  // To represent set of vertices not yet included in MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int v = 0; v < graph->numVertices; v++) {
        key[v] = INT_MAX;
        mstSet[v] = false;
    }

    key[0] = 0;       // Make the key 0 so that this vertex is picked as the first vertex
    parent[0] = -1;   // First node is always the root of MST

    for (int count = 0; count < graph->numVertices - 1; count++) {
        int u = findMinKey(key, mstSet, graph->numVertices);
        mstSet[u] = true;

        for (int v = 0; v < graph->numVertices; v++) {
            if (graph->adjacencyMatrix[u][v] && mstSet[v] == false && graph->adjacencyMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->adjacencyMatrix[u][v];
            }
        }
    }

    printMST(parent, graph, graph->numVertices);
}
