class Solution {
public:
    double gain(int p,int n){
        return (double)(p+1)/(n+1)-(double)p/n;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    int n=classes.size();
    priority_queue<pair<double,pair<int,int>>> pq;
    for(auto& ele:classes){
        pq.push({gain(ele[0],ele[1]),{ele[0],ele[1]}});
    } 
    while(extraStudents!=0){
        auto ele=pq.top();
        pq.pop();
        int p=ele.second.first;
        int n1=ele.second.second;
        pq.push({gain(p+1,n1+1),{p+1,n1+1}});
        extraStudents--;
    }   
    double sum=0;
    while(!pq.empty()){
        auto ele=pq.top();
        pq.pop();
        sum+=(double)ele.second.first/ele.second.second;
    }
    return sum/n;
    }
};