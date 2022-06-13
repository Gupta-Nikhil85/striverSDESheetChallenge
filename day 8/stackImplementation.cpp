// Stack class.
class Stack {
    vector<int> v;
    int capacity;
public:
    
    Stack(int capacity) {
        // Write your code here.
        this->capacity= capacity;
    }

    void push(int num) {
        // Write your code here.
        if(v.size()<capacity){
            v.push_back(num);
        }
    }

    int pop() {
        // Write your code here.
        if(v.size()==0) return -1;
        int ans= v.back();
        v.pop_back();
        return ans;
    }
    
    int top() {
        // Write your code here.
        if(v.size()==0) return -1;
        return v.back();
    }
    
    int isEmpty() {
        // Write your code here.
        return v.size()>0 ? 0 : 1;
    }
    
    int isFull() {
        // Write your code here.
        return v.size()==capacity ? 1:0;
    }
    
};