class Solution {
public:
vector<string> commonChars(vector<string>& words) {
vector<string> ans;
unordered_map<char,int> m;
int n = words.size();
for (char ch : words[0]) {
m[ch]++;
}
for (int i = 1; i < n; ++i) {
unordered_map<char,int> temp;
for (char ch : words[i]) {
temp[ch]++;
}
for (auto& entry : m) {
entry.second = min(entry.second, temp[entry.first]);
}
}
for (auto& ele : m) {
while (ele.second > 0) {
ans.push_back(string(1, ele.first));
ele.second--;
}
}
return ans;
}
};