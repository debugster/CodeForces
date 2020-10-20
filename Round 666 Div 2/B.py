#	Author	: debugster
#	Email	: alive.dew@gmail.com
#	Date	: 2020-08-31 15:05:42

import sys
import os

def get_int():
    return map(int, input().split())

def get_array():
    return list(map(int, input().split()))

def array_1D(length, value = 0):
    data = [value for _ in range(length)]
    return data

def array_2D(row, col, value = 0):
    data = [[value for c in range(col)] for r in range(row)]
    return data

def vector_2D(nodes):
    data = dict()
    for n in range(nodes):
        data[n] = list()
    
    return data

def str_replacer(old_str, new_str, index):
    if index in range(len(old_str)):
        return old_str[:index] + new_str + old_str[index + 1:]
    else:
        return old_str

if os.environ.get("DEBUGSTER_PYTHON"):
    sys.stdin = open('in.txt', 'r')
    sys.stdout = open('out.txt','w')

n = int(input())
num = get_array()
num.sort()
limit = num[n - 1] ** (1 / float(n - 1))
limit = int(limit + 1)
ans = 10000000000000000000

for c in range(1, limit + 1):
    cnt = 0
    for i in range(n):
        cnt += abs(num[i] - c ** i)
    #print(c, cnt)
    ans = min(ans, cnt)

print(ans)