# COP4533-GreedyAlgorithms

**Students:**

Heiryn Hernandez Rojas - 90988659

Maite Chapartegui - 54536135

## Files
Within src folder:
* `cache.cpp` - has the cache struct with policy functions that you call in main.
* `policies.cpp` - holds the main function, input and output and runs all of the policy functions

Within data folder:
* `examplen.txt`: Different input files with a variety of input numbers and capacities
* `examplen.out`: the output with the misses for each function

## Compilation
Our program is written in C++
To compile the code,

1. Clone the repo on your device:
* git clone https://github.com/heirynhr/COP4533-GreedyAlgorithms.git

2. Compile in VSCode (or IDE of your choosing) terminal
* g++ -std=c++17 ./src/policies.cpp -o policies
* ./policies ./data/example2.in
- to change input file, just edit the path in the second command

### Our assumptions:
- Assumed the input file format does not differ from the one that was given
- Assumed a cache must have a capacity of at least 1
- Assumed cache size is small enough to deal with the vectors, does not exceed the vector
## Written Component

### Question 1: Empirical Comparison

| Input File | k  | m  | FIFO | LRU | OPTFF |
|------------|----|----|------|-----|-------|
| File 3     | 4  | 55 | 55   | 55  | 17    |
| File 4     | 10 | 60 | 30   | 30  | 20    |
| File 5     | 8  | 70 | 56   | 59  | 33    |

**Does OPTFF have the fewest misses?**

Yes, OPTFF has the fewest number of misses in all the test cases. This makes sense because OPTFF reads the request sequence prior to doing any actions. It is an offline algorithm, while FIFO and LRU are online algorithms, meaning they process requests as they come in with no knowledge of future impact.

**How does FIFO compare to LRU?**

FIFO and LRU have the same amount of misses in the first two cases. This happened because the sequences in File 1 and File 2 were either short or cyclic with no strongly repeated items. In the third example, FIFO had fewer misses than LRU. This difference shows that neither algorithm is more optimal than the other in all cases. However, there is a pattern that can be observed. When a request sequence contains bursts of unique items that flush the cache regardless of policy, LRU can leave the cache in a worse state than FIFO's simpler approach. The best algorithm depends entirely on the access pattern of the specific request sequence.

---

### Question 2: Bad Sequence for LRU or FIFO

**Sequence:** `k = 3`, requests = `5 1 2 5 8 1 9 5 1 4`

| Policy | Misses |
|--------|--------|
| FIFO   | 8      |
| LRU    | 8      |
| OPTFF  | 6      |


In this example, OPTFF incurs strictly fewer misses than LRU. The difference comes down to the eviction decision at step i=4. At that point both policies have {5, 1, 2} in cache and item 8 causes both to get a miss. OPTFF's decision to evict item 2 at i=4 was optimal because item 2 was the only item in cache that would never be needed again. LRU had no way to know this and LRU only knew item 5 was least recently used. This shows why OPTFF is optimal because by knowing the full future sequence it avoids evicting items that are needed soon, which transfers into fewer misses throughout the rest of the sequence.

---

### Question 3: Prove OPTFF is Optimal

**Theorem:** OPTFF is optimal.

**Proof by contradiction:**

Assume otherwise, that there exists an optimal solution A, such that A has fewer misses than OPTFF.
Since they differ, they disagree at some step. At step t, both algorithms get a miss. OPTFF evicts item i, the item with the farthest next use and A evicts item j. OPTFF chose item i by the farthest-next-use rule, showing that j is needed no later than i.

Now apply the exchange argument.  Construct an algorithm A’ identical to A, but at step t it evicts i instead of j. After the exchange, A’ holds j in the cache instead of i. Since j is needed no later in the future than i, when j is requested next A’ will have a hit where A will have a miss. So, the exchange does not increase the miss count. 

After the exchange, A' now agrees with OPTFF at step t. Applying this exchange recursively to every step where A' and OPTFF still disagree, A is transformed into OPTFF. This contradicts our assumption that A has strictly fewer misses than OPTFF. Therefore our assumption was wrong, and OPTFF is optimal among all offline algorithms.


