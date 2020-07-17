#include<iostream>
#include<map>
using namespace std;
struct node{
    int val;
    node *le,*ri;
};
map<int ,int> m;
node* root=NULL;
int maxdep=-1;
node* ins(node* tem,int value,int depth){
    if(tem==NULL){
        m[depth]++;
        tem=new(node);
        tem->val=value;
        tem->le=tem->ri=NULL;
        maxdep=maxdep<depth?depth:maxdep;
    }else if(value<=tem->val){
        tem->le=ins(tem->le,value,depth+1);
    }else{
        tem->ri=ins(tem->ri,value,depth+1);
    }
    return tem;
}
int main(){
    int n,buf;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>buf;
        root=ins(root,buf,1);
    }
    cout<<m[maxdep]<<" + "<<m[maxdep-1]<<" = "<<m[maxdep-1]+m[maxdep];
}
