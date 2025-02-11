class Solution {
    public:
        string removeOccurrences(string s, string part) {
            string result;
            int n = part.length();
            char end = part.back();
            
            for (char c : s) {
                result.push_back(c);
    
                if (c == end && result.size() >= n)
                    if (result.substr(result.size() - n) == part)
                        result.erase(result.size() - n);
            }
    
            return result;
        }
    };