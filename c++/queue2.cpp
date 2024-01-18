#include <iostream>
#include <queue>

class JobQueue {
private:
    std::queue<std::string> jobs;

public:
    void addJob(const std::string& job) {
        jobs.push(job);
        std::cout << "Job added: " << job << std::endl;
    }

    void processJobs() {
        while (!jobs.empty()) {
            std::string currentJob = jobs.front();
            jobs.pop();
            std::cout << "Processing job: " << currentJob << std::endl;
        }
    }

    bool isEmpty() {
        return jobs.empty();
    }
};

int main() {
    JobQueue jobQueue;

    jobQueue.addJob("Job 1");
    jobQueue.addJob("Job 2");
    jobQueue.addJob("Job 3");

    jobQueue.processJobs();

    return 0;
}
