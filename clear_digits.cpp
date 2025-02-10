// Could've used a stack instead...

class Solution {
    public:
        string clearDigits(string s) {
            string result;
    
            for (int i = 0; i < s.length(); i++){
                if (!isdigit(s[i]))
                    result += s[i];
                else if (result.begin() != result.end()){
                    result.erase(result.end() - 1);
                }
            }
    
            return result;
        }
    };