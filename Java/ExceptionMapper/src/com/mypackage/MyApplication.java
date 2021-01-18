/*
javac -d ../target/ com/mypackage/MyApplication.java
java com.mypackage.MyApplication
*/

package com.mypackage;

import com.mypackage.exception.MyException;

public class MyApplication {
	
	public static void main(String args[]) throws Exception{
		throw new MyException("Testing Exception Mapper", new NullPointerException());
	}

}