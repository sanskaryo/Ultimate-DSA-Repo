#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

// Represents an item with a value and a weight
struct Item {
    int value;
    int weight;
    double ratio; // value / weight
};

// Comparison function to sort items by their value-to-weight ratio
bool compareItems(const Item& a, const Item& b) {
    return a.ratio > b.ratio;
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(int capacity, std::vector<Item>& items) {
    // 1. Calculate the value-to-weight ratio for each item
    for (auto& item : items) {
        item.ratio = static_cast<double>(item.value) / item.weight;
    }

    // 2. Sort items based on their ratio in descending order
    std::sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    // 3. Iterate through the sorted items
    for (const auto& item : items) {
        if (currentWeight + item.weight <= capacity) {
            // Take the whole item if it fits
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            // Take a fraction of the item to fill the remaining capacity
            int remainingCapacity = capacity - currentWeight;
            totalValue += item.value * (static_cast<double>(remainingCapacity) / item.weight);
            break; // Knapsack is now full
        }
    }
    return totalValue;
}

int main() {
    int capacity = 50;
    std::vector<Item> items = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    double maxValue = fractionalKnapsack(capacity, items);
    std::cout << "Maximum value in Knapsack = " << std::fixed << std::setprecision(2) << maxValue << std::endl;
    return 0;
}