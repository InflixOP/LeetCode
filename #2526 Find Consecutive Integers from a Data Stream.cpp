class DataStream {
public:
    vector<int> a;
    int k = 0;
    int value;
    unordered_map<int, int> count;

    DataStream(int value, int k) : value(value), k(k) {}

    bool consec(int num) {
        a.push_back(num);
        
        count[num]++;

        if (a.size() > k) {
            int removed_num = a[a.size() - k - 1];
            count[removed_num]--;
            if (count[removed_num] == 0) {
                count.erase(removed_num);
            }
        }

        return count[value] == k;
    }
};