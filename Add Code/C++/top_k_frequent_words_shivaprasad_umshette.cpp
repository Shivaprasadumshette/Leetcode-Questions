Name : shivaprasad Umshette
           Dificulty -
       Medium
           Problem number -
       692 link - https : // leetcode.com/problems/top-k-frequent-words/

                          class Solution
{
    struct cmp
    {
        bool operator()(pair<int, string> a, pair<int, string> b) const
        {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };

public:
    vector<string> topKFrequent(vector<string> &a, int k)
    {
        unordered_map<string, int> mp;
        vector<pair<int, string>> v;
        for (int i = 0; i < a.size(); i++)
            mp[a[i]]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for (auto x : mp)
        {
            pq.push({x.second, x.first});
            if (pq.size() > k)
                pq.pop();
        }
        vector<string> res(k);
        while (pq.size())
        {
            res[--k] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};