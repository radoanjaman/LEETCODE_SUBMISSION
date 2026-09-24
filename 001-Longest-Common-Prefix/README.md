# Longest Common Prefix

**LeetCode:** 14
**Difficulty:** Easy
**Language:** C++

## Approach

The main idea is to compare the characters of all strings position by position and find the longest prefix that is common to every string.

### 1. Find the length of the shortest string

First, I find the length of the shortest string.

The common prefix cannot be longer than the shortest string, so this gives us the maximum number of characters that we need to check.

```cpp
int size = INT_MAX;

for(auto i : strs)
{
    size = min(size, (int)i.length());
}
```

For example:

```text
["flower", "flow", "flight"]
```

The shortest string is `"flow"`, whose length is `4`. Therefore, we only need to check the first 4 characters.


### 2. Take the first string as the reference

Next, I store the first string in a temporary string variable.

```cpp
string k = strs[0];
```

I use this string as the reference and compare its characters with the corresponding characters of all the other strings.

---

### 3. Compare characters position by position

Now, I compare each character of the first string with the character at the same position in every other string.

```cpp
for(int j = 0; j < size; j++)
{
    for(int i = 1; i < strs.size(); i++)
    {
        if(strs[i][j] != k[j])
        {
            return k.substr(0, j);
        }
    }
}
```

The outer loop selects the character position, while the inner loop checks that character against all the other strings.

For example:

```text
flower
flow
flight
```

Comparison:

```text
Position 0 → f = f = f ✓
Position 1 → l = l = l ✓
Position 2 → o = o ≠ i ✗
```

At position `2`, a mismatch is found.

Therefore, I return all characters before position `2`:

```cpp
k.substr(0, 2)
```

which gives:

```text
"fl"
```

---

### 4. If no mismatch is found

If the loops finish without finding any mismatch, it means that all characters up to the length of the shortest string are common to every string.

Therefore, I return the prefix of the first string up to `size`:

```cpp
return k.substr(0, size);
```

For example:

```text
["ab", "a"]
```

The shortest string has length `1`, and the first character is common to both strings.

Therefore, the result is:

```text
"a"
```

## Example

### Input

```text
["flower", "flow", "flight"]
```

### Output

```text
"fl"
```

## Complexity

Let:

* `n` = number of strings
* `m` = length of the shortest string

### Time Complexity

```text
O(n × m)
```

In the worst case, we compare `m` characters across all `n` strings.

### Space Complexity

```text
O(1)
```

No additional data structures are used apart from a few variables and the returned substring.
