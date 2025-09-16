// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A)
{
    // Implement your solution here
    vector<int> counter(N, 0);
    int max_value{0}, length = A.size();
    for (int i = 0; i < length; ++i)
    {
        if (A[i] == N + 1)
        {
            fill(counter.begin(), counter.end(), max_value);
        }
        else
        {
            ++counter[A[i] - 1];
            max_value = max(max_value, counter[A[i] - 1]);
        }
    }
    return counter;
}

vector<int> solution(int N, vector<int> &A)
{
    // Implement your solution here
    vector<int> counter(N, 0);
    int max_to_set{}, max_value{0};
    for (int i : A)
    {
        if (i == N + 1)
        {
            max_to_set = max_value;
        }
        else
        {
            if (counter[i - 1] < max_to_set)
            {
                counter[i - 1] = max_to_set;
            }
            max_value = max(max_value, ++counter[i - 1]);
        }
    }
    for (int idx = 0; idx < N; ++idx)
    {
        if (counter[idx] < max_to_set)
        {
            counter[idx] = max_to_set;
        }
    }
    return counter;
}