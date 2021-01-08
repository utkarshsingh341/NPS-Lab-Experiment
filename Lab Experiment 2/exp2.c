#include<stdio.h>
int a[10][10],n,d[10],p[10];

void bellmanford(int s)
{
	int i,u,v;
	for(i=1;i<n;i++)
	{
		for(u=0;u<n;u++)
		{
			for(v=0;v<n;v++)
			{
				if(d[v]>d[u]+a[u][v])
				{
					d[v]=d[u]+a[u][v];
					p[v]=u;
				}
			}
			
		}
	}
			for(u=0;u<n;u++)
			{
				for(v=0;v<n;v++)
				{
					if(d[v]>d[u]+a[u][v])
					{
						printf("Negative Edge");
					}
				}
			}
}


int main()
{
	printf("Enter no of vertices: ");
	scanf("%d",&n);
	printf("Enter the Adjacency Matrix:\n");
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	
	int source=0;
	
	for(source=0;source<n;source++)
	{
		for(i=0;i<n;i++)
		{
			d[i]=999;
			p[i]=-1;
		}

	d[source]=0;
	
	bellmanford(source);
	printf("Router %d\n",source);
	
	for(i=0;i<n;i++)
	{
		if(i!=source)
		{
			j=i;
			while(p[j]!=-1)
			{
				printf("%d <- ",j);
				j=p[j];
			}
		}
		printf("%d\tcost%d\n\n",source,d[i]);
	}
}
}
