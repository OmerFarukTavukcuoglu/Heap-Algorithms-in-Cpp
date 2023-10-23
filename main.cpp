#include <iostream>
#include "Heap.cpp"
#include "utils.cpp"

int main()
{
    // Example 1: Heap Sort
    std::cout << "Example 1: Heap Sort" << std::endl;

    std::vector<int> arr{10, 20, 15, 17, 9, 21};
    std::cout << "Before: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }

    heapSort(arr, HeapType::MAX_HEAP);

    std::cout << std::endl
              << "After: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl
              << std::endl;

    // Example 2: Merge Sorted Lists
    std::cout << "Example 2: Merge Sorted Lists" << std::endl;

    std::vector<std::vector<int>> lists{{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    std::cout << "Before: ";
    for (const auto &list : lists)
    {
        for (int num : list)
        {
            std::cout << num << " ";
        }
        std::cout << "| ";
    }

    std::vector<int> mergedList = mergeSortedLists(lists);

    std::cout << std::endl
              << "After: ";
    for (int num : mergedList)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl
              << std::endl;

    // Example 3: Sliding Window Maximum
    std::cout << "Example 3: Sliding Window Maximum" << std::endl;

    std::vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    std::cout << "Before: ";
    for (int num : nums)
    {
        std::cout << num << " ";
    }

    std::vector<int> maxElements = slidingWindowMax(nums, k);

    std::cout << std::endl
              << "After: ";
    for (int num : maxElements)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
