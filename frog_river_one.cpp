// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, vector<int> &A)
{
    // Implement your solution here
    vector<int> x(X + 1, -1); // x saves the earliest time when the leave appear
    for (int idx = 0; idx < A.size(); ++idx)
    {
        if (x[A[idx]] == -1)
        {
            x[A[idx]] = idx;
        }
        else
        {
            x[A[idx]] = min(x[A[idx]], idx);
        }
    }
    int result{-1};
    for (int i = 1; i <= X; ++i)
    {
        if (x[i] == -1)
            return -1;
        result = max(result, x[i]);
    }
    return result;
}