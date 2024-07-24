class BrowserHistory {
public:
    int index = 0 , n = 1;
    string list[101];
    BrowserHistory(string homepage) {

        list[index] = homepage;
    }

    void visit(string url) {
        list[++index] = url;
        n = index + 1;
    }

    string back(int steps) {

        index = index - steps > 0 ? index - steps : 0;

        return list[index];
    }

    string forward(int steps) {

        index = index + steps < n ? index + steps : n - 1;

        return list[index];
    }
};