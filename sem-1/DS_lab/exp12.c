#include <stdio.h>
#include <stdlib.h>

void dfs(int graph[10][10], int visited[10], int totalvertices, int currentvertex)
{
    printf("%d", currentvertex);
    visited[currentvertex] = 1;

    for (int i = 0; i < totalvertices; i++)
    {
        if (graph[currentvertex][i] == 1 && visited[i] == 0)
        {
            dfs(graph, visited, totalvertices, i);
        }
    }
}

int main()
{
    int graph[10][10];
    int visited[10];
    int totalVertices;
    int startVertex;

    for (int i = 0; i < 10; i++)
    {
        visited[i] = 0;
    }

    printf("Enter the number of vertices (up to 10): ");
    scanf("%d", &totalVertices);

    for (int i = 0; i < totalVertices; i++)
    {
        for (int j = 0; j < totalVertices; j++)
        {
            printf("Edge between vertex %d and vertex %d (0 or 1): ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex (0 to %d): ", totalVertices - 1);
    scanf("%d", &startVertex);

    printf("DFS Traversal starting from vertex %d: ", startVertex);
    dfs(graph, visited, totalVertices, startVertex);

    // Print a newline for better output formatting
    printf("\n");
    return 0;
}
