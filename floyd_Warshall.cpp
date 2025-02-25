#include <bits/stdc++.h>
using namespace std;


int main()

{
    //Initials
    int v,e;
    cin >> v >> e;
    int matrix_ans[v+5][v+5];
    fill(&matrix_ans[0][0],&matrix_ans[0][0]+(v+5)*(v+5),INT_MAX);
    for(int i=0;i<v;i++)
    matrix_ans[i][i]=0;

    //Input edges
    while(e--)
    {
        int from,to,weight;
        cin >> from >> to >> weight;
        matrix_ans[from][to] = weight;
    }

    for(int mid=0;mid<v;mid++)
    {
        for(int from=0;from<v;from++)
        {
            for(int to=0;to<v;to++)
            {
    if( matrix_ans[from][mid]!=INT_MAX && matrix_ans[mid][to]!= INT_MAX &&
        matrix_ans[from][to]>matrix_ans[from][mid]+matrix_ans[mid][to]){
        matrix_ans[from][to] = matrix_ans[from][mid]+matrix_ans[mid][to];
    }
                
            }
        }
    }

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(matrix_ans[i][j]==INT_MAX) cout << "X" << " ";
            else cout << matrix_ans[i][j] << " ";
        }
        cout << endl;
    }

 return 0;

}
