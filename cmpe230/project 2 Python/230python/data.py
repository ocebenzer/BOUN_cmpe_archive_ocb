from variable import *
import re


def fill(variable, listStr):
    list = []
    for e in listStr:
        list.append(int(e))
    if isinstance(variable, scalar):
        if len(list) != 1:
            pass  # Error variable size do not match
        variable.value = [list[0]]
    elif isinstance(variable, vector):
        if len(list) != variable.size:
            pass  # Error variable size do not match
        for e in list:
            variable.value.append(e)
    elif isinstance(variable, matrix):
        if len(list) != variable.size[0] * variable.size[1]:
            pass  # Error variable size do not match
        for i in range(variable.size[1]):
            variable.value.append(list[i * variable.size[0]:(i + 1) * variable.size[0]])
    else:  # Error no variable named such
        pass
    return


def myprint(variable, index=-1):
    if index == -1:
        for i in variable.value:
            if isinstance(i, int):
                print i
            else:
                for j in i:
                    print j
    else:
        if isinstance(variable.value[index], int):
            print variable.value[index]
        else:
            for i in variable.value[index]:
                if isinstance(i, list):
                    for j in i:
                        print j
                else:  # i is int
                    print i
