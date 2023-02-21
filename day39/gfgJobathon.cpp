void findPrime(vector<bool> &pr)
{
    for (int i = 2; i * i <= 25; i++)
    {
        if (pr[i] == true)
        {
            for (int j = i * 2; j <= 25; j += i)
            {
                pr[j] = false;
                //   cout<<"false";
            }
        }
    }
}
vector<int> findBots(vector<string> &usernames, int n)
{
    // code here
    vector<bool> pr(true, 25);
    findPrime(pr);
    pr[1] = false;
    vector<int> ans;
    for (int i = 0; i < usernames.size(); i++)
    {
        unordered_set<char> st;
        int count = 0;
        string str = usernames[i];
        for (int j = 0; j < str.size(); j += 2)
        {
            if (st.find(str[j]) == st.end())
            {
                count++;
                st.insert(str[j]);
            }
        }
        if (pr[count])
        {
            ans.push_back(1);
        }
        else
            ans.push_back(0);
    }
    return ans;
}