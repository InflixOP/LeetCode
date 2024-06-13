class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int total=0;
        for(int i=0;i<seats.size();i++){
            total+=abs(seats[i]-students[i]);
        }
        return total;
    }
};