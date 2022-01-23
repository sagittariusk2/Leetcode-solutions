// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

void insertSort(stack<int>&s, int temp) {
    if(s.empty() or temp>s.top()) {
        s.push(temp);
    } else {
        int x = s.top();
        s.pop();
        insertSort(s, temp);
        s.push(x);
    }
}

void sortStack(stack<int>&s) {
    if(!s.empty()) {
        int temp = s.top();
        s.pop();
        sortStack(s);
        // s.push(temp);
        insertSort(s, temp);
    }
}

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort() {
    sortStack(s);
}