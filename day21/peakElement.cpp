class Solution {
public:
    int BinarySearch(vector<int> &num, int s, int end) {
        if(s == end) return s;
        else{
            int mid1 = (s+end)/2;
            int mid2 = mid1+1;
            if(num[mid1] > num[mid2]) return BinarySearch(num, s, mid1);
            else return BinarySearch(num, mid2, end);
        }
    }
    int findPeakElement(vector<int> &num) {
        return BinarySearch(num, 0, num.size()-1);
    }
};