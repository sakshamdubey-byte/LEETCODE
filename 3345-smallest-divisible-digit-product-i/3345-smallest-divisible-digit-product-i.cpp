class Solution {
public:
int product(int n)
{
    int p=1;
    while(n)
    {
        p=p*(n%10);
        n=n/10;
    }
    return p;
}
    int smallestNumber(int n, int t) {
        while(product(n)%t!=0)
        {
            n++;
        }
        return n;
    }
};