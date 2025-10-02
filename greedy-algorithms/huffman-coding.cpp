#include <iostream>
#include <vector>
#include <queue>
#include <string>

// A node in the Huffman Tree
struct MinHeapNode {
    char data;
    unsigned freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

// Comparison structure for the priority queue (min-heap)
struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->freq > r->freq);
    }
};

// Function to print Huffman codes from the tree
void printCodes(struct MinHeapNode* root, std::string str) {
    if (!root) return;

    if (root->data != '$') { // '$' is a special value for internal nodes
        std::cout << root->data << ": " << str << "\n";
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Main function to build and print Huffman Codes
void huffmanCoding(std::vector<char>& data, std::vector<int>& freq) {
    MinHeapNode *left, *right, *top;

    // Create a min-heap and inserts all characters
    std::priority_queue<MinHeapNode*, std::vector<MinHeapNode*>, compare> minHeap;
    for (size_t i = 0; i < data.size(); ++i) {
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }

    // Iterate while size of heap is not 1
    while (minHeap.size() != 1) {
        // Extract the two minimum frequency items
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes' frequencies
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    // Print the Huffman codes using the generated tree
    printCodes(minHeap.top(), "");
}

int main() {
    std::vector<char> data = {'a', 'b', 'c', 'd', 'e', 'f'};
    std::vector<int> freq = {5, 9, 12, 13, 16, 45};
    
    huffmanCoding(data, freq);
    
    return 0;
}