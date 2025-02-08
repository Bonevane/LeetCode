// It seems there's a better way to do this using priority queues (min heaps)...

class NumberContainers {
    private:
        unordered_map<int, int> indexToNum;
        unordered_map<int, set<int>> numToIndex;
    
    
    public:
        NumberContainers() {}
        
        void change(int index, int number) {
            if (indexToNum.find(index) != indexToNum.end()){
                numToIndex[indexToNum[index]].erase(index);   
    
                if (numToIndex[indexToNum[index]].empty())
                    numToIndex.erase(indexToNum[index]);
            }
    
            numToIndex[number].insert(index);
            indexToNum[index] = number;
        }
        
        int find(int number) {
            if (numToIndex.find(number) != numToIndex.end()){
                return *numToIndex[number].begin();
            }
    
            return -1;
        }
    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */