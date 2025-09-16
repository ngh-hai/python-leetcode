// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
    // Implement your solution here
    int N = S.size(), M = P.size();
    vector<int> ans(M);
    for (int idx = 0; idx < M; ++idx)
    {
        int result{5};
        for (int j = P[idx]; j <= Q[idx]; ++j)
        {
            switch (S[j])
            {
            case 'A':
            {
                result = min(result, 1);
                break;
            }
            case 'C':
            {
                result = min(result, 2);
                break;
            }
            case 'G':
            {
                result = min(result, 3);
                break;
            }
            case 'T':
            {
                result = min(result, 4);
                break;
            }
            }
        }
        ans[idx] = result;
    }
    return ans;
}

/*
    the idea:
    - if 'A' exist, then no matter the other letters, the answer is 1
    - if 'A' not exist, then does 'C' exist?....

    - if 'A' exist ==> how many 'A' are there in sequence? is this > 0?
    - how many 'A' are there in sequence? -> prefix sum, counting 'A' in all position
*/

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q)
{
    // Implement your solution here
    int N = S.size(), M = P.size();
    vector<int> ans(M);

    vector<int> count_A(N + 1, 0);
    vector<int> count_C(N + 1, 0);
    vector<int> count_G(N + 1, 0);
    // vector<int> count_T(N + 1, 0);

    for (int i = 1; i <= N; ++i)
    {
        count_A[i] = count_A[i - 1] + (S[i - 1] == 'A' ? 1 : 0);
        count_C[i] = count_C[i - 1] + (S[i - 1] == 'C' ? 1 : 0);
        count_G[i] = count_G[i - 1] + (S[i - 1] == 'G' ? 1 : 0);
        // count_T[i] = count_T[i - 1] + (S[i - 1] == 'T' ? 1 : 0);
    }
    for (int i = 0; i < M; ++i)
    {
        if (count_A[Q[i] + 1] - count_A[P[i]] > 0)
            ans[i] = 1;
        else if (count_C[Q[i] + 1] - count_C[P[i]] > 0)
            ans[i] = 2;
        else if (count_G[Q[i] + 1] - count_G[P[i]] > 0)
            ans[i] = 3;
        else
            ans[i] = 4;
    }
    return ans;
}
