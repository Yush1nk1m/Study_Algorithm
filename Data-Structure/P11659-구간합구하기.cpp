#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> numbers(N + 1, 0);              // 원시 배열
    vector<int> sums(N + 1, 0);                 // 합 배열

    for (int i = 1; i <= N; i++) {
        cin >> numbers[i];
        sums[i] = sums[i - 1] + numbers[i];     // 합 배열 공식
    }

    for (int _ = 0; _ < M; _++) {
        int i, j;
        cin >> i >> j;
        cout << sums[j] - sums[i - 1] << '\n';  // 구간 합 공식
    }

    return 0;
}