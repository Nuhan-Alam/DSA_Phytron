#include <bits/stdc++.h>
using namespace std;
//Input with reference and array to increase porficiency
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
    int ans[v];
    fill(&ans[0],&ans[0]+v,INT_MAX);
    ans[0]=0;
    Edge* edge_list[e];
    for(int i=0;i<e;i++)
    {
        int from,to,weight;
        cin >> from >> to >> weight;
        Edge* a = new Edge(from,to,weight);
        edge_list[i]=a;
        
    }
    // for(auto ed: edge_list)
    // {
    //     cout << ed->from << " " <<  ed->to  << " " << ed->weight << endl;
    // }
    bool negative_cycle = false;
    for(int i=e;i>0;i--)
    {
        //cout << "In outer Looop" << endl;
        for(auto eg:edge_list)
        {
            //cout << "In inner Looop" << endl;
            if(ans[eg->from]!=INT_MAX && ans[eg->from]+eg->weight < ans[eg->to])
            {
                ans[eg->to]=ans[eg->from]+eg->weight;
                //cout << ans[eg->to]<< endl;
            }
        }
    }

    for(auto eg:edge_list)
        {
            if(ans[eg->from]!=INT_MAX && ans[eg->from]+eg->weight<ans[eg->to])
            {
                //cout << eg->from << " " << ans[eg->from] << " To " << eg->to << " " << ans[eg->to] << endl;
                negative_cycle = true;
                break;
            }
        }

        // for(int i=0;i<v;i++)
        // {
        //     cout << i << " -> " << ans[i]<< endl;
        // }

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
