#include <iostream>
using namespace std;

#define SIZE 10

typedef struct {
	int data[SIZE];
	int front;
	int rear;
} CircularQueue;

void InitQueue(CircularQueue &Q) {
	Q.front = Q.rear = 0;
}

bool IsEmpty(CircularQueue Q) {
	return Q.front == Q.rear;
}

bool IsFull(CircularQueue Q) {
	return (Q.rear + 1) % SIZE == Q.front;
}

void Enqueue(CircularQueue &Q, int x, bool &fullFlag) {
	if (IsFull(Q)) {
		fullFlag = true;
		return;
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % SIZE;
	fullFlag = false;
}

void Dequeue(CircularQueue &Q, int &x, bool &emptyFlag) {
	if (IsEmpty(Q)) {
		emptyFlag = true;
		return;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % SIZE;
	emptyFlag = false;
}

int main() {
	int n;
	cin >> n;
	CircularQueue Q;
	InitQueue(Q);
	string dequeueOutput;
	for (int i = 0; i < n; ++i) {
		int op;
		cin >> op;
		if (op != 0) {
			bool fullFlag = false;
			Enqueue(Q, op, fullFlag);
			if (fullFlag) {
				dequeueOutput += "FULL ";
			}
		} else {
			int x;
			bool emptyFlag = false;
			Dequeue(Q, x, emptyFlag);
			if (emptyFlag) {
				dequeueOutput += "EMPTY ";
			} else {
				dequeueOutput += to_string(x) + " ";
			}
		}
	}
	cout << dequeueOutput << endl;
	string remainingElements;
	while (!IsEmpty(Q)) {
		int x;
		bool emptyFlag;
		Dequeue(Q, x, emptyFlag);
		remainingElements += to_string(x) + " ";
	}
	cout << remainingElements << endl;
	return 0;
}
