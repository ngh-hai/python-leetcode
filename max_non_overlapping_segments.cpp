// you can use includes, for example:
#include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B)
{
    // Implement your solution here
    int N = A.size(), idx{1}, last{}, result{1};
    if (N == 0)
        return 0;
    while (idx < N)
    {
        if (A[idx] > B[last])
        {
            last = idx;
            ++result;
        }
        ++idx;
    }
    return result;
}

/*
https://app.codility.com/demo/results/training43YF7S-525/
*/