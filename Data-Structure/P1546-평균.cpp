#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    int N;
    cin >> N;

    vector<double> scores(N);
    double max_score = 0.0;
    for (int i = 0; i < N; i++) {
        cin >> scores[i];
        if (scores[i] > max_score) max_score = scores[i];
    }

    double average = 0.0;
    for (int i = 0; i < N; i++)
        average += (scores[i] / max_score * 100);
    
    average /= static_cast<double>(N);

    cout << average;

    return 0;
}