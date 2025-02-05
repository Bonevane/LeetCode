class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int pos1 = 0, pos2 = 0;

        for (int i = 0; i < s1.length(); i++){
            if (s1[i] != s2[i] && pos1 == 0)
                pos1 = i;
            else if (s1[i] != s2[i] && pos2 == 0)
                pos2 = i;
        }

        swap(s1[pos1], s1[pos2]);
        
        return s1 == s2;
    }
};