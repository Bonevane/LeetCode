// Defo gave up and used GPT :(

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Step 1: Initialize the transitive closure matrix
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));
        
        // Step 2: Populate the direct prerequisites
        for (const auto& prereq : prerequisites) {
            reachable[prereq[0]][prereq[1]] = true;
        }
        
        // Step 3: Compute transitive closure using Floyd-Warshall
        for (int k = 0; k < numCourses; ++k) { // Intermediate node
            for (int i = 0; i < numCourses; ++i) { // Source node
                for (int j = 0; j < numCourses; ++j) { // Destination node
                    if (reachable[i][k] && reachable[k][j]) {
                        reachable[i][j] = true;
                    }
                }
            }
        }
        
        // Step 4: Process the queries
        vector<bool> answer;
        for (const auto& query : queries) {
            answer.push_back(reachable[query[0]][query[1]]);
        }
        
        return answer;
    }
};
