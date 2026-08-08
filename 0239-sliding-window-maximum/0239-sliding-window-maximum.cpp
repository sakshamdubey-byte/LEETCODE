class Solution {
public:
    vector<int> st;

    void create(vector<int>& nums, int idx, int start, int end)
    {
        if (start == end)
        {
            st[idx] = nums[start];
            return;
        }

        int mid = (start + end) / 2;

        create(nums, 2 * idx + 1, start, mid);
        create(nums, 2 * idx + 2, mid + 1, end);

        st[idx] = max(st[2 * idx + 1], st[2 * idx + 2]);
    }

    int query(vector<int>& nums, int idx, int start, int end, int l, int r)
    {
        // Completely inside
        if (l <= start && end <= r)
            return st[idx];

        // Completely outside
        if (end < l || start > r)
            return INT_MIN;

        int mid = (start + end) / 2;

        int left = query(nums, 2 * idx + 1, start, mid, l, r);
        int right = query(nums, 2 * idx + 2, mid + 1, end, l, r);

        return max(left, right);
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        st.resize(4 * nums.size());

        create(nums, 0, 0, nums.size() - 1);

        vector<int> v;

        for (int i = 0; i <= nums.size() - k; i++)
        {
            v.push_back(
                query(nums, 0, 0, nums.size() - 1, i, i + k - 1)
            );
        }

        return v;
    }
};