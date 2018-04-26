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
    	long a,b,c,d,fac,pr=0;
    	int x,y,z,res;
    	long i,j,k;
    	int num,T,t,n,day;
    	String s;
    	char cc;
    	int[] arr;
    	n=ni();
    	while((n--)!=0){
    		k=0;t=0;
    		a=st.nextLong();
    		b=st.nextLong();
    		c=st.nextLong();
    		x=(int)Math.sqrt(c)+1;
    		y=(int)Math.cbrt(b)+1;
    		
    		out.println(""+x+" "+y);
    		lbl:
    			for(i=-y;i<=y;i++){
    				if(i!=0 && b%i!=0) continue;
    				if(i*i>c) continue;
    				int tm=1000000000;
    				if(i!=0)
    				tm=(int)Math.sqrt((b/Math.abs((int)i)+1))+1;
    				for(j=i+1;j<=min(x,tm);j++){
    					if(j!=0 && b%j!=0) continue;
    					if(i==j || i*i+j*j>c) continue;
    					k= a-(i+j);
    					if(i!=k && j!=k && i*i+j*j+k*k==c && i*j*k==b){
    						out.println(""+i+" "+j+" "+k);
    						t=1;
    						break lbl;
    					}

    				}
    			}

    		if(t==0)out.println("No solution.");	

    		
    	}
    		

		     
    }

    long min (long a, long b){
    	return a>b?b:a;
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

