#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
    vector<int> stream; // Stores prefix product
public:
    ProductOfNumbers() {
        stream = {1};  // Initialize with 1 to handle multiplication properly
    }

    void add(int num) {
        if (num == 0) {
            stream = {1}; // Reset the product sequence when a 0 is added
        } else {
            stream.push_back(stream.back() * num);
        }
    }

    int getProduct(int k) {
        if (k >= stream.size()) 
            return 0;  // If we ask for more elements than exist, return 0
        return stream.back() / stream[stream.size() - k - 1];
    }
};

int main() {
    ProductOfNumbers productOfNumbers;
    vector<string> output = {"null"}; // First call is the constructor, so return "null"

    productOfNumbers.add(3);        
    output.push_back("null");
    
    productOfNumbers.add(0);        
    output.push_back("null");
    
    productOfNumbers.add(2);        
    output.push_back("null");
    
    productOfNumbers.add(5);        
    output.push_back("null");
    
    productOfNumbers.add(4);        
    output.push_back("null");
    
    output.push_back(to_string(productOfNumbers.getProduct(2))); // 20
    output.push_back(to_string(productOfNumbers.getProduct(3))); // 40
    output.push_back(to_string(productOfNumbers.getProduct(4))); // 0
    
    productOfNumbers.add(8);        
    output.push_back("null");
    
    output.push_back(to_string(productOfNumbers.getProduct(2))); // 32

    // Print output in required format
    cout << "[";  
    for (size_t i = 0; i < output.size(); i++) {
        cout << output[i];
        if (i != output.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}

