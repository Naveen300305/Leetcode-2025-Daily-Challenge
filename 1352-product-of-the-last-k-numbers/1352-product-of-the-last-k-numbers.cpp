class ProductOfNumbers {
public:
    vector<int> v;
    ProductOfNumbers() {
        v.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            v.clear();
            v.push_back(1);
        }
        else v.push_back(num*v[v.size()-1]);
    }
    
    int getProduct(int k) {
        if(k>=v.size()) return 0;
        else return v[v.size()-1]/v[v.size()-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */