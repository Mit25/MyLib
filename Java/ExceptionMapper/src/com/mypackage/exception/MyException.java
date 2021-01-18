/*
javac -d ../target/ com/mypackage/exception/MyException.java
*/

package com.mypackage.exception;

public class MyException extends Exception {

	public MyException() {
        super();
    }
    
    public MyException(String msg) {
        super(msg);
    }
    
    public MyException(String msg, Exception e) {
        super(msg, e);
    }

}