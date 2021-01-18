#include<bits/stdc++.h>
using namespace std;

void printStack(stack<int> s){
    while(!s.empty()){
        printf("%d ",s.top());
        s.pop();
    }
    printf("\n");
    return;
}

void printStack(stack<int> s,int test){
    while(!s.empty() && s.top()!=test){
        printf("%d<-",s.top());
        s.pop();
    }
    if(!s.empty())
        printf("%d<-",s.top());
    return;
}

void printVector(vector<int> v){
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        printf("%d ",*it);
    }
    printf("\n");
    return;
}

class Graph{
    int V;
    vector<int> *array;
    bool *visited;
    queue<int> q;
    stack<int> s;

    public:
    Graph(int n){
        V=n;
        array=new vector<int>[V];
        visited=new bool[V];
    }

    void addEdge(int u,int v){
        //array[v].push_back(u);
        array[u].push_back(v);
        return;
    }

    void print(){
        for(int i=0;i<V;i++){
            printf("%d: ",i);
            printVector(array[i]);
        }
    }
    
    void BFS(){
        for(int i=0;i<V;i++)
            visited[i]=false;
        printf("BFS: ");

        for(int i=0;i<V;i++){
            if(!visited[i])
                BFSUtil(i);
        }
        printf("\n");
    }    

    void BFSUtil(int v){
        q.push(v);
        visited[v]=true;

        while(!q.empty()){
            int tmp=q.front();
            q.pop();
            printf("%d ",tmp);
            vector<int>::iterator it;

            for(it=array[tmp].begin();it!=array[tmp].end();it++)
                if(!visited[*it]){
                    q.push(*it);
                    visited[*it]=true;
                }
        }
    }

    void DFS(){
        for(int i=0;i<V;i++)
            visited[i]=false;
        printf("DFS: ");

        for(int i=0;i<V;i++){
            if(!visited[i])
                DFSUtil(i);
        }
        printf("\n");
    }    

    void DFSUtil(int v){
        printf("%d ",v);
        visited[v]=true;

        vector<int>::iterator it;
        for(it=array[v].begin();it!=array[v].end();it++)
            if(!visited[*it]){
                DFSUtil(*it);
            }
    }

    int findPath(int v,int u){
        for(int i=0;i<V;i++)
            visited[i]=false;

        int res=path(v,u);

        while(!s.empty())
            s.pop();
        return res;
    }

    int path(int v,int u){
        visited[v]=true;
        s.push(v);

        if(u==v){
            printStack(s);
            return 1;
        }

        vector<int>::iterator it;
        for(it=array[v].begin();it!=array[v].end();it++){
            if(!visited[*it]){
                int res=path(*it,u);
                if(res)
                    return res;
            }
        }
        s.pop();
        return 0;
    }

    int findCycle(int v){
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        int res=cycle(v);
        return res;
    }

    int cycle(int v){
        visited[v]=true;
        s.push(v);
        for(int j=0;array[v].begin()+j!=array[v].end();j++){
            if(visited[array[v][j]]){
                printStack(s,array[v][j]);cout<<v<<endl;
                return 1;
            }
            else{
                int res=cycle(array[v][j]);
                if(res==1)
                    return 1;
            }
        }
        s.pop();
        return 0;
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(2,1);
    g.addEdge(2,4);
    g.addEdge(0,4);
    g.addEdge(3,2);
    g.addEdge(4,3);
    g.print();
    g.BFS();                
    g.DFS();
    if(g.findPath(1,4)==0)
        cout<<"No path found"<<endl;
    if(g.findCycle(3)==0)
        cout<<"No loop in this graph."<<endl;
    return 0;
}
