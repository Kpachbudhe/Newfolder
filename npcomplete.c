# include<stdio.h>
int max (int a, int b){return (a>b)?a:b;}
int knapSack(int W,int wt[],int val[],int n)
{
    int i,w;
    int k[n+1][w+1];
    for(i=0;i<n;i++)
    {
        for(w=0;w<=W;w++)
        {
            if(i==0|| w==0)
                k[i][w]=0;
            else if(wt[i-1]<=w)
                k[i][w]=max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
            else
                k[i][w]=k[i-1][w];

        }
    }
    return k[i][w];
}
int main()
{
    int i,n,val[20],wt[20],w;

    printf("Enter number of items: ");
    scanf("%d",&n);

    printf("Enter value & wieght of items: \n");
    for(i=0;i<=n;++i){
        scanf("%d%d",&val[i],&wt[i]);
    }
    printf("Enter size of knapsack: ");
    scanf("%d",&w);

    printf("%d",knapSack (w,wt,val,n));
    return 0;

}




