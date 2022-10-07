/*	Nico Andrade
 *	201261260
 *	andra106@csusm.edu
 */


using namespace std;
#include <iostream>
#include <vector>

struct Node {
	int data;
	Node* next;
};

/*	I've decided to implement the Queue data structure using a linked list.
 *	It is all contained in the following class, except for the node, which is in the above struct.
 */
class integerQueue {
public:
	integerQueue(){
		front = nullptr;
		rear = nullptr;
		size = 0;
	}

	//inserts n at the end of the queue
	void insert(int n) {
		//cout << "inserting " << n << endl;
		Node* last = new Node();
		last->data = n;
		last->next = nullptr;
		if (rear != nullptr) {
			rear->next = last;
		}
		rear = last;
		if (front == nullptr)
			front = last;
		size++;
	}

	//removes the first element of the queue and returns it to calling function
	int remove() {
		if (front == nullptr) {
			cout << "error: list is empty" << endl;
		}
		else {
			size--;
			int first = front->data;
			front = front->next;
			return first;
		}
	}

	//returns the first element of the queue but does not remove it
	int query() {
		if (front == nullptr) {
			cout << "error: list is empty" << endl;
		}
		else {
			return front->data;
		}
	}

	//returns true if the queue is empty, returns false otherwise
	bool isEmpty() {
		return (front == nullptr);
	}

private:
	Node* front;
	Node* rear;
	int size;
};


/*	Algorithm:
 *	1. Get user input and add each cow to the queue.
 *	2. Take the first k cows and place them on the stage.
 *	3. Iterate time function:
 *		A. Subtract 1 from the time remaining value of each cow on stage.
 *		B. If a cow finishes her part, take her off stage and place next cow in queue in her spot.
 *		C. Iterate time counter by one.
 */
int main(void) {
	integerQueue cows;
	int n, k, t = 0;	//n is the number of cows. k is the size of the stage. t is the total time taken for all cows to perform.
	int cowNumber;	//Used for adding each cow's time value to the queue
	vector<int> stage;
	bool stageEmpty = false;


	//Query user for input
	cin >> n;
	cin >> k;
	stage.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> cowNumber;
		cows.insert(cowNumber);
	}

	//Put first n cows on stage
	for (int i = 0; i < n; i++) {
		stage[i] = cows.remove();
	}


	//Iterate time, and put new cows on stage as old cows finish
	while (!stageEmpty) {
		stageEmpty = true;
		for (int i = 0; i < n; i++) {
			if (stage[i] == 0) {
				if (!cows.isEmpty())
					stage[i] = cows.remove();
			}
			else {
				stageEmpty = false;
				stage[i]--;
			}
		}
		if (stageEmpty)
			break;
		t++;
	}

	//Print final result
	cout << "Total time: " << t << endl;

	return 0;
}

