// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
int solution(vector<int> &A, vector<int> &B, vector<int> &C)
{
    // Implement your solution here
    int N = A.size(), M = C.size();
    vector<int> has_removed(N, 0);
    int result{};
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (has_removed[j] == 0)
            {
                if (C[i] >= A[j] && C[i] <= B[j])
                {
                    has_removed[j] = 1;
                }
            }
        }
        ++result;
        if (std::accumulate(has_removed.begin(), has_removed.end(), 0) == N)
            return result;
    }
    return -1;
}

int main()
{
    vector<int> A{1, 4, 5, 8};
    vector<int> B{4, 5, 9, 10};
    vector<int> C{4, 6, 7, 10, 2};
    cout << solution(A, B, C);
    return 0;
}
