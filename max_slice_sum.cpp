// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A)
{
    // Implement your solution here
    long long int max_sum{numeric_limits<long long int>::min()}, max_ending{};
    for (int x : A)
    {
        max_ending = max(x, max_ending + x);
        // if max_ending + x is larger, then extend the current slice to x
        // else, start new slice from x
        max_sum = max(max_sum, max_ending);
    }
    return max_sum;
}

/*
    Idea:
    - find the largest sum of any slice that ending at a position
    - among all the largest slice sum that we found at all position, select the max

    Kadane's algorithm finds the maximum sum of a contiguous subarray by iterating through the array once.
    It maintains a max_ending sum, which tracks the largest sum of a slice ending at the current position.
    The overall max_sum is then updated by comparing it with the current max_ending to ensure the final result is the greatest sum found anywhere in the array.
*/