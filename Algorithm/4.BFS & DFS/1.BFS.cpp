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

void bfsTraverse(Graph* graph, int start){
    bool visited[MAX_NODES] = {false};
    int queue[MAX_NODES];
    int front = 0;
    int rare = 0;
    visited[start] = true;
    queue[rare++] = start;

    printf("\nBFS Traversal: ");
    while(front<rare){
        int node = queue[front++];
        printf("%d ",node);
        for(int i=0; i<graph->numNodes; i++){
            if(graph->edges[node][i] && !visited[i]){
                visited[i] = true;
                queue[rare++] = i;
            }
        }
    }
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

    bfsTraverse(&graph, 0);

}