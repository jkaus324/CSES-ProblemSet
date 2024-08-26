#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>

using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;

    void build(const vector<int>& data) {
        // Initialize the tree with the data
        for (int i = 0; i < n; i++)
            tree[n + i] = data[i];
        
        // Build the segment tree by calculating parents
        for (int i = n - 1; i > 0; --i)
            tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    }

public:
    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(2 * n);
        build(data);
    }

    void update(int index, int value) {
        // Update the value at the original array and propagate it upwards
        index += n;
        tree[index] = value;
        
        for (index /= 2; index >= 1; index /= 2)
            tree[index] = min(tree[index << 1], tree[index << 1 | 1]);
    }

    int rangeMinQuery(int left, int right) {
        // Get the minimum value in the range [left, right)
        int minVal = INT_MAX;
        left += n;
        right += n;
        
        while (left < right) {
            if (left & 1)
                minVal = min(minVal, tree[left++]);
            if (right & 1)
                minVal = min(minVal, tree[--right]);
            left /= 2;
            right /= 2;
        }
        return minVal;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> data(n);
    for (int i = 0; i < n; i++)
        cin >> data[i];

    SegmentTree segTree(data);

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, u;
            cin >> k >> u;
            segTree.update(k - 1, u);  // Convert to 0-based index
        } else if (type == 2) {
            int a, b;
            cin >> a >> b;
            cout << segTree.rangeMinQuery(a - 1, b) << endl;  // Convert to 0-based index
        }
    }

    return 0;
}
