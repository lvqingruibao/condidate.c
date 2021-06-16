#include<stdio.h>
#include<string.h>
#define N 20


typedef struct candidate
    {
        char name[N];
        int count;
        
    }CANDIDATE;

 
int Election (CANDIDATE can[],int n, int elector)
{
    char name [N];
    int i,j;
    int flag,fail=0;
    for (j=0; j<elector; j++)
    {
        flag = 0;
        gets(name);
        
        for(i=0 ; i<3 ; i++)
        {
            if(strcmp(can[i].name, name)==0)
            {
                can[i].count++;
                flag = 1;
                break;
            }
        }
        
        if(flag==0)
        {
            fail++;
        }
    }
    return fail;
}




int main()
{
    
    
    CANDIDATE can[3];
    int i,j,A;
    char name[N];
    
    for (i=0; i<3; i++)
    {
        scanf("%s",name);
        strcpy(can[i].name, name);
        can[i].count=0;
    }
    A=Election(can, 3, 10);
    printf("Election result :\n");
    for (j=0; j<3; j++)
    {
        printf("%-8s%d\n",can[j].name,can[j].count);
    }
    printf("废票：%d",A);
}
