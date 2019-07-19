
//2.1.1 Remove Duplicates from sorted array

/* 
#include <iostream>
#include <vector>
#include <algorithm>

//solution1-O(n) O(1) time/space

int removeDuplicates(std::vector<int>& nums)
{
    if(nums.empty()) return 0;
    int index = 0;
    for(int i = 1; i<nums.size(); i++)
    {
        if(nums[index] != nums[i])
        {
            nums[++index] = nums[i];
        }
    }
    return ++index;
}


//solution2  O(n) O(1) time/space
int removeDuplicates(std::vector<int>& nums)
{
    return distance(nums.begin(), unique(nums.begin(),nums.end()));
    //notice, if I pass {1,1,2,2,3,4,6,6,7,7,7,8} in
    //{1,2,3,4,6,7,8,6,7,7,7,8} and unique will return the iterator pointing to 8 {8,6,7,7,7,8}
    //nums.erase(unique(nums.begin(),nums.end()), nums.end()) will delete 8 to 7
    //so nums will be  {1,2,3,4,6,7,8} notice the 8 is the second 8 in vector above
}


int main()
{
    std::vector<int> A = {1,1,2,2,3,4,6,6,7,7,7,8};
    int i  = removeDuplicates(A);
    std::cout<<i<<"\n"; 
}
*/





//2.1.2 Remove Duplicates From Sorted Array II
/*if duplicates are allowed at most twice?*/

//solution O(n) O(1)
/* 
class solution{
    public:
    int removeDuplicates(std::vector<int>& nums)
    {
        if(nums.size()<2) return nums.size();

        int index = 2;

        for(int i = 2; i<nums.size(); i++)
        {
            if(nums[index] != nums[i])
            {
                nums[index++] = nums[i];
            }
        }
    }
};
*/




//2.1.3
//Search in rotated sort array:
//suppose a sorted array is rotated at some pivot unknown, 
//(i.e  0124567 might become 4567012)
//given a target value to search, if found in the array return its index, otherwise return -1
//assume no duplicate exists in the array

//solution, O(log n), O(1)

/* 
class Solution
{
    public:
    int search(std::vector<int>& nums, int target)
    {
        int first=0, last = nums.size();
        while(first != last)
        {
            int mid = first+(last-first)/2;
            if(nums[mid] == target)
                return nums[mid];
            //if the array is transformed at any point, anytime, at least one half 
            //of the array is in ascending order, where the targetting is performed.
            if(nums[first] <= nums[mid])
            {
                if(nums[first] <= target && target < nums[mid])
                    last = mid;
                else
                    first = mid+1;
            }
            else
            {
                if(nums[mid] < target && target <= nums[last-1])
                    first = mid+1;
                else
                    last = mid;
            }
            
        }
        return -1;
    }
};
*/



/* 
//2.1.4 Search in roated sorted array II
//following the last question, what if duplicates are allowed?

//if duplicate is allowed, then A[m] >= A[l] can no longer lead to conclusion that [l, m] is in ascending order
//thus, spliting it into two sub conditions, one is to check A[m] > A[l], another one is that if A[m]==A[l], l++

//o(n), o(1) time/space

class solution
{
    public:
    bool search(const std::vector<int>& nums, int target)
    {
        int first=0, last = nums.size();
        while(first != last)
        {
            const int mid = first + (last - first)/2;
            if(nums[first] < nums[mid])
            {
                if(nums[first] <= target && target < nums[last-1])
                last = mid;
                else 
                first = mid+1;
            }
            else if(nums[first] > nums[mid])
            {
                if(nums[mid] < target && target <= nums[last-1])
                first = mid+1;
                else
                last = mid;
            }
            else 
            {
                first++;
            }
        }
        return false;
    }
};

*/






//-------------------------------------
//Advertisement--another good resource to refer to 
//https://www.cnblogs.com/grandyang/p/4606334.html


//2.1.5 Median of two sorted arrays
//https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/

/**/
#include <stdio.h>https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/
#include <vector>
#include <iostream>

#define max(a,b) (((a)>(b)) ? (a) : (b))
#define min(a,b) (((a)<(b)) ? (a) : (b))
#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

class Solution
{
    public:
        double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
        {
            int n = nums1.size();
            int m = nums2.size();
            if(n>m)
            {
                return findMedianSortedArrays(nums2, nums1);
            }

            int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2*n;
            while(lo<=hi)
            {
                c1 = (lo+hi)/2;
                c2 = m+n-c1;
                LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1-1)/2];
                RMin1 = (c1 == 2*n) ? INT_MAX : nums1[c1/2];
                LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2-1)/2];
                RMin2 = (c2 == 2*m) ? INT_MAX : nums2[(c2/2)];

                if(LMax1 > RMin2)
                    hi = c1-1;
                else if(LMax2 > RMin1)
                    lo = c1+1;
                else
                    break; 
            }
            return (max(LMax1, LMax2)+min(RMin1, RMin2))/2.0;
        }
};

