
//1. Two-sum
// ex: nums = [2,7,11,15], target = 9, return [0,1]
//method: hash table (once)
// what is hash table? https://blog.csdn.net/iva_brother/article/details/82253989
#include<iostream>
#include<map>
#include<vector>
#include<string>

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
            return findMedianSortedArrays(nums2, nums1);
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




//10 regular-expression-matching
//'.' 匹配任意单个字符
//'*' 匹配零个或多个前面的那一个元素

class Solution{
    public:
        bool isMatch(string str, string pattern)
        {
            len1 = str.size();
            len2 = pattern.size();
            if(len2 && pattern[0] == '*')
                return false;
            vector<vector<bool>>flag(len1+1, vector<bool>(len2+1, false));
            flag[0][0] = true;
            for(int i = 0; i < len2; i++)
            {
                if(pattern[i-1] == '*')
                    flag[0][i] = flag[0][i-1] || flag[0][i-2];
            }

            for(int i = 1; i<= len1; i++)
            {
                for(int j = 1; j <= len2; j++)
                {
                    if((pattern[j-1] == str[i-1]) || (pattern[j-1] == '.'))
                        flag[i][j] = flag[i-1][j-1];
                    else if(pattern[j-1] == '*')
                    {
                        if((pattern[j-2] == str[i-1]) || (pattern[j-2] == '.'))
                            flag[i][j] = flag[i][j-2] || flag[i][j-1] || flag[i-1][j];
                        else
                            flag[i][j] = flag[i][j-2]; 
                        
                    }
                    else
                    {
                        flag[i][j] = false;
                    }
                    
                }
            }

            return flag[len1][len2];
        }
};



11. container with most water 
class Solution
{
    public:
        int maxArea(vector<int>& height)
        {
            int i = 0;
            int j = height.size()-1;
            int ret = 0;
            while(i < j)
            {
                int temp1 = min(height[i],height[j]);
                int temp2 = temp1*(j-i);
                ret = max(ret, temp2)
                if(height[i] < height[j])
                    i++;
                else
                    j--;
                
            }
            return res;
        }
};


12. integer to roman

class Solution
{
    public:
    {
        string intToRoman(int num)
        {
            vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
            vector<string> dic = {"M", "CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
            string str;
            int i = 0;
            while(num > 0 && i<dic.size())
            {
                if(num >= value[i])
                {
                    str += dic[i];
                    num -= value[i];
                }
                else
                {
                    i++;
                }
                
            }

            return str;
        }
    }
};



13. roman to integer

class Solution
{
    public:
    int romanToInt(string s)
    {
        unordered_map<string, int> m = {{"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, {"M", 1000}};
        int r = m[s.substr(0, 1)];
        for(int i = 1; i<s.size();i++)
        {
            string two = s.substr(i-1,2);
            string one = s.substr(i,1);
            r += m[two] ? m[two] : m[one];
        }

        return r;
    }
};


14. longest-common-prefix
class Solution
{
    public:
    string longestCommonPrefix(vector<string>& str)
    {
        if(str.size() == 0) return "";
        string ret = str[0];
        for(int i = 1; i<str.size();i++)
        {
            for(int j=0; j<ret.length();j++)
            {
                if(ret[j] == str[i][j]) continue;
                else 
                {
                    ret.erase(j);
                    break;
                }
                
            }
        }

        return ret;
    }
};


15. 3sums
//time O(n^2)
//nums whether or not has 3 elements whose sum is zero
//ex. nums{-1,0,1,2,-1,-4} ,  [[-1,0,1],[-1,-1,2]]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> >res;
        sort(nums.begin(),nums.end());
        if(nums.empty() || nums.front()>0 || nums.back()<0)
            return {};
        
        for(int i=0;i<nums.size();i++){
            int fix=nums[i];
            if(fix>0)   break;
            if(i>0 && fix==nums[i-1])    continue;
            //对撞指针
            int l=i+1,r=nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r]==-fix  ){
                    if(l==i+1 || r==nums.size()-1){
                        res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                        l++;r--;
                    }
                    else if(nums[l]==nums[l-1])
                        l++;
                    else if(nums[r]==nums[r+1])
                        r--;
                    else{
                        res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                        l++;r--;
                    }
                    
                }
                else if(nums[l]+nums[r]<-fix)
                    l++;
                else
                    r--;
            }
        }
        return res;
    }
};



16. 3sum-closest
nums = [-1,2,1,-4] , target = 1
sum(-1+2+1 = 2) of three int closest to the target

class Solution{
    public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int len = nums.size();
        int ins = INT_MAX;
        int sum = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<len; i++)
        {
            int l = 0;
            int r = len-1;
            while(l<r)
            {
                if(l==i)
                    l++;
                if(r==i)
                    r--;
                if(l>=r) break;
                int n = nums[i]+nums[l]+nums[r];
                int x = abs(n-target);
                if(x < ins)
                {
                    ins = x;
                    sum = n;
                }
                if(n == target)
                   return sum;
                if(n < target)
                    l++;
                if(n > target)
                    r--;
                
            }
        }
        return sum;
    }
};




17. letter combinations of a phone number
//ex "23"  output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
#include <iostream>
#include <string>
#include <vector>
#include <map> 

using namespace std;

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> res;
        if(digits.empty())
            return res;
        std::string temp;
        res.push_back(temp);
        std::map<char,std::string> maps;
        maps['2'] = "abc";
        maps['3'] = "def";
        maps['4'] = "ghi";
        maps['5'] = "jkl";
        maps['6'] = "mno";
        maps['7'] = "pqrs";
        maps['8'] = "tuv";
        maps['9'] = "wxyz";
        letterCombinations(digits, maps,res);
        return res;
    }
    
    void letterCombinations(std::string &digits, std::map<char,std::string> &maps,std::vector<std::string> &res)
    {
        //从左到右增加每个按键
        for(int j=0;j<digits.size();j++)
        {
            //之前所有按键的情况组合数
            
            int len = res.size();
            std::cout<<"j: "<<j<<std::endl;
            std::cout<<"len: "<<len<<std::endl;
           // std::cout<<len<<std::endl;
            for(int i = 0;i<len;i++)
            {
                //按键的每个情况，在之前结果上加上一个按键
                std::cout<<"i: "<<i<<std::endl;
                for(auto m:maps[digits[j]])
                {
                    res.push_back(res[i]+m);
                    for(auto m : res)
                        std::cout<<m<<std::endl;
                }
            }

            
            //删除上一步中残留的项
            std::cout<<"----"<<std::endl;
            res.erase(res.begin(),res.begin()+len);
        }

        for(auto m : res)
            std::cout<<"result is: "<<m<<std::endl;
        return;
    }
};




class Solution
{
    public:
        vector<string> LetterCombination(vector<int>& digits)
        {
            vector<string> res;
            if(digits.empty()) return {};
            string temp = "";
            res.push_back(temp);
            map<char, string>maps;
            maps['2'] = "abc";
            maps['3'] = "def";
            maps['4'] = "ghi";
            maps['5'] = "jkl";
            maps['6'] = "mno";
            maps['7'] = "pqrs";
            maps['8'] = "tuv";
            maps['9'] = "wxyz";
            for(int j = 0; j <digits.size())
            {
                int len = res.size();
                for(int i = 0; i<len;i++)
                {
                    for(auto m:maps[digits[j]])
                        res.push_back(res[i]+m);
                }
                res.erase(res.begin(),res.begin()+1);
            }
        }
};


//18. 4 sum
/*
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

*/


class Solution{
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target)
        {
            if(nums.size()<4) return {};
            sort(nums.begin(),nums.end());
            vector<vector<int>> res;
            set<vector<int>>a;
            for(int i = 0; i<nums.size()-3;i++)
            {
                if(nums[i]>target && target>0) break;
                for(int j = i+1; j<nums.size()-2;j++)
                {
                    int l = j+1;
                    int r=nums.size()-1;
                    while(l<r)
                    {
                        if(nums[i]+nums[j]+nums[l]+nums[r]<target)
                            l++
                        else if (nums[i]+nums[j]+nums[l]+nums[r]>target)
                            r--;
                        else
                        {
                            vector<int> temp{nums[i],nums[j],nums[l],nums[r]};
                            a.insert(temp);
                            l++;
                            r--;
                        }

                    }
                }
            }

        for(auto c : a)
            res.push_back(c);
        
        return res;

        }
};







19.REMOVE NTH NODE FROM END OF LIST
/*给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
*/


struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* q = new ListNode(0);
        ListNode* p = new ListNode(0);
        q = head;
        p = head;
        while(head->next != NULL)
        {
            for(int i = 0; i<n; i++)
            {
                head = head->next;
            }
            if(head == NULL)
            {
                if(q->next == NULL) return NULL;
                return q->next;
            }

            if(head->next != NULL)
            {
                head = p->next;
                p = p->next;
            }
        }

        if(q->next == NULL) return NULL;
        p->next = p->next->next;
        return q;
    }
};




20. valid-parentheses
/*
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true
*/

class Solution{
    public:
    bool isValid(string s)
    {
        if(s.length() %2 != 0) return false;
        map<char,char>wordbook;
        wordbook.insert(map<char,char>::value_type(')','('));
        wordbook.insert(map<char,char>::value_type(']','['));
        wordbook.insert(map<char,char>::value_type('}','{'));
        stack<char> mystack;
        for(int i=0; i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                mystack.push(s[i]);
            else if(s[i]==')' || s[i]=='}' || s[i]==']')
            {
                if(mystack.empty()) return false;
                if(wordbook[s[i]] == mystack.top())
                {
                    mystack.pop();
                    continue;
                }
                else return false;
            }
        }
        if(mystack.empty()) return true;
        else return false;
    }
};





21. merge two sorted lists
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

class Solution
{
    public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        else if(l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};

or iterator method:
class Solution
{
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
        {
            ListNode* prehead = new ListNode(-1);
            ListNode* prev = prehead;
            while(l1 != NULL && l2 != NULL)
            {
                if(l1->val <= l2->val)
                {
                    prev->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    prev->next = l2;
                    l2 = l2->next;
                }
                prev = prev->next;
            }
            prev->next = l1 != NULL ? l1:l2;
            ListNode* resNode = prehead->next;
            delete prehead;
            return resNode;
        }
};




22. parentheses 
//给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
class Solution
{
    public:
    void helper(int left, int right, string tmp, vector<string>& result)
    {
        if(left == 0 && right == 0)
        {
            result.push_back(tmp);
            return;
        }
        if(left>right || left<0 || right<0)
            return;
        helper(left-1, right, tmp+'(', result);
        helper(left, right-1, tmp+')', result);
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string>result;
        helper(n,n,"",result);
        return result;
    }
};






23.merge-k-sorted-lists
输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

class Solution
{
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        vector<ListNode*> longList;
        for(ListNode* start:lists)
        {
            ListNode* ptr = start;
            while(ptr != NULL)
            {
                longList.push_back(ptr);
                ptr = ptr->next;
            }
        }
        std::sort(longList.begin(),longList.end(),[](auto x, auto y){return((x->val)<(y->val));});
        if(longList.size() == 0) return NULL;
        for(size_t i = 0; i < longList.size()-1; i++)
        {
            longList[i]->next = longList[i+1];
        }
        longList[longList.size()-1]->next = NULL;
        return longList[0];
    }
};





24. swap nodes in pairs 
给定 1->2->3->4, 你应该返回 2->1->4->3.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
}；

class Solution
{
    public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        dummy->next = head;
        ListNode* cur = head;

        while(cur != NULL)
        {
            ListNode* next = cur->next;
            if(next == NULL)
                break;
            pre->next = next;
            cur->next = next->next;
            next->next = cur;

            pre = cur;
            cur = cur->next;
        }

        return dummy->next;
    }

};




25. reverse-nodes-in-k-group
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

示例 :

给定这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5


class Solution
{
    public:
        ListNode* reverseKGroup(ListNode* head, int k)
        {
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            ListNode* pre = dummy;
            ListNode* cur = head;
            ListNode* tail = dummy;
            while(true)
            {
                int count = 0;
                tail = pre;
                while(tail != NULL && count < k)
                {
                    tail = tail->next;
                    count++;
                }

                if(tail==NULL) break;

                while(pre->next != tail)
                {
                    cur = pre->next;
                    pre->next = cur->next;

                    cur->next = tail->next;
                    tail->next = cur;
                }

                pre = head;
                tail = head;
                head = head->next;
            }
        return dummy->next;
        }
};



