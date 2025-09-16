# WRITE THE FUNCTION HERE #
#                         #
#                         #
#                         #
#                         #
###########################
def first_non_repeating_char(s):
    items = {}
    for i in s:
        if items.get(i) is None:
            items[i] = 1
        else:
            items[i] += 1
    for i in items:
        if items[i] == 1:
            return i
    return None


print( first_non_repeating_char('leetcode') )

print( first_non_repeating_char('hello') )

print( first_non_repeating_char('aabbcc') )



"""
    EXPECTED OUTPUT:
    ----------------
    l
    h
    None

"""