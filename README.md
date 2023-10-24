- Stack Sort
Used the provided Heap class to implement the heap sort algorithm for an array of integers.
The heap sort algorithm must support both ascending and descending order (support both minimum and maximum heaps).
Adapted this into a heapSort function.

- Combining K Sorted Lists
Suppose there is an ordered list of k integers. these lists
used Heap class to combine into a single sorted list. Implemented this in the mergeSortedLists function.

- Maximum Sliding Window
Given an array of integers and an integer k, each of size k
It finds the maximum element in the contiguous subarray. Heap class
was used and this was implemented with a slidingWindowMax function.

- Stack Down
The provided heapifyDown function in the Heap class moves an element down the stack.
It is used to maintain the stack feature while moving. An index as input
and compares the element at this index with its left and right children. 
Depending on the stack type (max stack or minimum stack), it determines the index of 
the top element between the current index and its children. If the parent is not in the 
current directory, the function replaces the elements and recursively calls heapifyDown 
on the new parent directory. This process continues until the item reaches the correct 
position in the stack.
