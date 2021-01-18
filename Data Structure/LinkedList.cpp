#include <bits/stdc++.h>
using namespace std;

#define pn printf("\n");
#define ps printf(" ");
typedef struct Node node;

struct Node{
	int data;
	node *next;
};

node *createNode(int d){
	node *t=(node *)malloc(sizeof(node));
	t->data=d;
	t->next=NULL;
	return t;
}

class LinkedList{
public:
	node *head;

	LinkedList(){
		head=NULL;
	}

	void addFront(int d){
		node *t=createNode(d);
		t->next=head;
		head=t;
	}

	void addLast(int d){
		node *t=head;
		if(head==NULL){
			addFront(d);
		}
		else{
			while(t->next!=NULL)
				t=t->next;
			node *t1=createNode(d);
			t->next=t1;
		}
	}

	void addAfter(int d,node *n){
		node *t=createNode(d),*t1=n->next;
		n->next=t;
		t->next=t1;
	}

	void del(int pos){
		if(pos==0){
			head=head->next;
		}
		else{
			node* t=head;
			int count=0;
			while(count!=pos-1 && t!=NULL){
				t=t->next;
				count++;
			}
			if(t!=NULL && t->next!=NULL)
				t->next=t->next->next;
			else
				printf("Error: Inappropriate position for deletion.\n");
		}
	}

	void delKey(int k){
		node *t=head,*pre=NULL;
		while(t!=NULL && t->data!=k){
			pre=t;
			t=t->next;
		}
		if(t==NULL){
			printf("Error: Key not found for deletion.\n");
		}
		else if(pre==NULL){
			head=t->next;
		}
		else{
			pre->next=t->next;
		}
	}

	int lengthI(){
		int c=0;
		node *t=head;
		while(t!=NULL){
			c++;
			t=t->next;
		}
		return c;
	}

	int lengthR(){
		return lengthR(	head);
	}

	int lengthR(node *t){
		if(t==NULL)
			return 0;
		else
			return lengthR(t->next)+1;
	}

	node *searchI(int k){
		node *t=head;
		while(t!=NULL && t->data!=k)
			t=t->next;
		return t;
	}

	node *searchR(int k){
		return searchR(k,head);
	}

	node *searchR(int k,node *t){
		if(t==NULL || t->data==k)
			return t;
		else
			return searchR(k,t->next);
	}

	void swap(int x,int y){
		node *px=NULL,*py=NULL,*tx=head,*ty=head;
		while(tx!=NULL && tx->data!=x){
			px=tx;
			tx=tx->next;
		}
		while(ty!=NULL && ty->data!=y){
			py=ty;
			ty=ty->next;
		}
		if(tx==ty){printf("Error: same node.\n");return;}
		else if(tx==NULL || ty==NULL){printf("Error: one or both node(s) not present in LinkedList.\n");}
		else if(tx==head){
			py->next=tx;
			node *tp=tx->next;
			tx->next=ty->next;
			ty->next=tp;
			head=ty;
		}
		else if(ty==head){
			px->next=ty;
			node *tp=tx->next;
			tx->next=ty->next;
			ty->next=tp;
			head=tx;
		}
		else{    
			px->next=ty;
			py->next=tx;
			node *tp=tx->next;
			tx->next=ty->next;
			ty->next=tp;
		}
 	}

 	node *nNode(int n){
 		int c=0;
 		node *t=head;
 		while(t!=NULL && c!=n){
 			t=t->next;
 			c++;
 		}
 		return t;
 	}

 	node *middle(){
 		node *t=head,*t1=head;
 		while(t!=NULL && t->next!=NULL){
 			t=t->next->next;
 			t1=t1->next;
 		}
 		return t1;
 	}

 	node *nLast(int n){
 		int l=lengthI();
		int c=0;
		node *t=head;
		while(t!=NULL && c!=l-n){
			c++;
			t=t->next;
		}
		return t;
 	}

 	node *nLast1(int n){
 		int c=0;
 		node *t=head,*t1=head;
 		while(t1!=NULL && c!=n){
 			t1=t1->next;
 			c++;
 		}
 		if(c!=n)
 			return t1;
 		while(t1!=NULL){
 			t1=t1->next;
 			t=t->next;
 		}
 		return t;
 	}

 	int countFreq(int key){
 		int c=0;
 		node *t=head;
 		while(t!=NULL){
 			if(t->data==key)
 				c++;
 			t=t->next;
 		}
 		return c;
 	}

 	void reverse(){
 		node *t=head,*t1=NULL;
 		while(t!=NULL){
			node *tmp=t->next;
			t->next=t1;
			t1=t;
			t=tmp;
 		}
 		head=t1;
 	}

 	bool isLoop(){
 		node *t=head,*t1=head;
 		while(t!=NULL && t1!=NULL && t1->next!=NULL){
 			t=t->next;
 			t1=t1->next->next;
 			if(t==t1)
 				return true;
 		}
 		return 0;
 	}

 	void deleteList(){
 		head=NULL;
 	}

	void print(){
		node *tmp=head;
		if(head==NULL){
			printf("null\n");
			return;
		}
     	while(tmp!=NULL){
		  	printf("%d",tmp->data);ps;
			 tmp=tmp->next;
		}pn;
	}  
 };

int main(){
	LinkedList l;
	for(int i=0;i<6;i++){
		if(i!=2)
			l.addLast(i);
	}cout<<"Insertion at end: ";l.print();
	cout<<"Insertion at after given node: ";l.addAfter(2,l.head->next);l.print();
	cout<<"Deletion of node given position: ";l.del(0);l.print();
	cout<<"Deletion of node using key: ";l.delKey(3);l.print();
	cout<<"Length of LinkedList: ";cout<<l.lengthI();ps;cout<<l.lengthR();pn;
	cout<<"Search(Iterative): ";cout<<l.searchI(2)->data;pn;
	cout<<"Search(Recursive): ";cout<<l.searchR(10);pn;
	cout<<"Swap nodes: ";l.swap(1,4);l.print();
	cout<<"nth node: "<<l.nNode(3)->data;pn;l.print();
	cout<<"middle node: "<<l.middle()->data;pn;
	cout<<"nth last node: "<<l.nLast(2)->data;pn;
	cout<<"nth last node: "<<l.nLast1(3)->data;pn;
	l.addLast(1);l.print();
	cout<<"Count frequency: "<<l.countFreq(1);pn;
	cout<<"Reverse: ";l.reverse();l.print();
	cout<<"Loop detection: "<<l.isLoop();pn;
	cout<<"Delete LinkedList: ";l.deleteList();l.print();
	return 0;
}