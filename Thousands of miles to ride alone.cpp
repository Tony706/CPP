#include <iostream>
int main()
{
    int B, C,CurrTest=1;
    scanf("%d",&B);
    
	while (CurrTest <= B)
		{
        scanf("%d",&C);
        float graph[C][C];
        float p[C - 2];
        
        for (int i = 0; i < C; i++)
            for (int j = 0; j < C; j++)
                scanf("%f",&graph[i][j]);

        for (int i = 0; i < C - 2; i++)
            scanf("%f",&p[i]);

        for (int i = 0; i < C; i++)
            for (int j = i + 1; j < C; j++)
                if (j - 1 < C - 2)
                    graph[i][j] *= p[j - 1];
       
        for (int i = 0; i < C; i++)
            for (int j = i+1; j < C; j++)
                for (int k = i+1; k < j; k++)
                    if (graph[i][k] * graph[k][j] > graph[i][j])
                        graph[i][j] = graph[i][k] * graph[k][j];
                    
        if (graph[0][C - 1] == 0 || graph[0][C-1]<0.0001)
            printf("Case %d: Cannot reach!\n",CurrTest);
        else
   			printf("Case %d: %.4f\n",CurrTest, graph[0][C - 1]);	
        CurrTest++;
    	}
}

