#include <stdio.h>

int main() {
    int p,r;
    printf("Enter the no. of processes: ");
    scanf("%d",&p);
    printf("Enter the no. of resources: ");
    scanf("%d",&r);
    int all[p][r],max[p][r],nee[p][r],ava[r],tot[r],seq[p],com[p],cou=0;
    for(int i=0;i<p;i++)
    {
        printf("\n\nProcess %d \n",i+1);
        for(int j=0;j<r;j++)
        {
            printf("Maximum value for resource %d: ",j+1);
            scanf("%d",&max[i][j]);
        }

        for(int j=0;j<r;j++)
        {
            printf("Allocated from resource %d: ",j+1);
            scanf("%d",&all[i][j]);
        }
    }
    printf("\n\n");
    for(int j=0;j<r;j++)
    {
        printf("Enter total value of resource %d: ",j+1);
        scanf("%d",&tot[j]);
    }
    for(int j=0;j<r;j++)
    {
        ava[j]=tot[j];
    }
    for(int j=0;j<p;j++)
    {
        com[j]=0;
    }
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            ava[j]-=all[i][j];
        }
    }
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            nee[i][j]=max[i][j]-all[i][j];
        }
    }

    while( cou<p)
    {
        int runcheck=0;
        for(int j=0;j<p;j++)
        {
            if(com[j]==0)
            {
                int k;
                for(k=0;k<r;k++)
                {
                    if(nee[j][k]>ava[k])
                        break;
                }
                if(k==r)
                {
                    for(int i=0;i<r;i++)
                    {
                        ava[i]+=all[j][i];
                    }
                    seq[cou]=j;
                    com[j]=1;
                    cou++;
                    runcheck=1;
                }
            }
        }
        if(runcheck==0)
        {
            printf("\n\nThe system is currently in  not safe state.\n");
            return 0;
        }
    }

    printf("\n\nThe system is currently in  not safe state and \n< ");
    for(int j=0;j<p;j++)
    {
        printf("P%d ",seq[j]);
    }
    printf("> is the safe sequence.\n");
    return 0;
}
