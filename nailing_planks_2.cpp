// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool check(vector<int> &A, vector<int> &B, vector<int> &C)
{
    sort(C.begin(), C.end());
    int N = A.size();
    for (int i = 0; i < N; ++i)
    {
        auto x = lower_bound(C.begin(), C.end(), A[i]);
        if (x == C.end() || (int)(*x) > B[i])
        {
            return false;
        }
    }
    return true;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C)
{
    // Implement your solution here
    int N = A.size(), M = C.size();
    int low{1}, high{M};
    int result{-1};
    while (low <= high)
    {
        int mid{(high - low) / 2 + low};
        vector<int> C_selected(C.begin(), C.begin() + mid);
        if (check(A, B, C_selected))
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

int main()
{
    vector<int> A{1, 4, 5, 8};
    vector<int> B{4, 5, 9, 10};
    vector<int> C{4, 6, 7, 10, 2};
    cout << solution(A, B, C);
    return 0;
}


/*
https://app.codility.com/demo/results/trainingVSUMVT-CG6/
*/