#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void initMap(map<string,int>& Map,vector<string>& words)
    {
        for(int i=0;i<words.size();i++)
            Map[words[i]]+=1;
    }

    vector<int> findSubstring(string s, vector<string>& words)
    {
        map<string,int> Map;

        vector<int> res;
        initMap(Map,words);
        bool MapChanged=false;
        int cnt=words.size();
        int slen=s.length();
        int singlelen=words[0].length();
        int wordslen=words.size();
        for(int i=0;i<=slen-wordslen*singlelen;i++)
        {
            string subStr=s.substr(i,singlelen);
            int j=i;
            while(Map[subStr]!=0&&j+singlelen<=slen)
            {
                Map[subStr]--;
                cnt--;
                MapChanged=true;
                j+=singlelen;
                subStr=s.substr(j,singlelen);
                if(Map[subStr]==0)break;
            }
            if(cnt==0)res.push_back(i);
            if(MapChanged)
            {
                Map.clear();
                initMap(Map,words);
                MapChanged=false;
                cnt=wordslen;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}
