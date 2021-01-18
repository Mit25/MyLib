import java.io.*;
import java.util.*;
import java.net.*;  

public class Http{
	
	public static void main(String[] args){
		System.out.println("Connecting World!");
		try{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			String fn,ln;
			System.out.print("Enter firstname: ");
			fn=br.readLine();
			System.out.print("Enter lastname: ");
			ln=br.readLine();
	        URL url=new URL("http://127.0.0.1/submit.php");
	        URLConnection con = url.openConnection();
	        con.setDoOutput(true);
	        PrintStream ps = new PrintStream(con.getOutputStream());
	        ps.print("&firstname="+fn);
	        ps.print("&lastname="+ln);
	        con.getInputStream();
	        ps.close();
		} 
	    catch(Exception eobj){
	    	System.out.println(eobj);;
	    }
	}

}