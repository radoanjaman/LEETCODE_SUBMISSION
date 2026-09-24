# Remove Duplicates from Sorted Array

**LeetCode:** [26 — Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
**Difficulty:** Easy
**Language:** C++

## Approach

The main idea is to remove duplicate elements from the array and keep only one occurrence of each element.

### 1. Sort the array

First, I sort the array using `sort()`:

```cpp
sort(nums.begin(), nums.end());
```

This makes all duplicate elements come next to each other.

For example:

```text
Before sorting:
0 1 0 2 1 3 2

After sorting:
0 0 1 1 2 2 3
```

### 2. Create a temporary vector

I create a temporary vector to store the unique elements:

```cpp
vector<int> temp;
```

### 3. Compare each element with the next element

I loop through the array and compare `nums[i]` with `nums[i + 1]`.

```cpp
for(int i = 0; i < nums.size() - 1; i++)
{
    if(nums[i] != nums[i + 1])
    {
        temp.push_back(nums[i]);
    }
}
```

If the current element is different from the next element, it means the current element is the **last occurrence of that value**, so I add it to `temp`.

For example:

```text
0 0 1 1 1 2 2 3 3 4
    ↑
```

When `0 != 1`, I add `0`.

Similarly:

```text
0 0 1 1 1 2 2 3 3 4
          ↑
```

When `1 != 2`, I add `1`.

This continues until the second-last element.

### 4. Add the last element

The last element cannot be compared with a next element, so I add it separately:

```cpp
temp.push_back(nums[nums.size() - 1]);
```

For example:

```text
0 0 1 1 1 2 2 3 3 4
                  ↑

Last element = 4
```

So the temporary vector becomes:

```text
0 1 2 3 4
```

### 5. Replace the original vector

Finally, I replace `nums` with the temporary vector:

```cpp
nums = temp;
```

Then I return the number of unique elements:

```cpp
return temp.size();
```


## Example

### Input

```text
0 0 1 1 1 2 2 3 3 4
```

### Output

```text
5
0 1 2 3 4
```

## Complexity

* **Time Complexity:** `O(n log n)` because of sorting.
* **Space Complexity:** `O(n)` because of the temporary vector.

## Key Learning

The main idea I used is:

> **After sorting, duplicate elements are adjacent, so I can compare each element with the next one and store only the elements that are different from the next element.**
