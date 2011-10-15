int K,i,j,k;
int modd(int k){
    long long ans=1;
    long long pow=2;
    while(k){
        if(k & 1) ans=(ans*pow)%K;
        pow=(pow*pow)%K;
        k=k/2;
    }
    return ans;
}
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&K);
        printf("%d\n",modd(modd(n)));
    }
    return 0;
}
