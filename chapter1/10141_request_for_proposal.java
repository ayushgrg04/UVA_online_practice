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
    	num=1;
    	int flag=0;
    	while(true){
    		a=st.nextInt();b=st.nextInt();
    		st.nextLine();
    		if(a==0 && b==0) break;
    		if(flag==1){
    			out.println();
    		}
    		flag=1;
    		for(i=0;i<a;i++)st.nextLine();
    		String cname="";
    		d=Double.MAX_VALUE;
    		c=Integer.MIN_VALUE;
    		for(i=0;i<b;i++){
    			String tt = st.nextLine();
    			pr=st.nextDouble();
    			x=st.nextInt();
    			st.nextLine();
    			for(j=0;j<x;j++) st.nextLine();
    			if(x>c){
    				// out.println(""+cname+" AYUSH"+tt+" "+c+" "+x);
    				c=x;
    				cname=tt;d=pr;

    			}
    			else if(x==c){
    				if(pr<d){
    					// out.println(""+cname+" AYUSH"+tt+" "+d+" "+pr);
    					// c=x;
    					cname=tt;d=pr;		
    				}
    			}
    		}

    		out.println("RFP #"+num);
    		num++;
    		out.println(cname);
    		// out.println();	
    	}
    		

		     
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

