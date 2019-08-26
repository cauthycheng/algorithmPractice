//全排列 
//1 递归法


#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        helper(res,nums,0);
        return res;
    }

    void helper(vector<vector<int> >& res,vector<int>& nums,int start){
        if(start>=nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++)
        {
            swap(nums[i],nums[start]);
            helper(res,nums,start+1);
            swap(nums[i],nums[start]);
        }
    }

    void printArray(vector<vector<int>> out)
    {
        for( int i=0;i<out.size();i++ )
        {
            for(int j=0;j<out[i].size();j++)
            {
                cout<<out[i][j]<<" ";
            }
            cout <<endl;
        }

    }

};


int main()
{
    vector<vector<int>> out;
    cout<<"please input 9 numbers:"<<endl;
    vector<int> vec ={1,2,3};
//    int x;
//    for(int i=0;i<9;i++)   { cin>>x;vec.push_back(x);}



    Solution *solution=new Solution();
    out=solution->permute(vec);
    solution->printArray(out);


}


//2堆排序
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> res;
        vector<bool> flag(nums.size(),false);//标记元素是否被访问过
        return HDFS(results,res,flag,nums,0);
    }
    vector<vector<int>> HDFS(vector<vector<int>> &results,vector<int> &res,vector<bool> &flag,vector<int> nums,int dep){
        if(dep==nums.size()){//达到树叶
            results.push_back(res);
        }
        for(int i=0;i<nums.size();i++){//每层都对每个节点进行检测
            if(!flag[i]){
                flag[i]=true;//访问节点
                res.push_back(nums[i]);
                HDFS(results,res,flag,nums,dep+1);  //进入下一层
                res.pop_back();//往上一层回退
                flag[i]=false;
            }
        }
        return results;
    }
};