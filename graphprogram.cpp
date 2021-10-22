#include <iostream.h>
#include <conio.h>

class graph
{
	private:int n;
		int **a;
		int *reach;
		int *pos;
	public:graph(int k=10);
		void create();
		void dfs();
		void dfs(int v,int label);
		int begin(int v);
		int nextvert(int v);
};
void graph::graph(int k)
{
	n=k;
	a=new int *[n+1];
	reach=new int[n+1];
	pos=new int [n+1];
	for(int i=1;i<=n;i++)
		pos[i]=0;
	for(int j=1;j<=n;j++)
		a[j]=new int[n+1];
}
void graph::create()
{
	for(int i=1;i<=n;i++)
	{
		cout<<"Enter the "<<i<<"th row of matrix a:
";
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int k=1;k<=n;k++)
		reach[k]=0;
}
void graph::dfs()
{
	int label=0;
	for(int i=1;i<=n;i++)
		if(!reach[i])
		{
			label++;
			dfs(i,label);
		}
	cout<<"
The contents of the reach array is:
;
	for(int j=1;j<=n;j++)
		cout<<reach[j]<<"	";
}
void graph::dfs(int v,int label)
{
	cout<<v<<"	";
	reach[v]=label;
	int u=begin(v);
	while(u)
	{
		if(!reach[u])
			dfs(u,label);
		u=nextvert(v);
	}
}
int graph::begin(int v)
{
	if((v<1)&&(v>n))
		cout<<"Bad input
";
	else
		for(int i=1;i<=n;i++)
			if(a[v][i]==1)
			{
				pos[v]=i;
				return i;
			}
	return 0;
}
int graph::nextvert(int v)
{
	if((v<1)&&(v>n))
		cout<<"Bad input
";
	else
		for(int i=pos[v]+1;i<=n;i++)
			if(a[v][i]==1)
			{
				pos[v]=i;
				return i;
			}
	return 0;
}
void main()
{
	clrscr();
	int x;
	cout<<"Enter the no of vertices:
";
	cin>>x;
	graph g(x);
	g.create();
	cout<<"dfs is.....";
	g.dfs();
	getch();
}
