#include <iostream>
#include <vector>

void print(const std::vector<std::vector<int>>& graph)
{
    for (const auto& x : graph) {
        for (const auto& y : x) {
            if (y == INT_MAX)
                std::cout << "-" << "  ";
            else
                std::cout << y << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int Crit_Path(std::vector<std::vector<int>>& graph)
{
    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
            {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
                {
                    if (graph[i][j] == INT_MAX)
                        graph[i][j] = graph[i][k] + graph[k][j];
                    else 
                        graph[i][j]=std::min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }   
    }
    print(graph);
    return graph[0][7];
}

int main()
{
    int c = INT_MAX;
    std::vector<std::vector<int>> graph =
    {
        {0,2,1,7,c,c,c,c,c,c},
        {c,0,c,c,1,4,c,c,c,c},
        {c,c,0,c,c,c,3,8,c,c},
        {c,c,c,0,c,c,c,c,1,c},
        {c,c,c,c,0,c,1,6,c,c},
        {c,c,c,1,c,0,c,c,c,c},
        {c,c,c,c,c,c,0,c,4,1},
        {c,c,c,c,c,c,c,0,c,c},
        {c,c,c,c,c,c,c,1,0,c},
        {c,c,c,c,c,1,c,c,c,0}
    };
    print(graph);
    int path = Crit_Path(graph);
    std::cout << "Critical path: " << path;
}

