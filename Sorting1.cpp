#include<iostream>
using namespace std;
void heapify(int A[],int n,int i)
{
    //In this we arrange the single subtree according heap requirement
    //i.e. parent>=child
    int large_in_subtree=i;
    int lchild=2*i+1,rchild=2*i+2;
    if(lchild<n && A[large_in_subtree]<A[lchild])
    {
        large_in_subtree=lchild;
    }
    if(rchild<n && A[large_in_subtree]<A[rchild])
    {
        large_in_subtree=rchild;
    }
    if(large_in_subtree!=i)
    {
        swap(A[large_in_subtree],A[i]);
        heapify(A,n,large_in_subtree);
        //If root is changed, then we need to go deep to manage subtree that are connected
        //to child node with whom we swapped root.
        //Else no change
    }
}
void sort(int A[],int n)
{
    //Initialize i to the root of the last element that would be in heap. 
    //i=n/2-1 gives i th value of root of the last element.
    for(int i=n/2-1;i>=0;i--) 
    {
        heapify(A,n,i);
        //We are doing this like BFS opeation.
        //We are going to level which has the root that contains last element as a child
        //So basically last second level
        //Then we are arranging each subtree at that level, and level by level going up the tree
        //and hence we are converting array into a max heap
    }
    cout<<"\nValue of heap:- ";
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    for(int i=n-1;i>0;i--)
    {
        swap(A[0],A[i]);
        heapify(A,i,0);
    }
}
int main()
{
    int n,x;
    cout<<"\nEnter number of elements:- ";
    cin>>n;
    int A[n];
    cout<<"Enter elements:- ";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    sort(A,n);
    cout<<"\nOutput of Sort:- ";
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}
