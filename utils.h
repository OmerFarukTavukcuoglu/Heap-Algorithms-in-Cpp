#pragma once

#include <vector>
#include <map>
#include "HeapType.h"
#include "Heap.h"

struct Node
{
    int val;
    int listIndex;
    int elementIndex;

    bool operator<=(const Node &other) const
    {
        return val <= other.val;
    }

    bool operator>=(const Node &other) const
    {
        return val >= other.val;
    }

    bool operator<(const Node &other) const
    {
        return val < other.val;
    }

    bool operator>(const Node &other) const
    {
        return val > other.val;
    }

    bool operator==(const Node &other) const
    {
        return val == other.val;
    }
};

template <typename T>
void heapSort(std::vector<T> &arr, HeapType heapType);
std::vector<int> mergeSortedLists(std::vector<std::vector<int>> &lists);
std::vector<int> slidingWindowMax(std::vector<int> &nums, int k);
