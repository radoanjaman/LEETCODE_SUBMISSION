# Merge Sorted Array


## Problem

You are given two sorted arrays:

```text
A = [1, 2, 3, 0, 0, 0]
B = [2, 5, 6]
```

The first `m` elements of `A` contain valid values, while the remaining positions are empty (`0`) and are reserved for the elements of `B`.

```text
m = 3
n = 3
```

The goal is to merge `B` into `A` so that `A` becomes:

```text
[1, 2, 2, 3, 5, 6]
```

---

## Approach

Since both arrays are already **sorted**, we can merge them efficiently by starting from the **end** of both arrays.

Instead of starting from the beginning, we compare the largest elements first and place the larger element at the last available position of `A`.

For example:

```text
A = [1, 2, 3, 0, 0, 0]
B = [2, 5, 6]
```

The last valid element of `A` is:

```text
A[m - 1] = A[2] = 3
```

The last element of `B` is:

```text
B[n - 1] = B[2] = 6
```

We compare:

```text
3 vs 6
```

Since `6` is larger, we put `6` at the last position of `A`:

```text
A = [1, 2, 3, 0, 0, 6]
```

Then we move the pointer of `B` backward.

---

## Three Pointers

We use three pointers:

```cpp
int i = m - 1;
int j = n - 1;
int idx = m + n - 1;
```

### `i`

Points to the last valid element of `A`.

```cpp
i = m - 1;
```

For:

```text
A = [1, 2, 3, 0, 0, 0]
m = 3
```

we get:

```text
i = 2
```

So:

```text
A[i] = 3
```

---

### `j`

Points to the last element of `B`.

```cpp
j = n - 1;
```

For:

```text
B = [2, 5, 6]
n = 3
```

we get:

```text
j = 2
```

So:

```text
B[j] = 6
```

---

### `idx`

Points to the last position of `A` where we need to place an element.

```cpp
idx = m + n - 1;
```

For:

```text
m = 3
n = 3
```

we get:

```text
idx = 5
```

So the first element will be placed at:

```text
A[5]
```

---

## Main Logic

We compare:

```cpp
A[i]
```

and

```cpp
B[j]
```

If the element in `A` is larger:

```cpp
if(A[i] >= B[j])
```

we put `A[i]` at `A[idx]`:

```cpp
A[idx] = A[i];
```

Then move both pointers backward:

```cpp
idx--;
i--;
```

Otherwise, we put `B[j]` at `A[idx]`:

```cpp
A[idx] = B[j];
```

and move:

```cpp
idx--;
j--;
```

---

## Step-by-Step Example

Initial arrays:

```text
A = [1, 2, 3, 0, 0, 0]
B = [2, 5, 6]
```

Pointers:

```text
i = 2
j = 2
idx = 5
```

### Step 1

Compare:

```text
A[i] = 3
B[j] = 6
```

`6` is larger.

Place `6` at `A[5]`.

```text
A = [1, 2, 3, 0, 0, 6]
```

Move:

```text
j = 1
idx = 4
```

---

### Step 2

Compare:

```text
A[i] = 3
B[j] = 5
```

`5` is larger.

```text
A = [1, 2, 3, 0, 5, 6]
```

Move:

```text
j = 0
idx = 3
```

---

### Step 3

Compare:

```text
A[i] = 3
B[j] = 2
```

`3` is larger.

Put `3` at `A[3]`.

```text
A = [1, 2, 3, 3, 5, 6]
```

Move:

```text
i = 1
idx = 2
```

---

### Step 4

Compare:

```text
A[i] = 2
B[j] = 2
```

Since:

```cpp
A[i] >= B[j]
```

is true, we put `A[i]` into `A[idx]`.

```text
A = [1, 2, 2, 3, 5, 6]
```

Move:

```text
i = 0
idx = 1
```

---

### Step 5

Compare:

```text
A[i] = 1
B[j] = 2
```

`2` is larger.

```text
A = [1, 2, 2, 3, 5, 6]
```

Move:

```text
j = -1
idx = 0
```

Now `j < 0`, so all elements of `B` have been placed.

The final array is:

```text
[1, 2, 2, 3, 5, 6]
```

---

## Why Do We Start From the End?

This is the most important idea of the solution.

`A` already contains its own elements at the beginning:

```text
A = [1, 2, 3, 0, 0, 0]
```

The empty spaces are at the end.

If we started merging from the beginning, we could overwrite elements of `A` that we still need.

By starting from the end, we can safely place the largest elements into the empty positions.

For example:

```text
A = [1, 2, 3, 0, 0, 0]
                 ↑
               idx
```

The empty positions give us enough space to work backward without losing the original values.

---

## Handling Remaining Elements of B

After the main loop:

```cpp
while(i >= 0 && j >= 0)
```

it is possible that some elements of `B` are still left.

Therefore, we use:

```cpp
while(j >= 0)
{
    A[idx] = B[j];
    idx--;
    j--;
}
```

If elements of `A` remain, we don't need another loop for them.

Why?

Because if `B` is completely processed first, the remaining elements of `A` are already in their correct positions.

---

## Code

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {

        int i = m - 1;       // Last valid element of A
        int j = n - 1;       // Last element of B
        int idx = m + n - 1; // Last position of A

        while(i >= 0 && j >= 0)
        {
            if(A[i] >= B[j])
            {
                A[idx] = A[i];
                idx--;
                i--;
            }
            else
            {
                A[idx] = B[j];
                idx--;
                j--;
            }
        }

        while(j >= 0)
        {
            A[idx] = B[j];
            idx--;
            j--;
        }
    }
};
```

---

## Complexity

### Time Complexity

```text
O(m + n)
```

Each element is processed at most once.

### Space Complexity

```text
O(1)
```

We do not use any extra array or data structure. The merging is done **in-place** inside `A`.

---

## Key Idea

The main idea can be summarized as:

> **Compare the largest remaining elements of both sorted arrays and place the larger one at the last available position of `A`.**

```text
A → [1, 2, 3, 0, 0, 0]
          ↑
          i

B → [2, 5, 6]
          ↑
          j

idx → points to the last position of A
```

Then repeatedly:

```text
Compare A[i] and B[j]
        ↓
Take the larger element
        ↓
Put it at A[idx]
        ↓
Move the corresponding pointer backward
        ↓
Move idx backward
```

This allows us to merge the arrays **without using an extra array**.
