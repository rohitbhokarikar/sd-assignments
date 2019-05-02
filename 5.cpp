#include <iostream>
using namespace std;
class graph
{
    int a[100][100];
    int v;
public:
    void insert_edge(int n1,int n2)
    {
        if(n1-1>=v||n2-1>=v)
            cout<<"\nVertex request out of range\n";
        else
            a[n1-1][n2-1]=1;
    }
    void display()
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                cout<<a[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    void update_v(int n)
    {
        v=n;
    }
};
int main()
{
    char r;
    do
    {
        graph g;
        char op;
        int v;
        cout<<"\nEnter number of vertices - ";
        cin>>v;
        g.update_v(v);
        do
        {
            int c;
            cout<<"\n=======================Menu======================\n";
            cout<<"\n1.Insert edge\n2.Increase number of vertices\n3.Display matrix\n";
            cout<<"\n=================================================\n";
            cout<<"\nEnter your choice - ";
            cin>>c;
            switch(c)
            {
                case 1: {
                            int n1,n2;
                            cout<<"\nEnter the nodes between which there is an edge - \n";
                            cin>>n1>>n2;
                            g.insert_edge(n1,n2);
                        }
                        break;
                case 2: {
                            int n;
                            cout<<"\nEnter the number by which you wish to increase the vertices - ";
                            cin>>n;
                            v+=n;
                            g.update_v(v);
                        }
                        break;
                case 3: {
                            g.display();
                        }
                        break;
                default:cout<<"Invalid\n";
            }
            cout<<"\nDo you want to continue -  ";
            cin>>op;
        }while(op=='y' || op=='Y');
        }while(r=='n' || r=='N');
    return 0;
}
