class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> mp(26,0);
        int result =0;
        for(auto &ch : word){
            mp[ch-'a']++;
        }
        sort(mp.begin(),mp.end(),greater<int>());
        for(int i =0;i<n;i++){
            int pressed = i/8 +1;
            result += pressed * mp[i];
        }
        return result;

    }
};