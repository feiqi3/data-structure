#define MAXVN 100
#include<iostream>
#include<limits>
#include<cstring>
#include<queue>
using namespace std;


class Graph
{
private:
    char Vertics[MAXVN];
    float Weight[MAXVN][MAXVN];
    int vexNum, arcNum;
    int visited[MAXVN];
public:
    Graph()
    {
        cin >> vexNum >> arcNum;
        for (int i = 0; i < vexNum; i++)
            cin >> Vertics[i];
        for (int i = 0; i < vexNum; i++)
            for (int j = 0; j < vexNum; j++)
            {
                Weight[i][j] = 0;
            }

        for (int i = 0; i < arcNum; i++)
        {
            char c1, c2;
            int w;
            cin >> c1 >> c2 >> w;
            int l1, l2;
            l1 = locateVex(c1);
            l2 = locateVex(c2);
            if (l1 == -1 || l2 == -1)
            {
                throw std::out_of_range("Vertex not found");
            }
            Weight[l1][l2] = w;
        }
        memset(visited, 0, vexNum);
    }
    int locateVex(char c)
    {
        for (int i = 0; i < vexNum; i++)
        {
            if (Vertics[i] == c)
                return i;
        }
        return -1;
    }

    void dfs(int v, void(*p)(char c))
    {
        if (visited[v] == 1)
        {
            return;
        }
        p(Vertics[v]);
        visited[v] = 1;
        for (int i = 0; i < vexNum; i++)
        {
            if (Weight[v][i] != 0)
            {
                dfs(i, p);
            }
        }
    }

    void bfs(int v)
    {
        visited[v] = 1;
        queue<char> Q;
        Q.push(Vertics[v]);
        cout << Vertics[v] << " ";
        while (!Q.empty())
        {
            char w = Q.front();
            Q.pop();
            for (char c = firstAdjVex(w); c != -1; c = nextAdjVex(w, c))
            {
                int d = findVex(c);
                if (visited[d] != 0)
                {
                    visited[d] = 1;
                    cout << c << " ";
                }
            }
        }

    }

    char firstAdjVex(char c)
    {
        int v = findVex(c);
        for (int i = 0; i < vexNum; i++)
            if (Weight[v][i] != 0)return Vertics[i];
    }

    char nextAdjVex(int v, char c)
    {
        int j = findVex(c);
        for (int i = j + 1; i < vexNum; i++)
        {
            if (Weight[v][i] != 0)return Vertics[i];
        }
        return -1;
    }

    int findVex(char c)
    {
        for (int i = 0; i < vexNum; i++)
        {
            if (Vertics[i] == c)
            {
                return i;
            }
        }

    }
    void initVisited() 
    {
        memset(visited, 0, vexNum*sizeof(int));
    }
};





