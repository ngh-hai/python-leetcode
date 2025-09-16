# WRITE GROUP_ANAGRAMS FUNCTION HERE #
#                                    #
#                                    #
#                                    #
#                                    #
######################################
def __hash(string):
    result = 0
    for i in string:
        result += ord(i)
    return result
    
def match(s1, s2):
    chars = {}
    for i in s1:
        if chars.get(i) is None:
            chars[i] = 1
        else:
            chars[i] += 1
    for j in s2:
        if chars.get(j) is None:
            return False
        else:
            chars[j] -= 1
    for i in chars:
        if chars[i] != 0:
            return False
    return True


def group_anagrams(strings):
    items = {}
    for string in strings:
        idx = __hash(string)
        if items.get(idx) is None:
            items[idx] = []
            items[idx].append([string])
        else:
            matched = False
            for i in items[idx]:
                if match(i[0], string):
                    i.append(string)
                    matched = True
                    break
            if not matched:
                items[idx].append([string])
    result = []
    for i in items:
        for j in items[i]:
            result.append(j)
    return result            



print("1st set:")
print( group_anagrams(["eat", "tea", "tan", "ate", "nat", "bat"]) )

print("\n2nd set:")
print( group_anagrams(["abc", "cba", "bac", "foo", "bar"]) )

print("\n3rd set:")
print( group_anagrams(["listen", "silent", "triangle", "integral", "garden", "ranged"]) )



"""
    EXPECTED OUTPUT:
    ----------------
    1st set:
    [['eat', 'tea', 'ate'], ['tan', 'nat'], ['bat']]

    2nd set:
    [['abc', 'cba', 'bac'], ['foo'], ['bar']]

    3rd set:
    [['listen', 'silent'], ['triangle', 'integral'], ['garden', 'ranged']]

"""


### Solution from author with comments
def group_anagrams(strings):
    # create an empty hash table
    anagram_groups = {}
 
    # iterate through each string in the array
    for string in strings:
        # sort each string to get its canonical form
        # sorted('eat') returns ['a', 'e', 't']
        # ''.join(['a', 'e', 't']) coverts the array of chars to 'aet' string
        canonical = ''.join(sorted(string))
 
        # check to see if the canonical form of the string exists in the hash table
        if canonical in anagram_groups:
            # if it does then add the string there
            anagram_groups[canonical].append(string)
        else:
            # otherwise create new canonical form and add the string there
            anagram_groups[canonical] = [string]
 
    # convert the hash table to a list of lists
    return list(anagram_groups.values())