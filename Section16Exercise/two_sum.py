# WRITE TWO_SUM FUNCTION HERE #
#                             #
#                             #
#                             #
#                             #
###############################
def two_sum(nums, target):
    items = {}
    for idx in range(len(nums)):
        if items.get(nums[idx]) is None:
            items[nums[idx]] = []
        items[nums[idx]].append(idx)
    for i in items:
        if target - i == i:
            if len(items[i]) >= 2:
                return [items[i][0], items[target - i][1]]
        elif items.get(target - i) is not None:
            return [items[i][0], items[target - i][0]]
        
    
    return []
    
    
print(two_sum([5, 1, 7, 2, 9, 3], 10))  
print(two_sum([4, 2, 11, 7, 6, 3], 9))  
print(two_sum([10, 15, 5, 2, 8, 1, 7], 12))  
print(two_sum([1, 3, 5, 7, 9], 10))  
print ( two_sum([1, 2, 3, 4, 5], 10) )
print ( two_sum([1, 2, 3, 4, 5], 7) )
print ( two_sum([1, 2, 3, 4, 5], 3) )
print ( two_sum([], 0) )



"""
    EXPECTED OUTPUT:
    ----------------
    [1, 4]
    [1, 3]
    [0, 3]
    [1, 3]
    []
    [2, 3]
    [0, 1]
    []

"""


### Solution from author

def two_sum(nums, target):
    # create an empty hash table
    num_map = {}
 
    # iterate through each number in the array
    for i, num in enumerate(nums):
        # calculate the complement of the current number
        complement = target - num
 
        # check if the complement is in the hash table
        if complement in num_map:
            # if it is, return the indices of the two numbers
            return [num_map[complement], i]
 
        # add the current number and its index to the hash table
        num_map[num] = i
 
    # if no two numbers add up to the target, return an empty list
    return []