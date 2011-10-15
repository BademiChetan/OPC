
double square(double n)
{
       return n*n;
}

main()
{
    int t,i=1,k;
    double n,ans=2;
    stdin(t);
    while(t)
    {
            stdin(n);
            stdin(k);
            
            while(i<=n)
            {
                   ans = square(ans);
                   i++; 
            }
            int woo = ans/k;
            ans = ans -( woo*k);
            stdout(ans);
            t--;
    }

}

