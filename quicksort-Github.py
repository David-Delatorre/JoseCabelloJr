#!/usr/bin/env python
# coding=utf-8

def quicksort(items, p, r):
    if p < r:
        q = partition(items, p, r)
        quicksort(items, p, q-1)
        quicksort(items, q+1, r)

def partition(items, p, r):
    x = items[r]
    i = p-1
    for j in range(p, r):
        if items[j] <= x:
            i = i + 1
            # print(f"items[i]:  {items[i]} at index {i}")
            # print(f"items[j]:  {items[j]} at index {j}")
            # print(f"In for loop i is {i}")
            items[i],items[j] = items[j],items[i]
            # print(f"items[i]:  {items[i]} at index {i}")
            # print(f"items[j]:  {items[j]} at index {j}")
    # print(f"items[i+1]:  {items[i+1]} at index {i+1}")
    # print(f"items[r]:  {items[r]} at index {r}")
    # print(f"j is {j}")
    # print(f"Outside of loop i is {i}")
    items[i+1],items[r] = items[r],items[i+1]
    print(f"after swap\nitems[i+1]:  {items[i+1]} at index {i+1}")
    print(f"items[r]:  {items[r]} at index {r}")
    return i+1



items = [2,8,7,1,3,5,6,4]
quicksort(items, 0, len(items)-1)
print(items)