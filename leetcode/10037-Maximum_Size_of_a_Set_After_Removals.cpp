class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        long long orig = nums1.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
        nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());
        vector<long long> ist;
        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(ist));
        long long n1 = nums1.size();
        long long n2 = nums2.size();
        n1 -= ist.size();
        n2 -= ist.size();
        long long sub1 = min(orig/2, n1);
        long long sub2 = min(orig/2, n2);
        long long ans = sub1+sub2;
        long long rem1 = orig/2 - sub1;
        long long rem2 = orig/2 - sub2;
        long long to_add = ist.size();
        ans += min(to_add, rem1);
        to_add = max((long long)0, to_add-rem1);
        ans += min(to_add, rem2);
        return ans;
    }
};
