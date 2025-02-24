#include <bits/stdc++.h>
using namespace std;
//Input with reference and array to increase porficiency
//Input is taken as Edge_list
//Complexity O(EV)
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

    //default Answer
    int ans[v];
    fill(&ans[0],&ans[0]+v,INT_MAX);
    ans[0]=0;

    //Edge Input
    Edge* edge_list[e];
    for(int i=0;i<e;i++)
    {
        int from,to,weight;
        cin >> from >> to >> weight;
        Edge* a = new Edge(from,to,weight);
        edge_list[i]=a;        
    }
    
    //Bellman_Ford    
    for(int i=e;i>0;i--)
    {
        for(auto eg:edge_list)
        {
            if(ans[eg->from]!=INT_MAX && ans[eg->from]+eg->weight < ans[eg->to])
            ans[eg->to]=ans[eg->from]+eg->weight;            
        }
    }

    
    //Cycle Ditection
    bool negative_cycle = false;
    for(auto eg:edge_list)
        {
            if(ans[eg->from]!=INT_MAX && ans[eg->from]+eg->weight < ans[eg->to])
            {
                negative_cycle = true;
                break;
            }
        }

        
    //Output
    if(negative_cycle) cout << "Negative Cycle Ditectied" << endl;
    else
    {
        for(int i=0;i<v;i++)
        {
            if(ans[i]==INT_MAX) cout << i << " -> " << "not reachable" << endl;
            else cout << i << " -> " << ans[i]<< endl;
        }
    }
return 0;

}
