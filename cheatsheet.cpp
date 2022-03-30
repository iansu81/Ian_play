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
