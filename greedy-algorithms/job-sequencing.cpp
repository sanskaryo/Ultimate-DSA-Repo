#include <iostream>
#include <vector>
#include <algorithm>

// Represents a job with an ID, deadline, and profit
struct Job {
    char id;
    int deadline;
    int profit;
};

// Comparison function to sort jobs by profit
bool compareJobs(const Job& a, const Job& b) {
    return (a.profit > b.profit);
}

// Function to find the maximum profit job sequence
void jobSequencing(std::vector<Job>& jobs) {
      if (jobs.empty()) {
        std::cout << "No jobs to schedule.\n";
      return;
   }
    // 1. Sort jobs in descending order of profit
    std::sort(jobs.begin(), jobs.end(), compareJobs);

    int n = jobs.size();
    int maxDeadline = 0;
    for (const auto& job : jobs) {
        if (job.deadline <= 0) {
          continue; // Skip jobs with invalid deadlines
      }
        if (job.deadline > maxDeadline) {
            maxDeadline = job.deadline;
        }
    }

     if (maxDeadline == 0) {
     std::cout << "No valid jobs to schedule.\n";
     return;
 }

    // Array to keep track of free time slots
    std::vector<char> result(maxDeadline, ' ');
    std::vector<bool> slot(maxDeadline, false);
    int totalProfit = 0;

    // 2. Iterate through all jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from the last possible slot)
        for (int j = std::min(maxDeadline, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = jobs[i].id; // Add this job to the result
                slot[j] = true;         // Mark this slot as filled
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    
    std::cout << "The sequence of jobs to maximize profit is: ";
    for (char jobId : result) {
        if (jobId != ' ') {
            std::cout << jobId << " ";
        }
    }
    std::cout << "\nTotal Profit: " << totalProfit << std::endl;
}

int main() {
    std::vector<Job> jobs = {
        {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
        {'d', 1, 25}, {'e', 3, 15}
    };
    jobSequencing(jobs);
    return 0;
}