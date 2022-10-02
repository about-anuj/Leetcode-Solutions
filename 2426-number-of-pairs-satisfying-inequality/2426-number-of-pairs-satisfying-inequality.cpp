#define pb push_back
class Solution {
public:
    vector<int>f;
    int diff;
    long long ans=0;
    void merge(int l,int mid,int h)
    {
        int i=l,j=mid+1;
        while(i<=mid and j<=h)
        {
            if(f[i]-f[j]<=diff)
            {
              ans+=(h-j+1);
              i++;
            }  
            else
            {
               j++;
            }
        }
        //merging
        i=l,j=mid+1;
        int k=l;
        int temp[(int)f.size()];
        while(i<=mid and j<=h)
        {
            if(f[i]<=f[j])
                temp[k++]=f[i++];
            else
                temp[k++]=f[j++];
        }
        
        while(i<=mid) temp[k++]=f[i++];
        while(j<=h) temp[k++]=f[j++];
        
        for(k=l;k<=h;k++) f[k]=temp[k];
    }
    void mergesort(int i,int j)
    {
        if(i<j)
        {
            int mid=i+(j-i)/2;
            mergesort(i,mid);
            mergesort(mid+1,j);
            merge(i,mid,j);
        }
    }
    long long numberOfPairs(vector<int>& n1, vector<int>& n2, int diff) {
        for(int i=0;i<n1.size();i++) f.pb(n1[i]-n2[i]);
        this->diff=diff;
        int st=0,end=n1.size()-1;
        mergesort(st,end);
            return ans;
    }
};