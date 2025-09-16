# WRITE ITEM_IN_COMMON FUNCTION HERE #
#                                    #
#                                    #
#                                    #
#                                    #
######################################
def item_in_common(list1, list2):
    items = {}
    for i in list1:
        items[i] = True
    for j in list2:
        if j in items:
            return True
    return False



list1 = [1,3,5]
list2 = [2,4,5]


print(item_in_common(list1, list2))



"""
    EXPECTED OUTPUT:
    ----------------
    True

"""