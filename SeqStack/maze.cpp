#include"SeqStack.cpp"
#include<iostream>
int a[10][10] =
{
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 0, 1, 0, 1, 0, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
    {1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
    {1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 0} };

struct point
{
    int x;
    int y;
    int dir;

    void pointOut() 
    {
        printf("(%d,%d)", x, y);
    }
};

class maze
{
private:
    int map[10][10];
    int visited[10][10];
    point start;
    point end;

    void move(int x, int y, point& p)
    {
        p.x += x;
        p.y += y;
    }

    void visit(const point& p)
    {
        visited[p.x][p.y] = 1;
    }

    point dirToGo(point& p)
    {
        point tar;
        tar.dir = 0;
        tar.x = p.x;
        tar.y = p.y;
        switch (p.dir)
        {
        case 0:
            tar.x += 1;
            break;
        case 1:
            tar.x -= 1;
            break;
        case 2:
            tar.y += 1;
            break;
        case 3:
            tar.y -= 1;
            break;
        }
        p.dir += 1;
        return tar;
    }

    void initPoint(point& p, point a)
    {
        p.x = a.x;
        p.y = a.y;
        p.dir = 0;
    }

    bool canPass(point p)
    {
        if (map[p.x][p.y] == 0 && visited[p.x][p.y] == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //判断是否到了终点
    bool isEnd(point x)
    {
        if (x.x == end.x && x.y == end.y)
        {
            return true;
        }
        else
            return false;
    }
public:
    maze(int a[10][10])
    {
        memcpy(map, a, 10 * 10 * sizeof(int));
        memcpy(visited, a, 10 * 10 * sizeof(int));
        start = { 0, 0 };
        end = { 9, 9 };
    }

    int findPath(stack<point> &Path)
    {
        int step = 0;
        point now;
        initPoint(now, start);
        while (true)
        {
            
            if (isEnd(now))break;
            while (now.dir < 4)
            {
                point tmp = dirToGo(now);//下一步可能走的地方
                if (canPass(tmp) == true)
                {
                    step++;
                    now = tmp;
                    visit(now);
                    Path.push(now);
                    break;
                }
            }
            if (now.dir == 4 && !Path.isEmpty())//把所有可能的位置走完了，则返回上一个路径
            {
                now = Path.top();
                step--;
                continue;
            }
            continue;
        }
        return step;
    }
};

int main()
{
    maze m(a);
    stack<point> path;
    int step = m.findPath(path);
    auto end= path.top();
    path.stackTraverse([](point a) 
    {
     a.pointOut();
     printf(" -> \n");
    });
    end.pointOut();
    printf("\nTotal: %d step",step);
    
}