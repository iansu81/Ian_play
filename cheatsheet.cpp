priority_queue<int, vector<int>, greater<int>> occupied_room;
// 如果沒有greater, default是less, 代表最大的會在最上面, greater最小的會在最上面


auto comp = [](const pair<int, int> &A, const pair<int, int> &B)
{
    return A.second > B.second;
};
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp) > q(comp);
for (auto it = freq.begin(); it != freq.end(); ++it){
    q.push(make_pair(it->first, it->second));
    if(q.size() > k) q.pop();
}


sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
{
    return a[0] < b[0];
});



如果是在嚴格遞增陣列中:
lower_bound( begin,end,num)：從陣列的begin位置到end-1位置二分查詢第一個大於或等於num的數字，找到返回該數字的地址，不存在則返回end。通過返回的地址減去起始地址begin,得到找到數字在陣列中的下標。

upper_bound( begin,end,num)：從陣列的begin位置到end-1位置二分查詢第一個大於num的數字，找到返回該數字的地址，不存在則返回end。通過返回的地址減去起始地址begin,得到找到數字在陣列中的下標。

如果是在從大到小的排序陣列中：
lower_bound( begin,end,num,greater() ):從陣列的begin位置到end-1位置二分查詢第一個小於或等於num的數字，找到返回該數字的地址，不存在則返回end。通過返回的地址減去起始地址begin,得到找到數字在陣列中的下標。

upper_bound( begin,end,num,greater() ):從陣列的begin位置到end-1位置二分查詢第一個小於num的數字，找到返回該數字的地址，不存在則返回end。通過返回的地址減去起始地址begin,得到找到數字在陣列中的下標。