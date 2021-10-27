#include<stdio.h>
#include<fstream>
#include<iostream>
#include<graphics.h>
#include <limits.h> 
#include <bits/stdc++.h>
#include <conio.h>
#define INF 99999
double adj[100][100];
int Fcoord[100][2];

int distcal=0;
void add_edge(int u,int v,double w );
void dijkstra(double graph[][100],int src, int V);
void BellmanFord(int graph[][3], int V, int E, int src);
void primMST(int graph[][100],int V);
void kruskalMST(int cost[][100],int V);
void floydWarshall (int graph[][4],int V);
int find(int i,int parent[]);
void union1(int i, int j,int parent[]);
void printMST(int parent[], int graph[][100],int V);
int minKey(int key[], bool mstSet[],int V);
int minDistance(int dist[], bool sptSet[],int V);
int printSolution(int dist[],int V);
using namespace std;

int main() 
 {   double in;	
	int num;  
	fstream inputfile; 
	char fileselect=' ';
	cout<<endl;
	back:
	cout<<"Select how much inputs you want to use :\n \nFor 10 use 1, Similarly for 20 use 2. Use the same procedure till 90. For 100 use 0 \n\n";
	fileselect= _getch();
	switch(fileselect)
	{		
	case '1':
	{	
	inputfile.open("input10.txt"); 
	break;
	}
	case '2':
	{	
	inputfile.open("input20.txt"); 
	break;
	}
	case '3':
	{	
	inputfile.open("input30.txt"); 
	break;
	}
	case '4':
	{	
	inputfile.open("input40.txt"); 
	break;
	}
	case '5':
	{	
	inputfile.open("input50.txt"); 
	break;
	}
	case '6':
	{	
	inputfile.open("input60.txt"); 
	break;
	}
	case '7':
	{	
	inputfile.open("input70.txt"); 
	break;
	}
	case '8':
	{	
	inputfile.open("input80.txt"); 
	break;
	}
	case '9':
	{	
	inputfile.open("input90.txt"); 
	break;
	}
	case '0':
	{	
	inputfile.open("input100.txt"); 
	break;
	}
	default:
	{
	cout<<"Wrong Choice";
	goto back;
	break;
	}
	
	}
	
	string data;
    inputfile>>data;	
    inputfile>>num;   
 	
	cout<<"\n\n\tINPUT FILE"<<"\n";
	cout<<"\n";
	cout<<"Total Nodes : "<<num<<"\n";
	float cord[num][2];
   
 	for(int i=0;i<num;i++)
  	 {
  	 inputfile >> in;	
   			 for(int j=0;j<2;j++)
   				{
   				     inputfile >> in; 
   				     cord[i][j]=in	;	
				}
   	 }
   	 for(int i=0;i<num;i++)
   	 {
 	for(int j=0;j<2;j++)
   	 			{
   	   	 		 cord[i][j]=cord[i][j]*1000;
    			}
    	 	 
   	 }
   	 
	
   	 for(int i=0;i<num;i++)
   	 {
		for(int j=0;j<2;j++)
   	 			{
   	   	 		 Fcoord[i][j]=(int)cord[i][j]; 
    			}
     	 
   	 }
   	 for(int i=0;i<num;i++)
   	 {
		for(int j=0;j<2;j++)
   	 			{
   	   	 		 cout<<cord[i][j]/1000<<" "; 
    			}
        	cout<<"\n";  	 
   	 }
   	 
   	 
   double inv;
   double f[100][100];
   int cnum[100];
   int k=0;
 
     for(int i=0;i<num;i++)
   {
   	  inputfile>>in;
   	  cnum[k]=in;
   	  inv=in; 
   	  k++;
   	  for(int j=0;j<2*inv;j++)
   	  {
   	  	 inputfile>>in;
   	  	
   	  	
   	  	 
   	  	 f[i][j]=in;
   	  	 
   	  	
	
   	  	 inputfile>>in;	
   	  	
	  }
   	 
   } 
   cout<<"\n";
   cout<<"Connected Nodes and distances :";
   cout<<"\n";   
   
	for(int i=0;i<num;i++)
   {
		for(int j=0;j<11;j++)
		{
 		  	cout<<f[i][j]<<"   "; 	  	 
		}
		cout<<"\n";   	 
	}  
	cout<<"\n";   
    int sourcenode;
    inputfile>>sourcenode;
    cout<<"SOURCE : "<<sourcenode; 
   
   
    cout<<"\n";
	for(int i=0;i<num;i++)
    {
    	for(int j=0;j<num;j++)
    	{
    		adj[i][j]=0;
		}	
    	
	}
int l=0;
k=0;

int newcount=1;
for(int i=0;i<num;i++)
{
	newcount=0;
	for(int j=0;j<=num;j=j+2)
	{
		if(newcount!=cnum[k])
		{

		add_edge(i,f[i][j], f[i][j+1]);
		newcount++;
		}
	
	}
	k++;
}

for(int i=0;i<num;i++)
    {	
    	
    	for(int j=0;j<num;j++)
    	{	
    	    if(adj[i][j]>10)
    	    {
    	    	for(int k=0;adj[i][j]>10;k++)
    	    	{
    	    		adj[i][j]=adj[i][j]/10;
				}
			}
    		
		}	
    	
	}

  
	cout<<endl;
	cout<<endl;
 	
 	
 	int result;
 	result = (num * (num - 1)) / 2;

	
		int INTadj[100][100];
		for(int i=0;i<num;i++)
   	{
   		for(int j=0;j<num;j++)
   		{  		
		   	INTadj[i][j]=(int)adj[i][j];
  			
		}
	}
	int bfadj[100][3];
	int m=0;
		for(int i=0;i<num;i++)
   	{	
   		for(int j=0;j<num;j++)
   		{  		
		   	bfadj[m][0]=i;
		   	bfadj[m][1]=j;
		   	bfadj[m][2]=INTadj[i][j];
  			m++;
		}
	}
	
	cout<<"\t\t 		Adjacency Matrix  ";
	cout<<"\n\n";
	cout<<"\t";
 
    
    cout<<"\n";
    
    

	for(int i=0;i<num;i++)
    {	
    	
    	for(int j=0;j<num;j++)
    	{	
    		cout<<"\t"<<adj[i][j];
		}	
    	cout<<"\n";
	}
	
  
	int graph[4][4] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
 
 //for floydWarshal uses the above data 
 
 
 
 char selection=' ';
 cout<<endl;
 back2:
 cout<<"\nSelect What you want to run \n \t1.Dijkstra \n \t2.BellmanFord \n \t3.Prims \n \t4.Kruskal \n \t5.FloydWarshall\n\t6. Clustering Coefficient \n\t7. For exit : \n";
 selection	=	_getch();
 int a,b,c;
 
 switch(selection) { 
    case '1': 
        cout<<"Enter The Source :";
        cin>>a;
        dijkstra(adj,a,num); 
        
        break; 
    case '2': 
    	cout<<"Enter The Source :";
        cin>>b;
        BellmanFord(bfadj,num,30,b);  
        break; 
    case '3': 
    	primMST(INTadj,num);
    	break;
    case '4':
		kruskalMST(INTadj,num); 
        break;
    case '5':
    	floydWarshall(graph,4);
        break;
     case '6':
	 {
	 	int degree=0;
 int src;
 cout<<"\nEnter Source :";
 cin>>src;
 for(int i=0;i<num;i++)
 {
 	if(INTadj[src][i]!=0)
 	{
 		degree++;
	 }
 	
 }
int neigb[100];
int nb=0;
 for(int i=0;i<num;i++)
 {
 	if(INTadj[0][i]!=0)
 	{
 		neigb[nb]=i;
 		nb++;
	}
 	
 }
 

 int p1[100],p2[100];
 for(int i=0;i<num;i++)
 {
 	
 		p1[i]=neigb[i];
 		p2[i]=neigb[i+1];
 			
 }
 
 
 
 float neigbedge=0;
 int xn=0,yn=0;
 for(int i=0;i<num;i++)
{
	for(int j=0;j<num;j++)
	{
			if(adj[p1[i]][p2[j]]!=0)
		{
		
			neigbedge++;
			
		}
	}
	
	
}
cout<<"Deg : "<<degree;
cout<<"N : "<<neigbedge;
 
 float ans=(2*degree)/(neigbedge*(neigbedge-1));
 cout<<"Clustering Coefficient : "<<ans;
	 	
	   }  
        
    case '7':
    	{
    		exit(1);
		}
    default: 
    {
    	cout<<"Wrong Choice!";
    	goto back2;
    	break;
	}
}
  
    inputfile.close(); 
}


void add_edge(int u,int v,double w ) {       
   adj[u][v] = w;
   adj[v][u] = w;
}

void dijkstra(double graph[][100], int src, int V) 
{ 
    int dist[V]; 
  
    bool sptSet[V]; 
    int parent[V];  
         for (int i = 0; i < V; i++) 
    { 
        parent[0] = -1; 
        dist[i] = INT_MAX; 
        sptSet[i] = false; 
    } 
  
   
    dist[src] = 0; 
  
    
    for (int count = 0; count < V - 1; count++) { 
        
        int u = minDistance(dist, sptSet,V); 
  
       
        sptSet[u] = true; 
  
         
        for (int v = 0; v < V; v++) 
  
      
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
			{
					parent[v] = u;  
                dist[v] = dist[u] + graph[u][v]; 
			}
	} 
  
   
    printSolution(dist,V); 
} 


int minDistance(int dist[], bool sptSet[],int V) 
{ 
     
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  

int printSolution(int dist[],int V) 
{ 
	int src = 0; 
     printf("Vertex\t   Distance\n"); 
     int gd = DETECT, gm; 
 

    initgraph(&gd, &gm, "");       
  
    circle(Fcoord[0][0],Fcoord[0][1],5);
  
    for (int i = 1; i < V; i++) 
    { 
   
         printf("%d \t\t %d\n", i, dist[i]);
      
         circle(Fcoord[i][0],Fcoord[i][1],5);
         line(Fcoord[0][0], Fcoord[0][1],Fcoord[i+1][0], Fcoord[i+1][1]);
        
    } 
    cout<<distcal;
     getch();   
    closegraph();
}

void BellmanFord(int graph[][3], int V, int E,int src)
{ 
	
	
	
    int dis[V]; 
    for (int i = 0; i < V; i++) 
        dis[i] = INT_MAX; 
  

    dis[src] = 0; 
  
   
    for (int i = 0; i < V - 1; i++) { 
  
        for (int j = 0; j < E; j++) { 
            if (dis[graph[j][0]] + graph[j][2] < 
                               dis[graph[j][1]]) 
                dis[graph[j][1]] =  
                  dis[graph[j][0]] + graph[j][2]; 
        } 
    } 
  
    
    for (int i = 0; i < E; i++) { 
        int x = graph[i][0]; 
        int y = graph[i][1]; 
        int weight = graph[i][2]; 
        if (dis[x] != INT_MAX && 
                   dis[x] + weight < dis[y]) 
            cout << "Graph contains negative"
                    " weight cycle"
                 << endl; 
    } 
   int gd = DETECT, gm; 
  
  	initgraph(&gd, &gm, "");       
  
    circle(Fcoord[0][0],Fcoord[0][1],5);
  
  
    cout << "Vertex Distance from Source" << endl; 
    
    for (int i = 0; i < V; i++) 
        {
		cout << i << "\t\t" << dis[i] << endl; 
         circle(Fcoord[i][0],Fcoord[i][1],5);
         line(Fcoord[0][0], Fcoord[0][1],Fcoord[i+1][0], Fcoord[i+1][1]);
         
     }
         
         
		 
		 getch();   
    closegraph();
} 
  
int minKey(int key[], bool mstSet[],int V)  
{  
    
    int min = INT_MAX, min_index;  
  
    for (int v = 0; v < V; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}  
  

void printMST(int parent[], int graph[][100],int V)  
{  		int gd = DETECT, gm; 
      	 initgraph(&gd, &gm, "");
		    circle(Fcoord[0][0],Fcoord[0][1],5);
		
    cout<<"Edge \tWeight\n";  
    for (int i = 1; i < V; i++)  
       {
		 cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
		 
      
    	 circle(Fcoord[i][0],Fcoord[i][1],5);
         line(Fcoord[parent[i]][0], Fcoord[parent[i]][1],Fcoord[i][0], Fcoord[i][1]);
    	}
    
    	 getch();   
    closegraph();
}  
  

void primMST(int graph[][100],int V)  
{  
   
    int parent[V];  
      
 
    int key[V];  
      

    bool mstSet[V];  
  
  
    for (int i = 0; i < V; i++)  
        key[i] = INT_MAX, mstSet[i] = false;  
  
    
    key[0] = 0;  
    parent[0] = -1;
  

    for (int count = 0; count < V - 1; count++) 
    {  
      
        int u = minKey(key, mstSet,V);  
  
 
        mstSet[u] = true;  
  
        for (int v = 0; v < V; v++)  
  
            
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])  
                parent[v] = u, key[v] = graph[u][v];  
    }  
  
      
    printMST(parent, graph,V);  
}  

int find(int i,int parent[]) 
{ 
    while (parent[i] != i) 
        i = parent[i]; 
    return i; 
} 
  

void union1(int i, int j,int parent[]) 
{ 
    int a = find(i,parent); 
    int b = find(j,parent); 
    parent[a] = b; 
} 


void kruskalMST(int cost[][100],int V)
{ 
    int mincost = 0; 
  int parent[V];

    for (int i = 0; i < V; i++) 
        parent[i] = i; 
  
   
    int edge_count = 0;
    int x[100],y[100];
    int l=0,m=0;
    while (edge_count < V - 1) { 
        int min = INT_MAX, a = -1, b = -1; 
        for (int i = 0; i < V; i++) { 
            for (int j = 0; j < V; j++) { 
                if (find(i,parent) != find(j,parent) && cost[i][j] < min) { 
                    min = cost[i][j];
                    a = i;
                    
                    b = j;
                    
                } 
            } 
        } 
  
        union1(a, b,parent); 
        printf("Edge %d:(%d, %d) cost:%d \n", 
               edge_count++, a, b, min);
			   x[l]=a; 
			   y[m]=b;
			   l++;
			   m++;
        mincost += min;
		
    } 
    
    printf("\n Minimum cost= %d \n", mincost);
    
    	int gd = DETECT, gm; 
      	 initgraph(&gd, &gm, "");
		    circle(Fcoord[0][0],Fcoord[0][1],5);
    
    
    for (int i = 0; i < V-1; i++) { 
            
		 circle(Fcoord[i][0],Fcoord[i][1],5);
         line(Fcoord[x[i]][0], Fcoord[x[i]][1],Fcoord[y[i]][0], Fcoord[y[i]][1]);
		}
		getch();   
    closegraph();
} 


void floydWarshall(int graph[][4],int V)  
{  	
    int dist[4][4], i, j, k;  
	  
    for (i = 0; i < V; i++)  
        {
		for (j = 0; j < V; j++)  
           {
			dist[i][j] = graph[i][j];  
}}
    
    
    for (k = 0; k < V; k++)  
    {  
        
        for (i = 0; i < V; i++)  
        {  
             
            for (j = 0; j < V; j++)  
            {  
               
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j]; 
				
					 
            }  
           
        }  
    }  
 
 cout<<"The following matrix shows the shortest distances"
            " between every pair of vertices \n";  
    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            if (dist[i][j] == INF)  
                cout<<"INF"<<"     ";  
            else
                cout<<dist[i][j]<<"     ";  
        }  
        cout<<endl;  
    }  
    
    
     int gd = DETECT, gm; 

    initgraph(&gd, &gm, "");       
  
    circle(Fcoord[0][0],Fcoord[0][1],5);
    
    
 
  for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
 if(dist[i][j]!=INF && dist[i][j]!=0)
 {
 		circle(Fcoord[i][0],Fcoord[i][1],5);
 		circle(Fcoord[j][0],Fcoord[j][1],5);
         line(Fcoord[i][0], Fcoord[i][1],Fcoord[j][0], Fcoord[j][1]);
 }
 
 	}
    }
    getch();   
    closegraph();
    
}  




