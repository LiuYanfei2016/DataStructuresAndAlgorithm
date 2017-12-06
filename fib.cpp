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
    for (int i = center; i >= left; i--)
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
int main()
{
    //cout << fib(10);

    vector<int> a{1, -2, 3, 6, -1, 5, -5, 3};
    //cout << maxSubSum1(a);
    //cout << maxSubSum2(a);
    cout << maxSubSum3(a, 0, a.size() - 1);
}
