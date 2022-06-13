class Queue {
    vector<int> v;
    int f=0,rear=0;
public:
    Queue() {
        // Implement the Constructor
        
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return f==rear;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        v.push_back(data);
        rear++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(f==rear) return -1;
        int ans= v[f];
        f++;
        return ans;
    }

    int front() {
        // Implement the front() function
        if(f==rear) return -1;
        return v[f];
    }
};