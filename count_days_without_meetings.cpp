class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(meetings.begin(), meetings.end());
            int freeDays = meetings[0][0] - 1, latest = meetings[0][1], i = 1;
    
            for (i = 1; i < meetings.size(); i++) {
                if (meetings[i][0] > latest) {
                    freeDays += meetings[i][0] - latest - 1;
                }
    
                latest = max(latest, meetings[i][1]);
            }
    
            freeDays += days - latest;
            return freeDays;
        }
    };