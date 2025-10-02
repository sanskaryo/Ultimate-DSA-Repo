#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <memory> // Required for smart pointers

// A node in the Huffman Tree, now using smart pointers
struct MinHeapNode {
    char data;
    unsigned freq;
    bool isLeaf;
    // Use std::shared_ptr for automatic memory management
    std::shared_ptr<MinHeapNode> left, right;

   MinHeapNode(char data, unsigned freq, bool isLeaf = true)
        : data(data), freq(freq), isLeaf(isLeaf), left(nullptr), right(nullptr) {}
};

// Comparison structure for the priority queue (min-heap)
// It now compares shared_ptr<MinHeapNode>
struct compare {
    bool operator()(const std::shared_ptr<MinHeapNode>& l, const std::shared_ptr<MinHeapNode>& r) const {
        return (l->freq > r->freq);
    }
};

// Function to print Huffman codes from the tree
void printCodes(const std::shared_ptr<MinHeapNode>& root, std::string str) {
    if (!root) {
        return;
    }

    // A '$' is used as a special value for internal nodes
    if (root->isLeaf) {
        std::cout << root->data << ": " << str << "\n";
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Main function to build and print Huffman Codes
void huffmanCoding(const std::vector<char>& data, const std::vector<int>& freq) {
    // --- 1. Input Validation ---
    if (data.empty() || data.size() != freq.size()) {
        std::cerr << "Error: Input vectors are empty or have mismatched sizes.\n";
        return;
    }
    // Check for reserved character
   for (char c : data) {
       if (c == '$') {
            std::cerr << "Error: Input data cannot contain the '$' character.\n";
          return;
      }
   }

    // --- 2. Build the Min-Heap ---
    // The priority queue now stores shared pointers to nodes
    std::priority_queue<std::shared_ptr<MinHeapNode>, std::vector<std::shared_ptr<MinHeapNode>>, compare> minHeap;

    for (size_t i = 0; i < data.size(); ++i) {
        // Use std::make_shared instead of `new`
        minHeap.push(std::make_shared<MinHeapNode>(data[i], freq[i]));
    }

    // --- 3. Build the Huffman Tree ---
    while (minHeap.size() != 1) {
        // Extract the two minimum frequency items
        auto left = minHeap.top();
        minHeap.pop();
        auto right = minHeap.top();
        minHeap.pop();

        // Create a new internal node.
        // Its frequency is the sum of the two nodes' frequencies.
        auto top = std::make_shared<MinHeapNode>('\0', left->freq + right->freq, false);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    // --- 4. Print Codes and Cleanup ---
    // The root of the tree is the last remaining node
    auto root = minHeap.top();
    printCodes(root, "");

    // No manual cleanup needed!
    // Smart pointers automatically deallocate memory when they go out of scope.
}

int main() {
    std::cout << "--- Test Case 1: Valid Input ---\n";
    std::vector<char> data1 = {'a', 'b', 'c', 'd', 'e', 'f'};
    std::vector<int> freq1 = {5, 9, 12, 13, 16, 45};
    huffmanCoding(data1, freq1);

    std::cout << "\n--- Test Case 2: Empty Input ---\n";
    std::vector<char> data2 = {};
    std::vector<int> freq2 = {};
    huffmanCoding(data2, freq2);

    std::cout << "\n--- Test Case 3: Mismatched Input ---\n";
    std::vector<char> data3 = {'x', 'y'};
    std::vector<int> freq3 = {10};
    huffmanCoding(data3, freq3);

    return 0;
}