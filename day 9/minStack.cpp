#include <bits/stdc++.h>

// Implement class for minStack.
class minStack
{
	// Write your code here.
        stack<int> st;
        stack<int> mn;
	public:
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
            if(mn.empty() || mn.top()>=num) mn.push(num);
            else mn.push(mn.top());
            st.push(num);
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
            if(st.empty()) return -1;
            int ele= st.top();
            st.pop();
            mn.pop();
            return ele;
			// Write your code here.
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
            if(st.empty()) return -1;
            else return st.top();
			// Write your code here.
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
            if(mn.empty()) return -1;
            return mn.top();
		}
};