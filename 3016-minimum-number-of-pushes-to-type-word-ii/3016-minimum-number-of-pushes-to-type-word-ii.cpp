class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<long long> mp(26,0);
        long long result =0;
        for(auto &ch : word){
            mp[ch-'a']++;
        }
        sort(mp.begin(),mp.end(),greater<int>());
        for(int i =0;i<26;i++){
            int pressed = i/8 +1;
            result +=  1LL*(pressed * mp[i]);
        }
        return result;

    }
};