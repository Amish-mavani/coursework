#include<stdio.h>
void bestFit(int bsize[], int nb, int psize[], int np)
{
    int i,j,sub,low=999;
    static int barr[10],parr[10];
    for(i = 0; i < 10; i++)
        {
            barr[i] = 0;
            parr[i] = -1;
        }
    for(i=0; i<np; i++)
    {
        for(j=0; j<nb; j++)
        {
            if(barr[j]!=1)
            {
                sub = bsize[j]-psize[i];
                if(sub>=0)
                {
                    if(low>sub)
                    {
                        parr[i] = j;
                        low = sub;
                    }
                }
            }
        }
        barr[parr[i]]=1;
        low=1000;
    }
    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size");
    for(i=0;i<=np;i++)
    {
    	printf("\n%d\t\t%d\t\t",i,psize[i]);
        if(parr[i]!=-1)
        {
			printf("%d\t\t\t%d",parr[i],bsize[parr[i]]);
	    }
    }
}

void firstFit(int bsize[], int nb, int psize[], int np)
{
    int i,j;
    static int barr[10],parr[10];
    for(i = 0; i < 10; i++)
        {
            barr[i] = 0;
            parr[i] = -1;
        }
    for(i=0;i<np;i++)
    {
        for(j=0;j<nb;j++)
        {
            if(bsize[j] >= psize[i] && barr[j]==0)
            {
                parr[i] = j;
                barr[j] = 1;
                break;
            }

        }
    }
    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size");
    for(i=0;i<=np;i++)
    {
    	printf("\n%d\t\t%d\t\t",i,psize[i]);
        if(parr[i]!=-1)
        {
			printf("%d\t\t\t%d",parr[i],bsize[parr[i]]);
	    }
    }
}

void worstFit(int bsize[], int nb, int psize[], int np)
{
	int i,j,sub,low=0;
	static int barr[10],parr[10];
    for(i = 0; i < 10; i++)
    {
        parr[i] = -1;
        barr[i] = 0;
    }
	for (i=0; i < np; i++)
    {
	    for(j = 0; j < nb; j++)
	    {
	        if(bsize[j] >= psize[i] && barr[j]==0)
                {
                	
                    sub = bsize[j]-psize[i];
                  	if(sub>low)
                   	{
                       	parr[i] = j;
                       	low = sub;
                   	}
                
                }
        }
        barr[parr[i]]=1;
        low=1;
    }
 
    printf("\nProcess No.\tProcess Size\tBlock no.\tblock Size\n");
    for (int i = 0; i < np; i++)
    {
        printf("%d \t\t %d \t\t", i, psize[i]);
        if (parr[i] != -1)
        {
            printf("%d\t\t%d\t\t\n",parr[i],bsize[parr[i]]);
        }   
    }
}



int main()
{
    int az,i,bsize[20],nb,np,psize[20];
    printf("enter the num. of memory block = ");
    scanf("%d",&nb);
    printf("enter the size of \n"); 
    for(i=0;i<nb;i++)
    {
        printf("momory block %d = ",i);
        scanf("%d",&bsize[i]);
    }
    printf("enter the num of process = ");
    scanf("%d",&np);
    printf("enter the size of \n"); 
    for(i=0;i<np;i++)
    {
        printf(" process %d = ",i);
        scanf("%d",&psize[i]);   
    }

    printf("select memory allocation ");
    printf(" \n1. Best fit\n2. First fit\n3. Worst fit");
    printf("\nenter the value :  ");
    scanf("%d",&az);
      
    switch(az)
    {
        case 1:
        bestFit(bsize, nb, psize, np);
        break;

        case 2:
        firstFit(bsize, nb, psize, np);
        break;
        
        case 3:
        worstFit(bsize, nb, psize, np);
        break;
    }
    return 0;
}
