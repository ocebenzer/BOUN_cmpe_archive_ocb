# -*- coding: utf-8 -*-
"""
Created on Mon Nov 25 16:38:05 2019

@author: luxuria
"""
import re


class matrix():
    def __init__(self, xp, yp):
        self.x = xp
        self.y = yp
        self.arr = []
        for i in range(xp):
            temp = []
            for j in range(yp):
                temp.append(-1)
            self.arr.append(temp)

    def initializer(self, o):
        for i in range(self.x):
            for j in range(self.y):
                self.arr[i][j] = o[i * self.y + j]

    def __add__(self, o):
        temp = matrix(self.x, self.y)
        for i in range(self.x):
            for j in range(self.y):
                temp.arr[i][j] = self.arr[i][j] + o.arr[i][j]
        return temp

    def __sub__(self, o):
        temp = matrix(self.x, self.y)
        for i in range(self.x):
            for j in range(self.y):
                temp.arr[i][j] = self.arr[i][j] - o.arr[i][j]
        return temp

    def __mul__(self, o):
        if isinstance(o, matrix):
            temp = matrix(self.x, o.y)
            for i in range(self.x):
                for j in range(o.y):
                    sum = 0
                    for k in range(self.y):
                        sum += self.arr[i][k] * o.arr[k][j]
                        temp.arr[i][j] = sum
            if self.x == 1 and o.y == 1:
                return temp.arr[0][0]
            else:
                return temp
        elif isinstance(o, int):
            value = o
            temp = matrix(self.x, self.y)
            for i in range(self.x):
                for j in range(self.y):
                    temp.arr[i][j] = value * self.arr[i][j]
            return temp

    def __rmul__(self, o):
        return self * o

    def tr(self):
        temp = matrix(self.y, self.x)
        for i in range(self.y):
            for j in range(self.x):
                temp[i][j] = self.arr[j][i]
        return temp

    def __repr__(self):
        temp = ""
        for i in range(self.x):
            for j in range(self.y):
                temp += str(self.arr[i][j]) + " "
            temp += "\n"
        return temp

    def __getitem__(self, key):
        if isinstance(key, int):
            return self.arr[key - 1][0]
        else:
            return self.arr[key[0] - 1][key[1] - 1]


f = open("example.mat")
execution = ""
vardict = {}


def choose(o1, o2, o3, o4):
    if o1 == 0:
        return o2
    elif o1 > 0:
        return o3
    else:
        return o4


def sqrt(o):
    return o ** (1 / 2)


for line in f:
    if not re.search("#", line):
        found = re.search("scalar\s+(\w)", line)
        if found:
            execution += "vardict[\"" + (found.group(1)) + "\"] = \"scalar\"\n"
        found = re.search("vector\s+(\w)\[(\d+)\]", line)
        if found:
            execution += "vardict[\"" + (found.group(1)) + "\"] = \"vector\"\n"
            execution += found.group(1) + " = matrix(" + found.group(2) + ",1)\n"
        found = re.search("matrix\s+(\w)\[(\d+),(\d+)\]", line)
        if found:
            execution += "vardict[\"" + (found.group(1)) + "\"] = \"matrix\"\n"
            execution += found.group(1) + " = matrix(" + found.group(2) + "," + found.group(3) + ")\n"
        found = re.search("(\w)+\s*=\s*(\d+)", line)
        if found:
            execution += found.group(1) + "=" + found.group(2) + "\n"
        found = re.search("(\w)+\s*=\s*", line)
        if found:
            print(found.group(0))
print(execution)
