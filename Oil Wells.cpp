#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
static int input[2000000],S1[2000000],S2[2000000],S3[2000000];
int randommin(int rdm)
{
    long minvalue=0;
    time_t t;
    srand((unsigned) time(&t));
    
    if(rdm<=30000)
    	{
        minvalue=rand()%(rdm-1);
        return minvalue;
    	}
    else
    	{
        while(rdm>30000)
        	{
            minvalue += rand()%30000;
            rdm=rdm-30000;
        	}
        	
        minvalue += rand()%(rdm-1);
        return minvalue;
    	}
}
void sort(int n,int* a)
{
    int q,temp,w;
    for(q=0;q<n;q++)
		{
        for(w=q+1;w<n;w++)
			{
            if(a[q] > a[w])
				{
                temp = a[q];
                a[q] = a[w];
                a[w] = temp;
            	}
        	}
    	}
}
long select(int q,int* S,int num)
{
    int vm = 0,m = 0,i,n1=0,n2=0,n3=0;
    
    if(num < 38)
		{
        sort(num,S);
        return S[q-1];
    	}
    else
		{ 
        vm = randommin(num);
        m = S[vm];
        n1 = n2 = n3 = 0;
        
        for(i=0;i<num;i++)
            if(S[i] < m)
				{
                S1[n1] = S[i];
                n1++;
            	}
            else if(S[i] == m)
				{
                S2[n2] = S[i];
                n2++;
            	}
            else
				{
                S3[n3] = S[i];
                n3++;
            	}
        if(n1 >= q) return(select(q,S1,n1));
        else if(n1 + n2 >= q) return m;
        else return(select(q - n1 - n2,S3,n3));
    	}
}
int main()
{
    int x;
    long result = 0;
    long n = 0;
    long q = 0;
    long i = 0;
    
    while(scanf("%d,%d",&x,&input[i]) != EOF)
		{
        i++,n++;
    	}
    
    q = (n + 1)/2;
    result = select(q,input,n);
    printf("%ld\n",result);
}

