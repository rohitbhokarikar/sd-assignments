#include <iostream>
using namespace std;
class tnode
{
    int data;
    int l,r;
    tnode *lt,*rt;
public:
    tnode *create(int item)
    {
        tnode *nn=new tnode;
        nn->data=item;
        nn->lt=nn->rt=NULL;
        nn->l=nn->r=1;
        return nn;
    }
    tnode *insert_r(tnode *r,int item)
    {
        tnode *rp=r;
        tnode *p=NULL;
        while(rp!=NULL)
        {
            p=rp;
            if(item<rp->data)
            {
                if(rp->l==0)
                    rp=rp->lt;
                else
                    break;
            }
            else if(item>rp->data)
            {
                if(rp->r==0)
                    rp=rp->rt;
                else
                    break;
            }
        }
        tnode *nn;
        nn=nn->create(item);
        if(p==NULL)
        {
            r=nn;
        }
        else if(item<p->data)
        {
            nn->lt=p->lt;
            nn->rt=p;
            p->lt=nn;
            p->l=0;
        }
        else if(item>p->data)
        {
            nn->rt=p->rt;
            nn->lt=p;
            p->rt=nn;
            p->r=0;
        }
        return r;
    }
    void inorder(tnode *r)
    {
        tnode *temp=r;
        while(temp->l==0)
        {
            temp=temp->lt;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            if(temp->r==1)
                temp=temp->rt;
            else
            {
                temp=temp->rt;
                while(temp->l==0)
                {
                    temp=temp->lt;
                }
            }
        }
    }
    void reverse_inorder(tnode *r)
    {
        tnode *temp=r;
        while(temp->r==0)
        {
            temp=temp->rt;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            if(temp->l==1)
                temp=temp->lt;
            else
            {
                temp=temp->lt;
                while(temp->r==0)
                {
                    temp=temp->rt;
                }
            }
        }
    }
};
tnode *root=NULL;
int main()
{
    char r;
    do
    {
        int flag=0;
        root=NULL;
        char op;
        do
        {
            if(flag==0)
            {
                int n;
                cout<<"Enter the number of elements you wish to enter: ";
                cin>>n;
                int a[n];
                cout<<"Start entering the elements\n";
                for(int i =0;i<n;i++)
                {
                    cin>>a[i];
                    root=root->insert_r(root,a[i]);
                }
                flag=1;
            }
            int c;
            cout<<"-----------------------------Menu-------------------\n";
            cout<<"1] Insert\n2] Display ascending\n3] Display descending";
            cout<<"\n===================================================\n";
            cout<<"Enter your choice: ";
            cin>>c;
            switch(c)
            {
                case 1: {
                            int item;
                            cout<<"Enter data you wish to enter: ";
                            cin>>item;
                            root=root->insert_r(root, item);
                        }
                        break;
                case 2: {
                            root->inorder(root);
                        }
                        break;
                case 3: {
                            root->reverse_inorder(root);
                        }
                        break;
                default:cout<<"Invalid\n";
        }
        cout<<"Do you wish to continue?(y/n): ";
        cin>>op;
        }while(op=='y' || op=='Y');
        cout<<"Test pass?(y/n): ";
        cin>>r;
    }while(r=='n' || r=='N');
    cout<<"******************\n";
    cout<<"*   Thank You!   *\n";
    cout<<"******************\n";
    return 0;
}
