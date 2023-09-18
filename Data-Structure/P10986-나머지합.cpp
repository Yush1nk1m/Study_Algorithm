#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    long long result = 0;

    vector<long long> sums(N, 0);               // 구간 합 배열
    vector<long long> divisors(M, 0);           // M으로 나누었을 때의 나머지가 인덱스가 되는 배열, 해당 나머지의 개수를 저장한다.

    cin >> sums[0];
    for (int i = 1; i < N; i++) {
        cin >> sums[i];
        sums[i] += sums[i - 1];
    }

    for (int i = 0; i < N; i++) {
        int remainder = sums[i] % M;            // M으로 나눈 나머지를 저장한 후 활용
        
        if (remainder == 0)                     // 만약 M으로 나눈 나머지가 0이라면
            result++;                           // 0 ~ i까지의 합은 M으로 나누어 떨어진다는 의미이므로 즉시 결과에 더한다.
        
        divisors[remainder]++;                  // M으로 나눈 나머지가 remainder인 경우의 수를 1 증가한다.
    }

    for (int i = 0; i < M; i++)
        if (divisors[i] >= 2)   // 경우의 수가 2개 이상이어야 경우의 수들 중 2개를 선택할 수 있다.
            result += (divisors[i] * (divisors[i] - 1) / 2);    // M으로 나누었을 때 i가 남는 수의 개수가 n개라면, nC2를 계산하여 결과에 반영한다.
            // nC2를 계산하는 이유: 구간 합 배열이므로 나머지가 같은 인덱스 i, j(i < j)를 추출하였을 때 arr[j] - arr[i]가 i + 1 ~ j의 구간 합이 된다.

    cout << result;

    return 0;
}