#include <iostream>
#include <vector>

using namespace std;


long fib(int n)
{
    if (n <= 1)
        return 1;
    else
        return fib(n-1) + fib(n -2);
}
/*************最大子序列**************/
int maxSubSum1(const vector<int> &a)
{
    int maxSum = 0;
    for (int i = 0; i <a.size(); i++)
    {
        for (int j = i; j < a.size(); j++)
        {
            int temSum = 0;
            for (int k = i; k < j; k++)
            {
                temSum += a[k];
            }
            maxSum = temSum > maxSum ? temSum : maxSum;
        }
    }
    return maxSum;
}

int maxSubSum2(const vector<int> &a)
{
    int maxSum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int temSum = 0;
        for (int j = i; j < a.size(); j++)
        {
            //int temSum = 0;
            temSum += a[j];
            maxSum = temSum > maxSum ? temSum : maxSum;
        }
    }
    return maxSum;
}

int maxSubSum3(const vector<int> &a, int left, int right)
{
    if (left == right)
        if (a[left] > 0)
            return a[left];
        else
            return 0;

    int center = (left + right) / 2;
    int maxLeftSum = maxSubSum3(a, left, center);
    int maxRightSum = maxSubSum3(a, center + 1, right);

    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for (int i = center; i >= left; i--) // 这里很奇怪， 换成i++就不行了？？？？
    {
        leftBorderSum += a[i];
        maxLeftBorderSum = maxLeftBorderSum > leftBorderSum ? maxLeftBorderSum : leftBorderSum;
    }
    int maxRightBorderSum = 0, rightBorderSum = 0;
    for (int i = center + 1; i <= right; i++)
    {
        rightBorderSum += a[i];
        maxRightBorderSum =maxRightBorderSum > rightBorderSum ?  maxRightBorderSum : rightBorderSum;
    }

    cout << maxLeftSum << maxRightSum << maxLeftBorderSum + maxRightBorderSum << endl;
    return (maxLeftSum > maxRightSum ? maxLeftSum : maxRightSum) > (maxLeftBorderSum + maxRightBorderSum) ? (maxLeftSum > maxRightSum ? maxLeftSum : maxRightSum) : (maxLeftBorderSum + maxRightBorderSum);


}
//简单 但又牛逼的想法啊....
int maxSubSum4(const vector<int> &a)
{
    int maxSum = 0, thisSum = 0;

    for (int j = 0; j < a.size(); j ++)
    {
        //一直在累加
        thisSum += a[j];
        //每次判断取其最大值
        maxSum = thisSum > maxSum ? thisSum : maxSum;
        //如果小于零了，就从下一个位置 重新开始累加
        if (thisSum < 0)
            thisSum = 0;
    }
    return maxSum;
}
//排序，冒泡吧
void swap(int &i, int &j);
void swap(int &i, int &j)
{
    i = i + j;
    j = i - j;
    i = i - j;
}

void easySort(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
    {
        for (int j = 0; j < a.size() - i; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

//二分查找 递归, 所有递归都可以用while循环实现？
int findItem(const vector<int> &a, int item, int left, int right)
{
    int mid = (left + right)/2;
    //防止 进入无线递归
    if (left == right && a[left] != item)
        return -1;
    //cout << a[mid] << endl;
    if (a[mid] > item)
        findItem(a, item, left, mid);
    else if (a[mid] < item)
        findItem(a, item, mid, right);
    else if (a[mid] == item)
        return mid;
}

int main()
{
    //cout << fib(10);

    vector<int> a{1, -2, 3, 6, -1, 5, -5, 3};
    //cout << maxSubSum1(a);
    //cout << maxSubSum2(a);
    //cout << maxSubSum3(a, 0, a.size() - 1);
    //cout << maxSubSum4(a);
    easySort(a);
    for (auto i : a)
        cout << i << " ";
    cout << endl;
    cout << findItem(a, -9, 0, a.size()-1);
}





















