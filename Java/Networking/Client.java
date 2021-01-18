import java.io.*;
import java.util.*;
import java.net.*;  

public class Client{
	
	public static void main(String[] args){
		System.out.println("Hello Client!");
		try{
			Socket s=new Socket("localhost",6666);
			DataOutputStream dout=new DataOutputStream(s.getOutputStream());
			DataInputStream din=new DataInputStream(s.getInputStream());
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			String cmd=new String();
			while(true){
				while(din.available()>0){
					String msg=din.readUTF();
					System.out.println("Recieved Message: "+msg);
				}
				cmd=br.readLine();
				if(cmd.equals("send")){
					System.out.println("Enter Message: ");
					String msg=br.readLine();
					dout.writeUTF(msg);
					dout.flush(); 
				}
				else if(cmd.equals("exit")){
					break;
				}
				else{
					System.out.println("Invalid command");
				}
			}
			br.close();
			din.close();
			dout.close();
			s.close();
		}
		catch(Exception eobj){
			System.out.println(eobj);
		}
	}

}