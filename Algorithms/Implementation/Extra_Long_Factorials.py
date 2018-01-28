#!/bin/python3

import sys


n = int(input().strip())
sum = 1;
for i in range(0,n):
    sum*=(n - i)
print(sum)
