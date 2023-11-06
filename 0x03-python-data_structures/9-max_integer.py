#!/usr/bin/python3
def max_integer(my_list=[]):
    if len(my_list) < 1:
        return None
    else:
        new_list = my_list.copy()
        new_list.sort()
        return new_list[-1]
