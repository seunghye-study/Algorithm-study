#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int map[101][101];
bool visit[101][101][10001];
int cnt = 123456789;

int bfs(int x, int y, int n, int m)
{
    queue<pair<pair<int, int>,int>> q;
    q.push({ {x, y}, 0 });
    visit[x][y][0] = true;

    while (!q.empty())
    {
        int xx = q.front().first.first;
        int yy = q.front().first.second;
        int wall = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            int new_wall = wall;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (map[nx][ny] == 1) new_wall++; // 벽일때
            if (nx == n-1 && ny == m-1) cnt = min(cnt, wall); //도착했을때, 벽 부순 횟수의 최솟값
            if (!visit[nx][ny][new_wall] && new_wall <= 200) // 부순횟수는 200회를 넘을 수 없음, 이거없으면 시간초과
            {// 해당 위치에 해당 벽 부순 횟수로 도착한적 없을 시,
                q.push({ {nx, ny}, new_wall });
                visit[nx][ny][new_wall] = true;
            }
        }
    }
    return cnt;
}

int main()
{
    cin >> m >> n; // 가로세로 크기 잘읽기
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = s[j]-'0';
        }
    }
    if (n == 1 && m == 1) // 시작점이 도착지인 경우
    {
        if (map[0][0] == 0) cout << 0;
        else cout << 1;
    }
    else cout << bfs(0, 0, n, m);
    return 0;
}