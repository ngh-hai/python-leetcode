// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A)
{
    // Implement your solution here
    int N = A.size();
    vector<int> suffix_sum(N + 1, 0);
    // for (int i = 1; i <= N; ++i){
    //     prefix_sum[i] = prefix_sum[i - 1] + A[i - 1];
    // }
    for (int i = N - 1; i >= 0; --i)
    {
        suffix_sum[i] = suffix_sum[i + 1] + A[i];
    }
    int result{};
    for (int i = 0; i < N; ++i)
    {
        if (A[i] == 0)
        {
            result += suffix_sum[i];
        }
        if (result > 1000000000)
        {
            return -1;
        }
    }
    return result;
}
