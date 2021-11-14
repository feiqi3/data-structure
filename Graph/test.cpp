#include"Graph.cpp"
int main() 
{
    Graph d;
    d.bfs(0);
    d.initVisited();
    d.dfs(0, [](char c) {cout << c <<" "; });
}