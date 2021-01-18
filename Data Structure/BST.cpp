#include <bits/stdc++.h>
using namespace std;

#define pn printf("\n");
#define ps printf(" ");
#define debug(x) cout<<x<<" ";

typedef int myt;

template <class t> t max2(t x,t y){return x>y?x:y;}
template <class t> t max3(t x,t y,t z){return max2<t>(x,max2<t>(y,z));}
template <class t> t min2(t x,t y){return x<y?x:y;}
template <class t> t min3(t x,t y,t z){return min2<t>(x,min2<t>(y,z));}

template <class t>
struct node{									//Structure of node
	t data;
	struct node *left,*right,*nextRight,*parent;
};

template <class t>
class BST{
public:
	struct node<t>* createNode(t d){			//Create new Node in Binary Tree
		struct node<t> *root=new struct node<t>();
		root->data=d;
		root->left=NULL;
		root->right=NULL;
		root->nextRight=NULL;
		root->parent=NULL;
		return root;
	}

	void inOrderR(struct node<t> *root){		//Inorder Traversal using recursion
		if(root==NULL)
			return;
		inOrderR(root->left);
		cout<<root->data;ps;
		inOrderR(root->right);
	}

	void inOrderI(struct node<t> *root){		//Inorder Traversal using iteration with stack
		stack<struct node<t> *> stk;
		while(1){
			if(root==NULL){
				if(!stk.empty()){
					cout<<stk.top()->data;ps;
					root=stk.top()->right;
					stk.pop();
				}
				else
					break;
			}
			else{
				stk.push(root);
				root=root->left;
			}
		}
	}

	void postOrder(struct node<t> *root){		//Postorder traversal using recursion
		if(root==NULL)
			return;
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data;ps;
	}

	void preOrder(struct node<t> *root){		//Preorder traversal using recursion
		if(root==NULL)
			return;
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}

	void levelOrderI(struct node<t> *root){		//BFS for Binary Tree using iteration
		long long level=height(root);
		for(int i=0;i<level;i++)
			levelOrderUtil(root,i);
	}

	void levelOrderUtil(struct node<t> *root,long long level){
		if(level==0){
			cout<<root->data;ps;
		}
		else{
			if(root->left!=NULL)
				levelOrderUtil(root->left,level-1);
			if(root->right!=NULL)
				levelOrderUtil(root->right,level-1);
		}
	}

	void levelOrderQ(struct node<t> *root){		//BFS for Binary Tree using queue
		queue<struct node<t> *> q;
		q.push(root);
		while(!q.empty()){
			root=q.front();
			cout<<root->data;ps;
			q.pop();
			if(root->left!=NULL)
				q.push(root->left);
			if(root->right!=NULL)
				q.push(root->right);
		} 
	}

	void leftView(struct node<t> *root){		// Prints image of Binary Tree as we look from left side
		long long level=0;
		leftViewUtil(root,1,&level);
	}

	void leftViewUtil(struct node<t> *root,long long l,long long *level){
		if(l>*level){
			cout<<root->data;ps;
			*level+=1;
		}
		if(root->left!=NULL)
			leftViewUtil(root->left,l+1,level);
		if(root->right!=NULL)
			leftViewUtil(root->right,l+1,level);
	}

	void maxWidthI(struct node<t> *root){		//Find Maximum Width using iteration
		long long ans=numeric_limits<t>::min();
		long long level=height(root);
		for(int i=0;i<level;i++){
			long long width=0;
			maxWidthUtilI(root,i,&width);
			if(width>ans)
				ans=width;
		}
		cout<<ans;
	}

	void maxWidthUtilI(struct node<t> *root,long long level,long long *width){
		if(level==0){
			*width+=1;
		}
		else{
			if(root->left!=NULL)
				maxWidthUtilI(root->left,level-1,width);
			if(root->right!=NULL)
				maxWidthUtilI(root->right,level-1,width);
		}
	}

	void maxWidthQ(struct node<t> *root){		//Find Maximum Width using queue
		long long ans=numeric_limits<t>::min();
		queue<struct node<t> *> q;
		q.push(root);
		while(!q.empty()){
			long long size=q.size();
			if(ans<size)
				ans=size;
			while(size!=0){
				if(q.front()->left!=NULL)
					q.push(q.front()->left);
				if(q.front()->right!=NULL)
					q.push(q.front()->right);
				q.pop();
				size--;
			}
		}
		cout<<ans;
	}

	void maxWidthP(struct node<t> *root){		//Find Maximum Width using preorder
		long long h=height(root);
		long long ans=numeric_limits<t>::min(),width[h]={0};
		maxWidthUtilIP(root,0,width);
		for(int i=0;i<h;i++)
			if(ans<width[i])
				ans=width[i];
		cout<<ans;
	}

	void maxWidthUtilIP(struct node<t> *root,long long level,long long *width){
		if(root==NULL)
			return;
		width[level]++;
		maxWidthUtilIP(root->left,level+1,width);
		maxWidthUtilIP(root->right,level+1,width); 
	}

	void kDistance(struct node<t> *root,long long k){	//Find nodes at k distance from root
		if(k==1){
			cout<<root->data;ps;
		}
		else{
			if(root->left!=NULL)
				kDistance(root->left,k-1);
			if(root->right!=NULL)
				kDistance(root->right,k-1);
		}
	}

	void connectRight(struct node<t> *root){		//BFS for Binary Tree using iteration
		long long level=height(root);
		struct node<t> *con=NULL;
		for(int i=0;i<level;i++){
			connectRightUtil(root,i,&con);pn;
			con=NULL;
		}
	}

	void connectRightUtil(struct node<t> *root,long long level,struct node<t> **con){
		if(level==0){
			root->nextRight=(*con);cout<<"   ";
			if((*con)!=NULL)
				cout<<root->data<<"->"<<(*con)->data;
			else
				cout<<root->data<<"->NULL";
			*con=root;
		}
		else{
			if(root->right!=NULL)
				connectRightUtil(root->right,level-1,con);
			if(root->left!=NULL)
				connectRightUtil(root->left,level-1,con);
		}
	}

	long long size(struct node<t> *root){		//Calculate size of Binary Tree using recursion
		if(root==NULL)
			return 0;
		return size(root->left)+size(root->right)+1;
	}

	t max(struct node<t> *root){				//Find maximum element in Binary Tree
		if(root==NULL)
			return numeric_limits<t>::min();
		return max3<t>(root->data,max(root->left),max(root->right));
	}

	t min(struct node<t> *root){				//Find minimum elemenr un Binay Tree
		if(root==NULL)
			return numeric_limits<t>::max();
		return min3<t>(root->data,min(root->left),min(root->right));
	}

	long long height(struct node<t> *root){
		if(root==NULL)
			return 0;
		return max2<long long>(height(root->left),height(root->right))+1;
	}
};
int main(){
	BST<myt> bt;
	struct node<myt> *a =bt.createNode(1);
	struct node<myt> *b =bt.createNode(2);
	struct node<myt> *c =bt.createNode(3);
	struct node<myt> *d =bt.createNode(4);
	struct node<myt> *e =bt.createNode(5);
	struct node<myt> *f =bt.createNode(6);
	
//			1
//		  /	  \
//		2		5
//	  /	  \		  \
//	3		4		6

	a->left=b;
	b->left=c;
	b->right=d;
	a->right=e;
	e->right=f;

	cout<<"InOrder(Recursive): ";bt.inOrderR(a);pn;
	cout<<"InOrder(Iterative): ";bt.inOrderI(a);pn;
	cout<<"PreOrder: ";bt.preOrder(a);pn;
	cout<<"PostOrder: ";bt.postOrder(a);pn;
	cout<<"LevelOrder(Iterative): ";bt.levelOrderI(a);pn;
	cout<<"LevelOrder(Queue): ";bt.levelOrderQ(a);pn;
	cout<<"LeftView: ";bt.leftView(a);pn;
	cout<<"Maximun Width(Iterative): ";bt.maxWidthI(a);pn;
	cout<<"Maximun Width(Queue): ";bt.maxWidthQ(a);pn;
	cout<<"Maximun Width(Preorder): ";bt.maxWidthP(a);pn;
	cout<<"kDistance: ";bt.kDistance(a,3);pn;
	cout<<"ConnectRight:- ";pn;bt.connectRight(a);
	cout<<"Size: ";cout<<bt.size(a);pn;
	cout<<"Maximun: ";cout<<bt.max(a);pn;
	cout<<"Minimum: ";cout<<bt.min(a);pn;
	return 0;
}