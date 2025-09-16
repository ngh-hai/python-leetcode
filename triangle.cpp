// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A)
{
    // Implement your solution here
    int N = A.size();
    sort(A.begin(), A.end());
    for (int i = 0; i < N - 2; ++i)
    {
        long long int left = (long long int)(A[i]) + (long long int)(A[i + 1]);
        if (left > (long long int)(A[i + 2]))
            return 1;
    }
    return 0;
}

/*
    watch out for input constraint, in this exercise, the range for an edge is INT_MIN to INT_MAX
    -> use long long int
    Python can easily solve this problem as well :)
*/