import java.io.*;
import java.util.*;
import java.net.*;  

public class Tester{
	
	public static void main(String[] args){
		Server ser=new Server();
		ser.start();
		System.out.println("Exiting.");
	}

}

class Server{
	
	HashMap<Integer,ClientHandler> a;
	int cnt;

	Server(){
		a=new HashMap<>();
		cnt=0;
		System.out.println("Hello Server!");
	}

	public void start(){
		try{
			ServerHandler server=new ServerHandler();
			server.start();
			System.out.println("Server started.");
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			String cmd=br.readLine();
			while(!cmd.equals("exit")){
				if(cmd.equals("send")){
					System.out.print("Enter Client No: ");
					int cno=Integer.parseInt(br.readLine());
					if(a.get(cno)==null){
						System.out.println("Invalid Client.");
						cmd=br.readLine();
						continue;
					}
					System.out.print("Enter Message: ");
					String msg=br.readLine();
					a.get(cno).sendMsg(msg);
				}
				else{
					System.out.println("Invalid command");
				}
				cmd=br.readLine();
			}
			System.out.println("Shutting down server.");
			server.stop();
			return;
		}
		catch(Exception eobj){
			System.out.println(eobj);
		}
	}

	class ServerHandler extends Thread{
		
		ServerSocket ss;

		ServerHandler(){
			try{
				ss=new ServerSocket(6666);
			}
			catch(Exception eobj){
				System.out.println(eobj);
			}
		}

		@Override
		public void run(){
			try{
				while(true){
					Socket s=ss.accept();
					DataOutputStream dout=new DataOutputStream(s.getOutputStream());
					DataInputStream din=new DataInputStream(s.getInputStream());
					ClientHandler c=new ClientHandler(din,dout,cnt);
					a.put(cnt,c);
					c.start();
					cnt++;
				}
			}
			catch(Exception eobj){
				System.out.println(eobj);
			}
		}

	}

	class ClientHandler extends Thread{

		int id;
		DataInputStream din;
		DataOutputStream dout;

		public ClientHandler(DataInputStream din,DataOutputStream dout,int cnt){
			this.din=din;
			this.dout=dout;
			id=cnt;
		}

		@Override
		public void run(){
			try{
				while(true){
					String msg=din.readUTF();
					System.out.println("Message from Client "+id+": "+msg);
				}
			}
			catch(Exception eobj){
				System.out.println("Client "+id+" disconnected.");
				a.remove(id);
				return;
			}
		}

		public void sendMsg(String msg){
			try{
				dout.writeUTF(msg);
				dout.flush();
			}
			catch(Exception eobj){
				System.out.println(eobj);
			}
		}

	}

}