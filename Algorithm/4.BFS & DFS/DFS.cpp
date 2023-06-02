#include<stdio.h>
#include<stdbool.h>

#define MAX_NODES 100

typedef struct{//Graph data structure
    int edges[MAX_NODES][MAX_NODES];
    int numNodes;
}Graph;

//Initialize the graph
void initializedGraph(Graph* graph, int numNodes){
    graph->numNodes = numNodes;
    for(int i=0; i<numNodes; i++){
        for(int j=0; j<numNodes; j++){
            graph->edges[i][j];
        }
    }
}
//Add an edges to the graph
void addEdges(Graph* graph, int sources, int destination){
    graph->edges[sources][destination] = 1;
}
void DfsUtilities(Graph* graph, bool visited[], int node){
    visited[node] = true;
    printf("%d ",node);
    for(int i=0; i<graph->numNodes; i++){
        if(graph->edges[node][i] && !visited[i]){
            DfsUtilities(graph, visited, i);
        }
    }
}

void DfsTraversal(Graph* graph, int start){
    bool visited[MAX_NODES] = {false};

    printf("DFS Traversal: ");
    DfsUtilities(graph, visited, start);
    printf("\n\n");
}

int main(){
    Graph graph;
    int numNodes = 7;

    //Initilizead the graph with numNodes
    initializedGraph(&graph, numNodes);

    //Add edges to the graph
    addEdges(&graph, 0, 1);
    addEdges(&graph, 0, 2);
    addEdges(&graph, 1, 3);
    addEdges(&graph, 1, 4);
    addEdges(&graph, 2, 5);
    addEdges(&graph, 2, 6);

    DfsTraversal(&graph, 0);

}