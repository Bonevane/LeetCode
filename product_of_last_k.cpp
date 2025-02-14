// Much better than the version using linked list in O(k) (product) and O(1) (addition) 

class ProductOfNumbers {
    public:
        ProductOfNumbers() {}
        
        void add(int num) {
            if(num == 0){
                arr.clear();
                latest = 1;
                return;
            }
            latest *= num;
            arr.push_back(latest);
        }
        
        int getProduct(int k) {
            if(arr.size() < k) return 0;
            if(arr.size() == k) return latest;
            int result = arr[arr.size() - 1];
            return result / arr[arr.size() - 1 - k];
        }
    
    private:
        vector<int> arr;
        int latest = 1;
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */
