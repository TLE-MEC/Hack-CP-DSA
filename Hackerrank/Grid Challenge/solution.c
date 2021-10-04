#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef long long ll;
int main() {
    char m[105][105];
    ll t,n,i,j,f,cnt[26],k;
    ll a[105][105];
    printf("Enter number of rows: ");
    scanf("%lld",&t);
    printf("\nEnter number of columns: ");
    scanf("%lld",&n);
    while(t--)
        {
        for(i=0;i<n;i++)
            {
            scanf("%s",m[i]);
        }
        for(i=0;i<n;i++)
            {
            memset(cnt,0,sizeof(cnt));      /* sets all 26 values of cnt[] to 0 */
            for(j=0;j<n;j++)
                {
                cnt[m[i][j]-'a']++;;
            }
            j=0;
            for(k=0;k<26;k++)
                {
                while(cnt[k]>0)
                    {
                    a[i][j]=k;
                    j++;
                    cnt[k]--;
                }
            }
        }
        f=0;
        for(j=0;j<n&&f==0;j++)
            {
            for(i=0;(i+1)<n&&f==0;i++)
                {
                if(a[i][j]>a[i+1][j])       /* checking if it's in ascending order */
                    {
                    f=1;
                }
            }
        }
        if(f==0)
            {
            printf("YES\n");
        }
        else
            {
            printf("NO\n");
        }
    }
    return 0;
}
