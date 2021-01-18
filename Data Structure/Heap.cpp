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

class Heap{
	int *a,capacity,heapSize;

	int parent(int i){
		return (i-1)/2;
	}

	int leftChild(int i){
		return 2*i+1;
	}

	int rightChild(int i){
		return 2*i+2;
	}
public:
	Heap(int cap){
		a=new int[cap]();
		capacity=cap;
		heapSize=cap;
		for(int i=0;i<cap;i++)
				a[i]=i;
	}

	void printHeap(){
		cout<<"heap-> ";
		for(int i=0;i<heapSize;i++){
			cout<<a[i];ps;
		}
	}

	void printArray(){
		cout<<"array-> ";
		for(int i=0;i<capacity;i++){
			cout<<a[i];ps;
		}
	}

	void maxHeapify(int i){
		int l=leftChild(i),r=rightChild(i),largest=i;
		if(l<heapSize && a[l]>a[largest])
			largest=l;
		if(r<heapSize && a[r]>a[largest])
			largest=r;
		if(largest!=i){
			a[largest]=a[i]^a[largest];
			a[i]=a[i]^a[largest];
			a[largest]=a[i]^a[largest];
			maxHeapify(largest);
		}
	}

	void maxBuildHeap(){
		for(int i=(capacity/2);i>=0;i--)
			maxHeapify(i);
	}

	int maximum(){
		return a[0];	
	}
	
	int extractMax(){
		int max=a[0];
		heapSize--;
		a[0]=a[heapSize];
		maxHeapify(0);
		return max;
	}

	void increaseKey(int i,int k){
		if(k<a[i])
			cout<<"Error: Provided key is less than current key.\n";
		else{
			a[i]=k;
			int p=parent(i);
			while(a[p]<a[i]){
				a[p]=a[p]^a[i];
				a[i]=a[p]^a[i];
				a[p]=a[p]^a[i];
				i=p;
				p=parent(p);
			}
		}
	}

	void maxInsertKey(int k){
		a[heapSize]=numeric_limits<int>::min();
		increaseKey(heapSize,k);
		heapSize++;
	}

	void HeapSort(){
		int tmp=heapSize;
		for(int i=heapSize-1;i>0;i--){
			a[0]=a[0]^a[i];
			a[i]=a[0]^a[i];
			a[0]=a[0]^a[i];
			heapSize--;
			maxHeapify(0);
		}
		heapSize=tmp;
	}

};

int main(){
	Heap h(7);
	cout<<"buildHeap: ";h.maxBuildHeap();h.printHeap();pn;
	cout<<"Maximum: "<<h.maximum();pn;
	cout<<"Increase Key: ";h.increaseKey(3,9);h.printHeap();pn;
	cout<<"ExtractMax: "<<h.extractMax();pn;
	cout<<"After extractMax: ";h.printHeap();pn;
	cout<<"Heapsort: ";h.HeapSort();h.printHeap();pn;
	cout<<"Insert: ";h.maxInsertKey(7);h.printHeap();pn;
	return 0;
}