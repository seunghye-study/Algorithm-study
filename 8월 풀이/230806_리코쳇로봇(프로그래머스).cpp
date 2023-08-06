#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <string.h>
using namespace std;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int map[100][100];
int visit[100][100];

int bfs(int x, int y, int n, int m)
{
    queue<pair<int, int>> q;
    q.push({ x, y });
    visit[x][y] = 0;
    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = xx;
            int ny = yy;
            while (true)
            {
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                {
                    break;
                }
                if (map[nx][ny] == -1)
                {
                    break;
                }
                nx += dx[i];
                ny += dy[i];
            }
            nx -= dx[i];
            ny -= dy[i];
            if (map[nx][ny] == 10) return (visit[xx][yy] + 1);
            if (visit[nx][ny] >= 0) continue;
            visit[nx][ny] = visit[xx][yy] + 1;
            q.push({ nx, ny });
        }
    }
    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    int R_x = 0;
    int R_y = 0;
    int n = board.size();
    int m = board[0].length();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            string s = board[i];
            if (s[j] == 'D') map[i][j] = -1;
            else if (s[j] == 'G') map[i][j] = 10;
            else if (s[j] == 'R')
            {
                R_x = i;
                R_y = j;
            }
        }
    }
    memset(visit, -1, sizeof(visit));
    answer = bfs(R_x, R_y, n, m);
    return answer;
}