#include <bits/stdc++.h>
using namespace std;

class NumberContainers {
    unordered_map<int, int> index_number; // Maps index to number
    unordered_map<int, set<int>> number_indices; // Maps number to a set of indices

public:
    NumberContainers() {}

    void change(int index, int number) {
        // If the index already has a number, remove it from the old mapping
        if (index_number.count(index)) {
            int old_number = index_number[index];
            number_indices[old_number].erase(index);
            if (number_indices[old_number].empty()) {
                number_indices.erase(old_number);
            }
        }
        // Assign the new number to the index
        index_number[index] = number;
        number_indices[number].insert(index);
    }

    int find(int number) {
        if (!number_indices.count(number)) {
            return -1;
        }
        return *number_indices[number].begin(); // Return the smallest index storing the number
    }
};

int main() {
    NumberContainers* obj = new NumberContainers();
    vector<string> operations = {"NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"};
    vector<vector<int>> inputs = {{}, {10}, {2, 10}, {1, 10}, {3, 10}, {5, 10}, {10}, {1, 20}, {10}};
    
    vector<string> output;
    
    for (int i = 0; i < operations.size(); ++i) {
        if (operations[i] == "NumberContainers") {
            obj = new NumberContainers();
            output.push_back("null"); // Constructor doesn't return anything
        } else if (operations[i] == "find") {
            output.push_back(to_string(obj->find(inputs[i][0])));
        } else if (operations[i] == "change") {
            obj->change(inputs[i][0], inputs[i][1]);
            output.push_back("null"); // change() doesn't return anything
        }
    }
    
    // Print the output in the required format
    cout << "[";
    for (int i = 0; i < output.size(); ++i) {
        cout << output[i];
        if (i < output.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    delete obj;
    return 0;
}

