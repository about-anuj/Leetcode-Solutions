class Solution {
public:
    
    int calc(string s,int k, int i, int n){
        if(n<k) return 0;
        
        int count[26]={0};
        
        for(int j=i;j<n;j++)
            count[s[j]-'a']++;
        
        for(int mid=i;mid<n;mid++){
            if(count[s[mid]-'a']>=k) continue;
            int midnxt=mid+1;
            while(midnxt<n and count[s[midnxt]-'a']<k) midnxt++;
            return max(calc(s,k,i,mid),calc(s,k,midnxt,n));
        }
        return n-i;
    }
    int longestSubstring(string s, int k) {
       return calc(s,k,0,s.size()); 
    }
};