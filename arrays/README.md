# Arrays

## Overview
Arrays are fundamental data structures that store elements in contiguous memory locations. They provide constant-time access to elements by index but have fixed size in most programming languages.

## Key Concepts
- **Index-based access**: O(1) time complexity
- **Insertion/Deletion**: O(n) time complexity (worst case)
- **Memory allocation**: Contiguous memory blocks
- **Cache-friendly**: Good spatial locality

## Beginner Problems ⭐
Perfect for coding interview preparation and learning fundamentals.

### 1. Two Sum
**Problem**: Find two numbers in array that add up to target sum.
- **Approach**: HashMap for O(n) solution vs O(n²) brute force
- **Key Learning**: Hash table optimization, space-time tradeoffs
- **Complexity**: O(n) time, O(n) space
- **Implementations**:
  - `two-sum.py` - Python with comprehensive test cases
  - `two-sum.cpp` - C++ with unordered_map optimization
  - `TwoSum.java` - Java with HashMap approach

### 2. Remove Duplicates from Sorted Array
**Problem**: Remove duplicates from sorted array in-place.
- **Approach**: Two pointers technique
- **Key Learning**: In-place array manipulation, pointer management
- **Complexity**: O(n) time, O(1) space
- **Implementations**:
  - `remove-duplicates-sorted-array.py` - Python with visual output
  - `remove-duplicates-sorted-array.cpp` - C++ with step-by-step demo
  - `RemoveDuplicatesSortedArray.java` - Java with interactive examples

### 3. Best Time to Buy/Sell Stock 
**Problem**: Find maximum profit from one buy and one sell transaction.
- **Approach**: Single pass with minimum price tracking
- **Key Learning**: Dynamic programming concepts, greedy approach
- **Complexity**: O(n) time, O(1) space
- **Implementations**: 
  - `buy-sell-stock.cpp` - C++ with performance comparison
  - `buy-sell-stock.java` - Java with detailed step-by-step demo
  - `buy-sell-stock.py` - Python with interactive features and advanced extensions

### 4. Move Zeroes
**Problem**: Move all 0's to the end while maintaining relative order of non-zero elements.
- **Approach**: Two pointers with in-place manipulation
- **Key Learning**: Array rearrangement, maintaining order, multiple solution approaches
- **Complexity**: O(n) time, O(1) space
- **Implementations**:
  - `move-zeroes.py` - Python with three different approaches
  - `move-zeroes.cpp` - C++ with swapping optimization
  - `MoveZeroes.java` - Java with comprehensive test cases

### 5. Contains Duplicate
**Problem**: Return true if any value appears at least twice in the array.
- **Approach**: Hash set for O(n) solution vs sorting and brute force approaches
- **Key Learning**: Duplicate detection, hash set properties, space-time analysis
- **Complexity**: O(n) time, O(n) space (hash set approach)
- **Implementations**:
  - `contains-duplicate.py` - Python with four different approaches + Pythonic one-liner
  - `contains-duplicate.cpp` - C++ with unordered_set and performance comparison
  - `ContainsDuplicate.java` - Java with comprehensive analysis

### 6. Intersection of Two Arrays
**Problem**: Return an array of intersection elements (each element unique).
- **Approach**: Hash set for O(n+m) solution vs sorting and brute force
- **Key Learning**: Set operations, array comparison, multiple solution strategies
- **Complexity**: O(n + m) time, O(min(n,m)) space (hash set approach)
- **Implementations**:
  - `intersection-two-arrays.py` - Python with set operations and step-by-step demo
  - `intersection-two-arrays.cpp` - C++ with unordered_set optimization
  - `IntersectionTwoArrays.java` - Java with HashSet and performance analysis

## Common Problems
- Two Sum ✅
- Remove Duplicates ✅
- Move Zeroes ✅
- Contains Duplicate ✅
- Intersection of Arrays ✅
- Maximum Subarray (Kadane's Algorithm)
- Array Rotation
- Best Time to Buy/Sell Stock ✅
- Merge sorted arrays

## Time Complexities
| Operation | Time Complexity |
|-----------|-----------------|
| Access    | O(1)           |
| Search    | O(n)           |
| Insertion | O(n)           |
| Deletion  | O(n)           |

## Files in this directory

### Multi-Language Implementations
- **Two Sum Problem**:
  - `two-sum.py` - Python with hash map optimization and comprehensive testing
  - `two-sum.cpp` - C++ with unordered_map and performance analysis
  - `TwoSum.java` - Java with HashMap approach and interactive examples

- **Remove Duplicates**:
  - `remove-duplicates-sorted-array.py` - Python with visual array transformation
  - `remove-duplicates-sorted-array.cpp` - C++ with two-pointer technique
  - `RemoveDuplicatesSortedArray.java` - Java with step-by-step process demo

- **Move Zeroes**:
  - `move-zeroes.py` - Python with three solution approaches and detailed analysis
  - `move-zeroes.cpp` - C++ with optimized swapping technique
  - `MoveZeroes.java` - Java with comprehensive test coverage

- **Contains Duplicate**:
  - `contains-duplicate.py` - Python with four approaches including Pythonic solutions
  - `contains-duplicate.cpp` - C++ with performance-optimized hash set implementation
  - `ContainsDuplicate.java` - Java with multiple algorithms and comparison

- **Intersection of Arrays**:
  - `intersection-two-arrays.py` - Python with set operations and bonus features
  - `intersection-two-arrays.cpp` - C++ with STL optimization and memory efficiency
  - `IntersectionTwoArrays.java` - Java with stream operations and modern syntax

### Single Language Implementations
- **Buy/Sell Stock**:
  - `buy-sell-stock.cpp` - C++ with performance comparison
  - `buy-sell-stock.java` - Stock trading with detailed demonstrations (Java)
  - `buy-sell-stock.py` - Stock trading with interactive features (Python)

- **Plus One**: `plus-one.py` - Add one to digit array with carry handling
- **Kadane's Algorithm**: `kadane.py` - Maximum subarray problem
- **Max Subarray**: `max-subarray.cpp` - Maximum subarray problem variations

## How to Run Examples

**Python files:**
```bash
python two-sum.py
python remove-duplicates-sorted-array.py
python move-zeroes.py
python contains-duplicate.py
python intersection-two-arrays.py
python plus-one.py
python buy-sell-stock.py  # Interactive features included!
```

**Java files:**
```bash
javac TwoSum.java && java TwoSum
javac RemoveDuplicatesSortedArray.java && java RemoveDuplicatesSortedArray
javac MoveZeroes.java && java MoveZeroes
javac ContainsDuplicate.java && java ContainsDuplicate
javac IntersectionTwoArrays.java && java IntersectionTwoArrays
javac buy-sell-stock.java && java StockTradingJava
```

**C++ files:**
```bash
g++ -o two-sum two-sum.cpp && ./two-sum
g++ -o remove-duplicates remove-duplicates-sorted-array.cpp && ./remove-duplicates
g++ -o move-zeroes move-zeroes.cpp && ./move-zeroes
g++ -o contains-duplicate contains-duplicate.cpp && ./contains-duplicate
g++ -o intersection intersection-two-arrays.cpp && ./intersection
g++ -o buy-sell-stock buy-sell-stock.cpp && ./buy-sell-stock
```

## Language-Specific Features

### Python Implementations
- 🐍 **Pythonic Solutions**: Leverages Python's built-in functions and syntax
- 📊 **Interactive Examples**: Step-by-step algorithm demonstrations
- 🔄 **Multiple Approaches**: Optimized, brute force, and Pythonic one-liners
- 📝 **Type Hints**: Modern Python with proper annotations
- 🧪 **Comprehensive Testing**: Extensive test cases with edge case coverage

### Java Implementations
- ☕ **Clean OOP Design**: Well-structured classes with static methods
- 🎯 **Step-by-Step Demos**: Visual algorithm walkthroughs
- 📊 **Performance Analysis**: Built-in complexity comparisons
- 🔍 **Detailed Output**: Shows intermediate steps and transformations
- 🧪 **Robust Testing**: Comprehensive test suites with verification

### C++ Implementations
- ⚡ **Maximum Performance**: Optimized for speed and memory efficiency
- 🔧 **STL Integration**: Uses standard library containers and algorithms
- 📊 **Memory Efficient**: Minimal overhead with optimal data structures
- 🎯 **Production Ready**: Enterprise-level code quality and practices

## Learning Path for Beginners

1. **Start with Two Sum** - Learn hash table optimization
   - Begin with Python for intuitive understanding
   - Try Java for detailed object-oriented approach
   - Challenge with C++ for performance optimization

2. **Master Remove Duplicates** - Two pointers technique
   - Understand in-place array manipulation
   - Learn pointer management strategies

3. **Practice Move Zeroes** - Array rearrangement
   - Multiple solution approaches
   - Maintaining relative order concepts

4. **Explore Contains Duplicate** - Hash set fundamentals
   - Different algorithmic approaches
   - Space-time complexity analysis

5. **Solve Intersection Problems** - Set operations
   - Array comparison techniques
   - Multiple optimization strategies

6. **Advance to Buy/Sell Stock** - Greedy algorithms
   - Dynamic programming introduction
   - Profit optimization concepts

## Problem Difficulty Progression
```
Beginner ⭐        Intermediate ⭐⭐      Advanced ⭐⭐⭐
├── Two Sum ✅     ├── Kadane's Algo     ├── Multiple Stock
├── Contains       ├── Array Rotation    │   Transactions  
│   Duplicate ✅   ├── Merge Arrays      ├── Sliding Window
├── Remove Dups ✅ ├── Binary Search     ├── Dynamic Programming
├── Move Zeroes ✅ │   in Array          │   Optimization
├── Intersection ✅└── 3Sum Problem      └── Advanced Two Pointers
└── Buy/Sell                                 with Multiple Conditions
    Stock (1x) ✅
```

## Key Algorithmic Techniques Covered

### Hash-Based Solutions
- **Two Sum**: Hash map for complement lookup
- **Contains Duplicate**: Hash set for duplicate detection  
- **Intersection**: Hash set for efficient comparison

### Two Pointers Technique
- **Remove Duplicates**: Slow/fast pointer for in-place removal
- **Move Zeroes**: Pointer for non-zero element placement

### Multiple Approach Problems
Each problem includes:
- ✅ **Optimized Solution**: Best time/space complexity
- ✅ **Alternative Approaches**: Different algorithmic strategies
- ✅ **Brute Force**: Educational baseline for comparison
- ✅ **Step-by-step Explanation**: Visual algorithm walkthrough
- ✅ **Comprehensive Testing**: 5-10 test cases per problem
- ✅ **Performance Analysis**: Big O complexity breakdown
- ✅ **Edge Case Handling**: Empty arrays, single elements, etc.

## Interactive Learning Features
- 🎮 **Step-by-Step Demos**: Watch algorithms execute in real-time
- 📊 **Performance Comparisons**: See efficiency differences between approaches
- 🧪 **Custom Test Cases**: Try your own inputs with built-in validation
- 📈 **Complexity Visualization**: Understand time/space trade-offs
- 🎯 **Language Comparisons**: Same problem across Python, Java, and C++