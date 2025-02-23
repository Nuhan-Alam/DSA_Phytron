#include <bits/stdc++.h>
using namespace std;
//Took input as reference
class Edge
{
    public:
    int from;
    int to;
    int weight;

    Edge(int from, int to, int weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
    
};


int main()
{
    
    int v,e;
    cin >> v >> e;
    
    Edge* edge_list[v];
    for(int i=0;i<v;i++)
    {
        int from,to,weight;
        cin >> from >> to >> weight;
        Edge* a = new Edge(from,to,weight);
        edge_list[i]=a;
        
    }
    for(auto ed: edge_list)
    {
        cout << ed->from << " " <<  ed->to  << " " << ed->weight << endl;
    }
return 0;

}
