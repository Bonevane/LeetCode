class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            unordered_map<int, int> ballToColor;
            unordered_map<int, int> colorCount;
            vector<int> result;
    
            for (int i = 0; i < queries.size(); i++){
                int ball = queries[i][0];
                int newColor = queries[i][1];
    
                if (ballToColor.find(ball) != ballToColor.end()) {
                    colorCount[ballToColor[ball]]--;
                    
                    if (colorCount[ballToColor[ball]] == 0) {
                        colorCount.erase(ballToColor[ball]);
                    }
                }
                
                ballToColor[ball] = newColor;
                colorCount[newColor]++;
    
                result.push_back(colorCount.size());
            }
    
            return result;
        }
    };
    