#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Job {
	int jobID;
	string jobName;

	Job(int id, string name) : jobID(id), jobName(name) {}
};

void addJob(queue<Job> &jobQueue, int id, const string &name) {
	Job newJob(id, name);
	jobQueue.push(newJob);
	cout << "Added Job ID: " << id << ", Name: " << name << endl;
}

void deleteJob(queue<Job> &jobQueue) {
	if (!jobQueue.empty()) {
		Job job = jobQueue.front();
		jobQueue.pop();
		cout << "Deleted Job ID: " << job.jobID << ", Name: " << job.jobName << endl;
	} else {
		cout << "The job queue is empty, no job to delete." << endl;
	}
}

void displayJobs(const queue<Job> &jobQueue) {
	queue<Job> tempQueue = jobQueue; // Copy to avoid modifying the original queue
	if (tempQueue.empty()) {
		cout << "The job queue is empty." << endl;
		return;
	}

	cout << "Current jobs in the queue:" << endl;
	while (!tempQueue.empty()) {
		Job job = tempQueue.front();
		cout << "Job ID: " << job.jobID << ", Name: " << job.jobName << endl;
		tempQueue.pop();
	}
}

int main() {
	queue<Job> jobQueue;
	int choice;
	int id;
	string name;

	do {
		cout << "\n--- Job Queue Menu ---" << endl;
		cout << "1. Add Job" << endl;
		cout << "2. Delete Job" << endl;
		cout << "3. Display Jobs" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore(); 

		switch (choice) {
			case 1:
				cout << "Enter Job ID: ";
				cin >> id;
				cin.ignore(); 
				cout << "Enter Job Name: ";
				getline(cin, name);
				addJob(jobQueue, id, name);
				break;

			case 2: deleteJob(jobQueue); break;
			case 3: displayJobs(jobQueue); break;
			case 4: cout << "Exiting the program." << endl; break;
			default: cout << "Invalid choice, please try again." << endl; break;
		}
	} while (choice != 4);
	return 0;
}
