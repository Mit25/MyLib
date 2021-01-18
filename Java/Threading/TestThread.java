import java.io.*;
import java.util.*;

public class TestThread{
	
	public static void main(String[] args){
		System.out.println("Hello World!");
		MyClass m=new MyClass();
		MyClass m1=new MyClass();
		m.start();
		m1.start();
	}

}

class MyClass extends Thread{
	
	public void run(){
		for(int i=0;i<10;i++){
			System.out.println("Test:"+i);
		}
	}


}