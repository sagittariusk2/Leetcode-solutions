class BrowserHistory {
private:
    stack<string> mainStack, secStack;
public:
    BrowserHistory(string homepage) {
        mainStack.push(homepage);
    }
    
    void visit(string url) {
        mainStack.push(url);
        while(!secStack.empty()) {
            secStack.pop();
        }
    }
    
    string back(int step) {
        while(mainStack.size()!=1 and step--) {
            secStack.push(mainStack.top());
            mainStack.pop();
        }
        return mainStack.top();
    }
    
    string forward(int step) {
        while(!secStack.empty() and step--) {
            mainStack.push(secStack.top());
            secStack.pop();
        }
        return mainStack.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */