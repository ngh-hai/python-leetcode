// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <limits>

int solution(vector<int> &A)
{
    // Implement your solution here
    int N = A.size();
    vector<int> prefix_sum(N + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        prefix_sum[i] = prefix_sum[i - 1] + A[i - 1];
    }
    double min_avg{numeric_limits<double>::max()}, result_idx{};
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            double avg = (double)(prefix_sum[j + 1] - prefix_sum[i]) / (double)(j - i + 1);
            if (avg < min_avg)
            {
                min_avg = avg;
                result_idx = i;
                break;
            }
        }
    }
    return result_idx; // O(N^2)
}

/*
    Idea:
    we don't need to check any slice has length longer than 3 elements.
    Prove by contradiction:
    - let's say we have a slice of length 4, avg is x.
    -> we can split into 2 slices of length 2.
    - if these 2 slices have avg greater x, then the avg of original slice is greater then x (contradict!)
    -> must exist 1 slice has avg smaller than x

    Apply this recursively to any slice has length greater then 3, we will eventually looking into slice of length 2 and 3.
*/

#include <limits>

int solution(vector<int> &A)
{
    // Implement your solution here
    double min_avg{numeric_limits<double>::max()};
    int result_idx{};
    int N = A.size();
    for (int i = 0; i < N - 1; ++i)
    {
        double tmp = (double)(A[i] + A[i + 1]) / 2.0;
        if (tmp < min_avg)
        {
            min_avg = tmp;
            result_idx = i;
            continue;
        }
        else if (i < N - 2)
        {
            tmp = (double)(A[i] + A[i + 1] + A[i + 2]) / 3.0;
            if (tmp < min_avg)
            {
                min_avg = tmp;
                result_idx = i;
            }
        }
    }
    return result_idx;
}