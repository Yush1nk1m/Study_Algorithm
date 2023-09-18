#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> table(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> sumTable(N + 1, vector<int>(N + 1, 0));
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> table[r][c];
            sumTable[r][c] = sumTable[r-1][c] + sumTable[r][c-1] - sumTable[r-1][c-1] + table[r][c];    // 부분 합 배열 공식
        }
    }

    for (int _ = 0; _ < M; _++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int partSum = sumTable[x2][y2] - sumTable[x2][y1-1] - sumTable[x1-1][y2] + sumTable[x1-1][y1-1]; // 부분 합 공식
        cout << partSum << '\n';
    }

    return 0;
}