//1. Two-sum
// ex: nums = [2,7,11,15], target = 9, return [0,1]
//method: hash table (once)
// what is hash table? https://blog.csdn.net/iva_brother/article/details/82253989
#include<iostream>
#include<map>
#include<vector>

//how to use map? https://blog.csdn.net/sevenjoin/article/details/81943864

class solution
{
    public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::map<int, int> a;
        std::vector<int> b(2,-1);
        for(int i = 0; i < nums.size();i++)
        {
            if(a.count(target-nums[i])>0)
            {
                b[0] = a[target-nums[i]];
                b[1] = i;
                break; 
            }
            a[nums[i]] = i;

        }
        return b;
    }
};

//Add-two-numbers
//ex: (2->4->3)+(5->6->4) = (7->0->8)
//reason: 342+465=807
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int a): val(a), next(NULL) {}
};

class Solution
{
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* head = new ListNode(-1);
        ListNode* h = head;
        int sum = 0;
        bool carry = false;

        while(l1 != NULL || l2 != NULL)
        {
            sum = 0;
            if(l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            if(carry)
            {
                sum += 1;
            }

            h->next = new ListNode(sum%10);
            h = h->next;
            carry = sum >= 10 ? true : false;

        }
        if(carry)
        {
            h->next = new ListNode(1);
        }
        return head->next;
    }
};


//3. longest-substring-without-repeating-characters
//pwwkew 3: wke

//https://www.cnblogs.com/ariel-dreamland/p/8668286.html

012
bbb
123

left = 2
res = 1
m=[abcdef...] {0300000...}
i = 1

{
(m[] == 0 || m[] < left)
{
    res=max(res,i-left+1);
}
else
{
    left = m[b];
}

m[b] = i+1;
}

return res;


class Solution{
    public:
    int hehe(string s)
    {
        int m[256] = {o}, res=0, left=0;
        for(int i = 0; i<s.size();i++)
        {
            if(m[s[i]] == 0 || m[s[i]] < left)
            {
                res = max(res,i-left+1); //in case abcabc, 
            }
            else
            {
                left = m[s[i]];
            }
            m[s[i]] =  i+1;
        }
        return res;
    }
};


//4. median of two sorted arrays
//nums1 = [1,3]
//nums2 = [2]
//median : 2.0

#include <stdio.h>
#include <vector>
#include <iostream>

#define max(a, b) (((a)>(b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

class solution
{
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m)
        {
            findMedianSortedArrays(nums2, nums1);
        }

        int LMax1, LMax2, RMin1, RMin2, c1, c2, lo=0, hi = 2*n;
        while(lo<=hi)
        {
            c1 = (lo+hi)/2;
            c2 = (m+n-c1);

            LMax1 = (c1 ==0) ? INT_MIN : nums1[(c1-1)/2];
            RMin1 = (c1 == 2*n) ? INT_MAX : nums1[(c1/2)];
            LMax2 = (c2 ==0) ? INT_MIN : nums2[(c2-1)/2];
            RMin2 = (c2 == 2*m) ? INT_MAX : nums2[(c2/2)];
            
            if(LMax1 > RMin2)
                hi = c1 - 1;
            else if (LMax2 > RMin1)
                lo = c1+1;
            else
                break;
            
        }
        return (max(LMax1, LMax2) + min(RMin1, RMin2))/2.0;
    }
}


//5 longest-palindromic-substring
//ex: babad  --> bab or aba
//ex: cbbd --> bb

class Solution{
    public:
    string longestPalindrome(string s)
    {
        int start = 0;
        int end = 0;
        int mlen = 0;
        int len=s.size();
        
        if(len == 0 || len ==1)
            return s;
        
        for(int i = 0; i<len;i++)
        {
            int len1 = expandaroundcenter(s, i, i);
            int len2 = expandaroundcenter(s,i,i+1);
            mlen = max(max(len1,len2), mlen);
            if(mlen > end-start+1)
            {
                start = i-(mlen-1)/2;
                end = i+mlen/2;
            }
        }
        return s.substr(start, mlen);
    }
    private:
    {
        int expandaroundcenter(string s, int L, int R)
        {
            while(L>=0 && R < s.length() && s[L] == s[R])
            {
                L--;
                R++;
            }
            return R-L-1;
        }
    }
}


//6 Zigzag-conversion

class Solution
{
    public:

    int curRow = 0;
    bool goingdown = false;
    vector<string> rows(min(numRows,int(s.size())));
    string convert(string s, int numRows)
    {
        for(char c : s)
        {
            rows[curRow] += c;
            if(curRow == 0 || curRow = numRows-1)
            {
                goingdown = !goingdown;
            }
            curRow += goingdown ? 1 : -1;
        }

        string ret;
        for(tring row : rows)
        {
            ret += row;
        }

        return ret;
    }
}


//7 reverse-integer
//ex: 120->21,  345->543
//O(log(x)) time, O(1) space.

class Solution{
    public:
    int reverse(int x)
    {
        int rev = 0;
        while(x != 0)
        {
            int pop = x%10;
            x /= 10;
            if(rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if(rev < INT_MIN/10 || (rev == INI_MIN/10 && pop < -8)) return 0;
            rev = rev*10 + pop;
        }

        return rev;
    }
};

//8 string to integer
//range INT_MAX (2^31-1) INT_MIN(-2^31)
//if the char in the string is neither int or sign, then no convertion

class Solution {
    public:
    int myAtoi(string str)
    {
        while(*str.begin() == ' ') str.erase(str.begin());
        if(str == "") return 0;
        stringstream ss;
        ss<<str;
        int n; 
        ss>>n;
        return n;
    }
};





//9 palindrome-number

class Solution
{
    public:
        bool isPalindrome(int x)
        {
            int midrev = 0;
            if(x < 0 || x%10 == 0 && x != 0) return false;
            while(x > midrev)
            {
                midrev = midrev*10 + x%10;
                x /= 10;
            }
            return midrev == x || midrev/10 == x;
        }
}