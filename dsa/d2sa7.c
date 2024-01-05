#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset
struct Subset {
    int parent;
    int rank;
};

// Function prototypes
int find(struct Subset subsets[], int i);
void unionSet(struct Subset subsets[], int x, int y);
int compare(const void* a, const void* b);
void kruskalMST(struct Edge edges[], int numVertices, int numEdges);

int main() {
    int numVertices, numEdges;
    struct Edge edges[MAX_EDGES];

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the details of each edge (source, destination, weight):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskalMST(edges, numVertices, numEdges);

    return 0;
}

// Find the subset of an element 'i'
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// Perform union of two subsets 'x' and 'y'
void unionSet(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function used by qsort to sort the edges in non-decreasing order of weight
int compare(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;

    return edgeA->weight - edgeB->weight;
}

// Kruskal's algorithm to find the minimum spanning tree
void kruskalMST(struct Edge edges[], int numVertices, int numEdges) {
    struct Edge result[numVertices];
    struct Subset subsets[numVertices];

    qsort(edges, numEdges, sizeof(struct Edge), compare);

    for (int i = 0; i < numVertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int e = 0;
    int i = 0;

    while (e < numVertices - 1 && i < numEdges) {
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSet(subsets, x, y);
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < e; i++) {
        printf("%d - %d (%d)\n", result[i].src, result[i].dest, result[i].weight);
    }
}
