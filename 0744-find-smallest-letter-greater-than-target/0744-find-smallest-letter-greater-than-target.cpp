class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int>diff(letters.size());
        for(int i=0;i<letters.size();i++){
            diff[i] = (int)letters[i];
        }
        int tar = (int)target;
        for(int i=0;i<letters.size();i++){
            if(diff[i] > tar){
                return char(diff[i]);
            }
        }
        int p = *min_element(diff.begin(),diff.end());
        return char(p);


    }
};