class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        sort(logs.begin(),logs.end());
        vector<int>v(k,0);
        int count , t=0;
        for(int i=0 ; i < logs.size() -1 ; i++ )
        {
            count=1;
            if( logs[i][0] == logs[i+1][0] )
            {
                while( logs[i][0] == logs[i+1][0] )
                {
                    if( logs[i][1] != logs[i+1][1] )
                    {
                        count++;
                    }
                    i++;
                    if(i+1==logs.size())
                    {
                        break;
                    }
                }
                v[count-1]++;
            }
            else
            {
                v[count-1]++;
            }
        }
        if( logs.size()==1 || logs[logs.size()-1][0]!=logs[logs.size()-2][0])
        {
            v[0]++;
        }
        return v;
    }
};