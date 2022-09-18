class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
     int res=0;
        for(int i=0;i<=31;i++)
        {
            //check wether last bit is set or not
            int last_bit=n & 1;
            //set this bit in reverse position by left shifting 31-i
            int shifting=last_bit<<(31-i);
            //take or so that we can fix this bit to our answer
            res= res | shifting;
            
            //right shift n so that we can check next bit n/=2 or n=n>>1
            n=n>>1;
        }
        return res;
    }
};