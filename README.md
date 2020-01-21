# Count Co-Prime Numbers
Sensei will be adding to or removing numbers (`x`) from a set. 2 numbers in the set are a co-prime pair if and only if `gcd(a, b) = 1`. As Sensei add or remove numbers from the set, the number of co-prime pairs in the set changes. You are to inform him the latest number of co-prime pairs as that happens.

gcd stands for "greatest common denominator", which is also known as HCF (highest common factor).

## Inputs
The first line consists of 1 integer `N`.<br>
The next `N` lines each contains 2 numbers, each describing an operation in the form of 1 of the following:
* `1 x` : Sensei is inserting `x` to the set
* `2 x` : Sensei is removing `x` from the set (it is guaranteed that x exists in the set)

## Outputs
Your output should consist of `N` lines, each line containing the number of pairs of co-prime numbers in the set.

## Sample Tests
### Input 1
```7
1 1
1 2
1 3
1 5
2 3
1 8
2 8
```
### Output 1
```0
1
3
6
3
5
3
```
## Subtasks
For all cases:<br>
1 <= N <= 50000, 1 <= x <= 50000<br>

\# | Points | Constraints
--- | --- | ---
1 | 20 | N <= 100
2 | 20 | `x`'s are all prime numbers
3 | 30 | `x`'s are all powers of prime numbers
4 | 30 | no additional constraint
