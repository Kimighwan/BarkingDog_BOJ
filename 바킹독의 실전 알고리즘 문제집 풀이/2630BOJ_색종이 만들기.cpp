#include <iostream>
using namespace std;

int map[128][128];
int ans[2];

bool Check(int n, int x, int y) {
    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            if (map[i][j] != map[x][y]) return false;
    return true;
}

void Solve(int n, int x, int y) {
    if (Check(n, x, y)) {
        ans[map[x][y]]++;
        return;
    }

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) 
            Solve(n / 2, x + i * n / 2, y + j * n / 2);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            cin >> map[i][j];

    Solve(n, 0, 0);

    for (int i = 0; i < 2; i++) cout << ans[i] << '\n';
}