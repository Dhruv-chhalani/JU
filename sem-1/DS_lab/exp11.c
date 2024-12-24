// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 100

// int queue[MAX];
// int front = -1, rear = -1;

// int isEmpty()
// {
//     return front == -1;
// }

// void enqueue(int value)
// {
//     if (rear == MAX - 1)
//     {
//         printf("Queue is full!");
//     }
//     if (front == -1)
//     {
//         front = 0;
//     }
//     rear++;
//     queue[rear] = value;
// }

// int dequeue()
// {
//     if (isEmpty())
//     {
//         printf("QUEUE is Empty ");
//     }
//     int item = queue[front];
//     front++;
//     if (front > rear)
//     {
//         front = rear = -1;
//     }
//     return item;
// }

// void bfs(int graph[MAX][MAX], int n, int start)
// {
//     int visited[MAX] = {0};

//     visited[start] = 1;
//     enqueue(start);

//     while (!isEmpty())
//     {
//         int cur = dequeue();
//         printf("%d", cur);

//         for (int i = 0; i < n; i++)
//         {
//             if (graph[cur][i] == 1 && !visited[i])
//             {
//                 visited[i] = 1;
//                 enqueue(i);
//             }
//         }
//     }
//     printf("\n");
// }

// int main()
// {
//     int n, start;
//     int graph[MAX][MAX];

//     // Input number of vertices
//     printf("Enter the number of vertices: ");
//     scanf("%d", &n);

//     // Input adjacency matrix
//     printf("Enter the adjacency matrix:\n");
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             scanf("%d", &graph[i][j]);
//         }
//     }

//     // Input the starting vertex
//     printf("Enter the starting vertex (0 to %d): ", n - 1);
//     scanf("%d", &start);

//     // Perform BFS
//     bfs(graph, n, start);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum number of vertices in the graph

// Array-based Queue Implementation
int queue[MAX];
int front = -1, rear = -1;


// Check if the queue is empty
int isEmpty()
{
    return front == -1;
}

// Enqueue an element into the queue
void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = value;
}

// Dequeue an element from the queue
int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = queue[front];
    front++;
    if (front > rear)
    {
        // Reset the queue when empty
        front = rear = -1;
    }
    return item;
}

// BFS function
void BFS(int graph[MAX][MAX], int n, int start)
{
    int visited[MAX] = {0}; // Array to track visited vertices

    // Mark the starting vertex as visited and enqueue it
    visited[start] = 1;
    enqueue(start);

    printf("Breadth-First Traversal: ");
    while (!isEmpty())
    {
        int current = dequeue();
        printf("%d ", current);

        // Visit all adjacent vertices
        for (int i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main()
{
    int n, start;
    int graph[MAX][MAX];

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Input the starting vertex
    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    // Perform BFS
    BFS(graph, n, start);

    return 0;
}