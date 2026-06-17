class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.length();
        vector<long long>lengths(n);
        long long current_len=0;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(current_len>0) current_len--;
            }
            else if(s[i]=='#'){
                current_len *=2;
            }else if(s[i]=='%'){

            }else{
                current_len++;
            }
            lengths[i]=current_len;
        }
        if(k>=current_len) return '.';
        for(int i=n-1;i>=0;i--){
            long long len_before=(i==0) ? 0 : lengths[i-1];
            if(s[i]=='*'){

            }else if(s[i]=='#'){
                long long prev_len=len_before;
                if(k>=prev_len){
                    k %=prev_len;
                }
            }else if(s[i]=='%'){
                long long  total_len=lengths[i];
                k=total_len-1-k;
            }else {
                if(k==lengths[i]-1){
                    return s[i];
                }
            }
        }
        return '.';
    }
};