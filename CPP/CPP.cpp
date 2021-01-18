#include <bits/stdc++.h>
using namespace std;

int ga=100;

void staticvar(){
	static int a=0;
	cout<<a<<" ";
	a++;
}

int * max1(int *a,int *b){
	if(*a>*b)
		return a;
	else
		return b;
} 

int & max2(int &a,int &b){
	if(a>b)
		return a;
	else
		return b;
}

class Square;

class Circle{
//private:
	int rad;
	static int count;
protected:

public:
	int var;
	Circle(){
		var=0;
		count++;
	}

	Circle(int r){
		var=0;
		rad=r;
		count++;
	}

	/* Copy Constructor 
	 * Used to create copy object
	 */
	Circle(Circle &c){	 
		rad=c.getRad();
	}

	~Circle(){
		//cout<<"Destroying Circle object."<<endl;
	}

	int getRad(){
		return rad;
	}

	void setRad(int r){
		rad=r;
	}

	static int getCount(){
		return count;
	}

	int calArea();

	friend void exchange(Circle &,Square &);

	void cannotAlter() const; 

	Circle operator+(Circle);

	operator float();
};

int Circle::count;

int Circle::calArea(){
	return 3.14*rad*rad;
}

void Circle::cannotAlter() const
{	cout<<"This function can not alter variable."<<endl;	// rad=tmp: Illegal Operation 
}

Circle Circle::operator+(Circle c){
	Circle ctmp;
	ctmp.rad=rad+c.rad;
	return ctmp;
}

Circle:: operator float(){
	return rad*1.0;
}

class Square{
	int len;
protected:

public:
	Square(){

	}

	Square(int l){
		len=l;
	}

	int getLen(){
		return len;
	}

	void setLen(int l){
		len=l;
	}

	friend void exchange(Circle &,Square &);
};

void exchange(Circle &c,Square &s){
	int tmp=c.rad;
	c.rad=s.len;
	s.len=tmp;
}

int main(){
	/* Enum is user defined datatype.
	 * Basically it is integer sequence mapped to user defined strings
	 */
	cout<<"Enum:"<<endl;
	enum color {red,green,blue};
	color bgcolor=red;
	cout<<bgcolor<<endl;
	
	/* Static variable scope is same as local variable.
	 * But lifetime is same as program's lifetime. 
	 */	
	cout<<"Static Variable:"<<endl;
	for(int i=0;i<5;i++)
		staticvar();
	cout<<endl;
    
    /* Pointer and Reference Variable
     */
	cout<<"Pointer and Reference Variable:"<<endl;
	int a1=5,a2;
	a2=a1;
	int *p1=&a1;
	int &a3=a1;
	printf("%llu %d %d %d %d\n", p1,*p1,a1,a2,a3);
	a1=10;
	printf("%llu %d %d %d %d\n", p1,*p1,a1,a2,a3);


    /* Constant variable and pointers
     */
	cout<<"Constant Variable and Pointer:"<<endl;
	const int a4=25;			//constat integer: a=10 is illegal
	const int *p2=&a4;			//pointer to a constant variable
	int * const p3=&a1;			// constant pointer: p3=&a2 is illegal but *p3=10 is legal
	const int * const p4=&a4;	//constant char and pointer: p4=&string1 and *p4="abc" is illegal
	
	/* Global variable and :: Operator
	 */
	cout<<"Scope:"<<endl;
	{
		int ga=200;
		{
			int ga=300;
			printf("%d %d\n", ga,::ga);
		}
	}

	/* Return by Reference
	 */
	cout<<"Return by Reference:"<<endl;
	cout<<a1<<" "<<a2<<endl;
	*(max1(&a1,&a2))=1;
	cout<<a1<<" "<<a2<<endl;
	max2(a1,a2)=1;
	cout<<a1<<" "<<a2<<endl;

	/* Object Orientation
	 */
	cout<<"OOP:"<<endl;
	Circle c1(7);
	cout<<c1.calArea()<<endl;

	/*static member scope only class but lifetime is same as liftime of class
	 */
	cout<<"Static Class Member:"<<endl;
	cout<<Circle::getCount()<<endl;
	

	/* Friend function: can have access to private data members and can be shared among multiple class 
	 */
	cout<<"Friend Funciton:"<<endl;
	Square s1(3);
	cout<<c1.getRad()<<" "<<s1.getLen()<<endl;
	exchange(c1,s1);
	cout<<c1.getRad()<<" "<<s1.getLen()<<endl;

	/* Constanct Member Funciton: can not alter data
	 */
	cout<<"Constant Member Function:"<<endl;
	c1.cannotAlter();

	/* Class and Pointers
	 * :: operator defines member of class
	 * ::* operator defines pointer to member of class
	 * -> operator defines pointer of object to member of class
	 * ->* operator defines pointer of object to pointer to member of class 
	 */
	cout<<"Class and Pointer:"<<endl;
	Circle *pc1=&c1;
	int Circle::* pvar=&Circle::var;
	int (Circle::* prad)()= &Circle::getRad;
	cout<<c1.*pvar<<" "<<pc1->*pvar<<endl;
	cout<<(c1.*prad)()<<" "<<(pc1->*prad)()<<endl;

	/* Operator Overloading
	 * Also can be implemented using friend function
	 * 		|-> Why? in case first argunment is other than class type 
	 */
	cout<<"Operator Overloading:"<<endl;
	Circle c2(4);
	Circle c3;
	c3=c1+c2;
	cout<<c3.getRad()<<endl;

	/* Type Conversation
	 * Basic -> Class: Constructor used
	 * Class -> Basic: Casting Operator
	 * Class -> Class: Both
	 */
	float f1=c1;
	printf("%f\n", f1);
	return 0;
}