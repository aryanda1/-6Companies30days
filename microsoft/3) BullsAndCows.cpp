class Solution {
public:
    string getHint(string secret, string guess) {
        int freq[10]={0};
        int freq2[10]={0};
        int bulls = 0;
        for(int i = 0;i<secret.length();i++)
            if(secret[i]==guess[i])
                bulls++;
            else{
                freq[secret[i]-'0']++;
                freq2[guess[i]-'0']++;
            }
        int crows = 0;
        for(int i = 0;i<10;i++)
            if(freq[i] && freq2[i])
                crows+=min(freq[i],freq2[i]);
        return to_string(bulls)+'A'+to_string(crows)+'B';
    }
};