// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int K, vector<int> &A)
{
    // Implement your solution here
    int N = A.size();
    if (N == 1)
        return A[0] < K ? 0 : 1;
    int idx{}, result{};
    long long int current_length{};
    while (idx < N)
    {
        long long int x{current_length + A[idx]};
        if (x >= K)
        {
            ++result;
            current_length = 0;
        }
        else
        {
            current_length = x;
        }
        ++idx;
    }
    return result;
}

/*
https://app.codility.com/demo/results/trainingMWVTFQ-VK2/
*/