#include <iostream>
#include <vector>
#include <algorithm>

// Represents an activity with a start and finish time
struct Activity {
    int start;
    int finish;
};

// Comparison function to sort activities by their finish time
bool compareActivities(const Activity& a, const Activity& b) {
    return (a.finish < b.finish);
}

// Function to find the maximum number of non-overlapping activities
void selectActivities(std::vector<Activity>& activities) {
       if (activities.empty()) {
       std::cout << "No activities to select." << std::endl;
       return;
    }
    // 1. Sort activities based on their finish time
    std::sort(activities.begin(), activities.end(), compareActivities);

    std::cout << "Selected activities:" << std::endl;

    // 2. The first activity is always selected
     size_t i = 0;
    std::cout << "(" << activities[i].start << ", " << activities[i].finish << ")" << std::endl;

    // 3. Iterate through the rest of the activities
     for (size_t j = 1; j < activities.size(); j++) {
        // If this activity's start time is after or same as the finish time of the previously selected one
        if (activities[j].start >= activities[i].finish) {
            std::cout << "(" << activities[j].start << ", " << activities[j].finish << ")" << std::endl;
            i = j; // Update the index of the last selected activity
        }
    }
}

int main() {
    std::vector<Activity> activities = {
        {5, 9}, {1, 2}, {3, 4}, {0, 6},
        {5, 7}, {8, 9}
    };
    selectActivities(activities);
    return 0;
}