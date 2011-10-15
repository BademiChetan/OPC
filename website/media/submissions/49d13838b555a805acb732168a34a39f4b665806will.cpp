#include <iostream>

using namespace std;

typedef long long int LL;

const int a = 659;
const LL base = 4194319; // random prime :D
const LL aInv = 3048678; // inverse of a mod base (i.e., (a * aInv) % base == 1) useful for division

LL modpow(int b, LL exp) {
    if (exp == 0) return 1;
    else if (exp == 1) return b;
    LL res = modpow(b, exp / 2);
    res *= res;
    res %= base;
    if (exp & 1)
        res = (res * b) % base;
    return res;
}

int main()
{
    LL T, Q, M, K, N;
    char str[50001];               
    int chHashes[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };
    
    cin>>T;
    while(T--){
        cin>>N;
        cin>>str;
        cin>>Q;
        for(LL i=1;i<=Q;i++){
            cin>>M>>K;       
            LL Count=0;
            
            LL hashValue = 0, revHashValue = 0;
            const LL revHashPower = modpow(a, K - 1);
            for (LL i = M; i < M+K; ++i) {
                hashValue *= a;
                hashValue += chHashes[str[i] - 'a'];
                hashValue %= base;
                revHashValue = (revHashValue * aInv) % base;
                revHashValue += chHashes[str[i] - 'a'] * revHashPower;
                revHashValue %= base;
            }
                //hash calculated now next
            LL FwdHash = hashValue;
            LL BckHash = revHashValue;
            //cout<<" Hashes FWD:"<<FwdHash<<" Back:"<<BckHash<<endl;
            
            hashValue = 0, revHashValue = 0;
            for (LL i = 0; i < K; ++i) {
                hashValue *= a;
                hashValue += chHashes[str[i] - 'a'];
                hashValue %= base;
                revHashValue = (revHashValue * aInv) % base;
                revHashValue += chHashes[str[i] - 'a'] * revHashPower;
                revHashValue %= base;
            }
            //cout<<" Hashes FWD:"<<hashValue<<" Back:"<<revHashValue<<endl;
            
            if (hashValue == FwdHash)Count++;
            
            LL k=K;
            for (int i = k; str[i]; ++i) {
                int toBeRemoved = chHashes[str[i - k] - 'a'], toBeAdded = chHashes[str[i] - 'a'];
                hashValue = (hashValue - toBeRemoved * revHashPower) % base;
                if (hashValue < 0) hashValue = (base + hashValue) % base;
                hashValue *= a;
                hashValue += toBeAdded;
                hashValue %= base;
        
                
                revHashValue = (revHashValue - toBeRemoved) % base;
                if (revHashValue < 0) revHashValue = (base + revHashValue) % base;
                revHashValue = (revHashValue * aInv) % base;
                revHashValue += toBeAdded * revHashPower;
                revHashValue %= base;
                
                //cout<<" Hashes FWD:"<<hashValue<<" Back:"<<revHashValue<<endl;
                if (hashValue == FwdHash)// && revHashValue == BckHash)
                    Count++;
            }
            cout<<Count<<endl;
        }
    }//end of while    
}
