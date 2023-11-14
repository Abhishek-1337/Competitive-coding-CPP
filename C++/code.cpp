#include <bits/stdc++.h>
#include <string>
using namespace std;

// int ArrayChallenge(int arr[], int arrLength)
// {

// }

int main(void)
{

    // keep this function call here
    int arr[] = {2, 3, 5, 6, 1};
    int arrLength = sizeof(arr) / sizeof(*arr);
    int maxEl = -1, maxIdx = -1;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] > maxEl)
        {
            maxEl = arr[i];
            maxIdx = i;
        }
    }
    queue<pair<int, int>> q;
    vector<int> visited(arrLength, -1);
    int nextf = (maxIdx + arr[maxIdx]) % arrLength;
    int nextb = (maxIdx - arr[maxIdx] + arrLength) % arrLength;
    q.push(make_pair(nextf, 1));
    q.push(make_pair(nextb, 1));
    visited[nextf] = 1;
    visited[nextb] = 1;
    int ans = -1;
    while(true){
        pair<int, int> temp = q.front();
        q.pop();
        if(temp.first == maxIdx){
            ans = temp.second;
            break;
        }
        int f = (temp.first + arr[temp.first]) % arrLength;
        int b = (temp.first - arr[temp.first] + arrLength) % arrLength; 
        // cout << 'f' << f << " " << b << endl;
        if(visited[f] == -1){
            visited[f] = 1;
            q.push(make_pair(f, temp.second + 1));
        }
        
        if(visited[b] == -1){
            visited[b] = 1;
            q.push(make_pair(b, temp.second + 1));
        }
    }
    cout << "ans " << ans << endl;
    return ans;
}