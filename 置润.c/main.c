#include <stdio.h>

int main()
{
    int n,m,i,j,k,time;
    scanf("%d %d",&n,&m);
    int array[n+1];
    int a[m];
    array[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&array[i]);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<m;i++)
    {
        time=0;
        for(j=0,k=1;j<a[i]&&k<=n;j++)
        {
            time++;
            if(time>array[k])
            {
                time--;
                k++;
            }
        }
        printf("%d\n",time);
    }

    return 0;
}
