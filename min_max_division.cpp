// you can use includes, for example:
#include <algorithm>
#include <numeric>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int K, int M, vector<int> &A)
{
    // Implement your solution here
    int N = A.size();
    int high{accumulate(A.begin(), A.end(), 0)}, low{*(max_element(A.begin(), A.end()))};
    int result{};
    while (low <= high)
    {
        int mid{(high - low) / 2 + low};
        // check starts here
        int current_sum{}, block_count{1};
        for (int i = 0; i < N; ++i)
        {
            current_sum += A[i];
            if (current_sum > mid)
            {
                current_sum -= A[i];
                ++block_count;
                current_sum = A[i];
            }
        }
        if (block_count <= K)
        {
            high = mid - 1;
            result = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

/*
    https://app.codility.com/demo/results/trainingGSHSKY-AMB/
    Idea:
    - among all the blocks, the max sum (of all blocks) will be at least the largest element
    in the array, and will be at most the sum of all elements in array
    - proof: the largest element will be in at least 1 block, no matter how we divide the array
    - the "minimum" of this max will be in this range -> binary search
    - for each candidate "middle" value, check if it is possible to divide the array into blocks,
    and sum of all elements in each block does NOT exceed "middle"
    - note: at this point, we only say does NOT exceed -> a possible large sum. the real "minimum" large sum
    does not exceed this possible value. however, just update the answer to this possible value
    - if the large sum is possible, narrow down the search range to smaller half, otherwise, proceed with larger half
    - later, when low == high, this is the moment that the real "minimum" large sum shows up
*/