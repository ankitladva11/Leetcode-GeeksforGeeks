class BrowserHistory {
    vector<string> urls {};
    int cur = -1, last = -1;
public:
    BrowserHistory(string homepage) {
        visit(homepage);
    }
    
    void visit(string url) {
        if (cur == last && (cur == urls.size()-1)) {
            urls.emplace_back(move(url));
            ++cur;
            ++last;
        } else {
            urls[++cur] = url;
            last = cur;
        }
    }
    
    string back(int steps) {
        return forward(-steps);
    }
    
    string forward(int steps) {
        int i = cur+steps;
        cur = clamp(i, 0, last);
        return urls[cur];
    }
};