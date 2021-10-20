#include "SeqStack.cpp"

int a[10][10] =
    {
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 0}};

struct point
{
    int x;
    int y;
    int dir;
};

class maze
{
private:
    int map[10][10];
    int visited[10][10];
    point start;
    point end;

    void move(int x, int y, point &p)
    {
        p.x += x;
        p.y += y;
    }

    void visit(const point &p)
    {
        visited[p.x][p.y] = 1;
    }

    void dirToGo(point& p)
    {
        switch (p.dir)
        {
        case 0:
            p.x +=1;
            break;
        case 1:
            p.x -=1;
            break;
        case 2:
            p.y +=1;
            break;
        case 3:
            p.y -=1;
            break;
        p.dir +=1;
        }
        
    }

    void initPoint(point &p,point a)
    {
        p.x = a.x;
        p.y = a.y;
        p.dir = 0;
    }

    bool canPass(point p)
    {
        if (map[p.x][p.y] == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEnd(point x)
    {
        if (x.x == end.x&&x.y == end.y)
        {
            return true;
        }
        else
            return false; 
    }
public:
    maze(int a[10][10])
    {
        memcpy(map, a, sizeof(a));
        memcpy(visited, a, sizeof(a));
        start = {0, 0};
        end = {9, 9};
    }

    void findPath(stack<point> Path)
    {  
        int step = 0;
        point Pos;
        initPoint(Pos,start);
        
        while (true)
        {
            point now;
            int flag;
            initPoint(now,Pos);
            if (isEnd(Pos))break;
            while(now.dir < 4)
            {
                dirToGo(now);
                if(canPass(now) == true)
                {
                    visit(now);
                    Path.push(now);
                    break;
                }
            }
            if (now.dir == 4 && !Path.isEmpty())
            {
                Pos = Path.top();
                continue;
            }
            


            continue;
        }
        
    }
};
