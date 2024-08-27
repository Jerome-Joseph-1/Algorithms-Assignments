## Problem Statement

You are given an array `daysToBloom` of size `n`, where `daysToBloom[i]` represents the day on which flower `i` will bloom. You are also given two integers, `k` and `m`. 

- `k` is the minimum number of adjacent blooming flowers required to form a bouquet.
- `m` is the number of bouquets needed.

Your task is to determine the earliest day on which it is possible to form at least `m` bouquets of flowers, with each bouquet consisting of exactly `k` adjacent blooming flowers. If it's not possible to form the required number of bouquets, return `-1`.

### Input

- The first line contains a single integer `T` — the number of test cases.
- For each test case:
  - The first line contains three integers `n`, `k`, and `m` — the number of flowers, the number of adjacent flowers required to form a bouquet, and the number of bouquets needed, respectively.
  - The second line contains `n` integers, where the `i-th` integer represents `daysToBloom[i]` — the day on which flower `i` will bloom.

### Output

For each test case, output a single integer — the earliest day on which it is possible to form at least `m` bouquets. If it is not possible to form the required number of bouquets, output `-1`.

### Constraints

- `1 <= T <= 100`
- `1 <= n <= 100,000`
- `1 <= daysToBloom[i] <= 10^9`
- `1 <= k <= n`
- `1 <= m <= n / k`

### Example

**Input:**

```
1
7 2 2
1 2 4 9 3 4 1
```

**Output:**

```
4
```

### Explanation

In the example above, there are 7 flowers with their blooming days given by `daysToBloom = [1, 2, 4, 9, 3, 4, 1]`. To form a bouquet, we need at least `2` adjacent flowers (`k = 2`), and we need to form `2` bouquets (`m = 2`). The earliest day on which we can form these bouquets is day `4`.
