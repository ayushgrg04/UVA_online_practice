import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.*;


public class Main {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
        int flag;
        StringBuffer res;
        int len;
        
        void pln(String s){
            out.println(s);
        }

        
	void solve()
	{
		Scanner st = new Scanner(System.in);
    	// String s = "";
    	// s = st.nextLine();
    	double a,b,d,fac,pr;
    	int c,x,y,z;
    	int i,j,k;
    	int num,T,t,n,day;
    	String s;
    	char cc;
    	c=0;
    	while(true){
    		n=ni();
    		if(n==0) return;
    		y=0;z=0;
			i=1;
			c=0;    		
    		for(j=0;j<n-1;j++){
    			s=ns();


    			if(c==1 && y%4==0){
    				c=0;i=1;
    			} 
    			else if(c==2 && z%4==0){
    				c=0;i=1;
    			}
    			else if(c==1 && (y%4==2 || y%4==-2)){
    				c=0;i=-1;
    			}
    			else if(c==2 && (z%4==2 || z%4==-2)){
    				c=0;i=-1;
    			}


				if(c==0){
					switch(s){
						case "+y" :{c=1; y=1*i;break;}
						case "-y" :{c=1; y=-1*i;break;}
						case "+z" :{c=2; z=1*i;break;}
						case "-z" :{c=2; z=-1*i;break;}
						default :{}
					}
				}
				else{
					if(s.equals("+y")) y++;
					else if(s.equals("-y")) y--;
    				else if(s.equals("-z")) z--;
    				else if(s.equals("+z")) z++;
    			}





    		}

    		// out.println("c y z i"+ c +" "+y+" "+z+" "+i);
    		if(c==0 && i==1) out.println("+x");
    		else if(c==0 && i==-1) out.println("-x");
    		else if(c==1){
    			if(y%4==0) out.println("+x");
    			else if(y%4==1 || y%4==-3) out.println("+y");
    			else if(y%4==2 || y%4==-2) out.println("-x");
    			else out.println("-y");
    				
    		}
    		else{
    			if(z%4==0) out.println("+x");
    			else if(z%4==1 || z%4==-3) out.println("+z");
    			else if(z%4==2 || z%4==-2) out.println("-x");
    			else out.println("-z");

    		}
    	}
    	

    		// out.println();	
    	
    		

		     
    }
         
        
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new Main().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = new Integer(ni());
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}

//	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private boolean oj = true;
        private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}

