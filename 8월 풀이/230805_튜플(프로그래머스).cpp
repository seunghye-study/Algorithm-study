#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}
vector<int> solution(string s) {
    vector<int> answer;
    int i = 0;
    vector<vector<int>> nn;
    while (true)
    {
        if (i >= s.length() - 2) break;
        vector<int> str;
        string temp;
        while (true)
        {
            if (s[i] == '}')
            {
                if (temp.length() != 0) str.push_back(stoi(temp));
                nn.push_back(str);
                i++;
                break;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                temp += s[i];
                i++;
            }
            else if (s[i] == ',')
            {
                if (temp.length() != 0) str.push_back(stoi(temp));
                temp = "";
                i++;
            }
            else i++;
        }
    }
    sort(nn.begin(), nn.end(), comp);
    vector<int> sett;
    for (int i = 0; i < nn.size(); i++)
    {
        for (int j = 0; j < nn[i].size(); j++)
        {
            if (i == 0) {
                sett.push_back(nn[i][j]);
                break;
            }
            else
            {
                if (find(sett.begin(), sett.end(), nn[i][j]) == sett.end())
                {
                    sett.push_back(nn[i][j]);
                    break;
                }
                else continue;
            }
        }
    }
    answer = sett;
    return answer;
}