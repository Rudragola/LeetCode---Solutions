class NumArray {
private:
    vector<int> tree;
    int n;

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(2 * n);
        
        // Fill the second half with input values
        for (int i = 0; i < n; ++i) {
            tree[n + i] = nums[i];
        }

        // Build the tree by calculating parents
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }

    void update(int index, int val) {
        index += n;
        tree[index] = val;

        while (index > 1) {
            index /= 2;
            tree[index] = tree[2 * index] + tree[2 * index + 1];
        }
    }

    int sumRange(int left, int right) {
        left += n;
        right += n;
        int sum = 0;

        while (left <= right) {
            if (left % 2 == 1) {
                sum += tree[left];
                left++;
            }
            if (right % 2 == 0) {
                sum += tree[right];
                right--;
            }
            left /= 2;
            right /= 2;
        }

        return sum;
    }
};



/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
