/*
javac -cp ../lib:../target/ -d ../target/ com/mypackage/exception/MyException.java
*/

package com.mypackage.exception;

import javax.ws.rs.core.Response;
import javax.ws.rs.ext.ExceptionMapper;
import javax.ws.rs.ext.Provider;

@Provider
public class MyExceptionMapper implements ExceptionMapper<Exception> {

    @Override
    public Response toResponse(Exception eobj) {
        System.out.println("Exception Mapper called: "+eobj);
        return null;
    }

}