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
        // int flag;
        // StringBuffer res;
 

        // int len;
		        
        void pln(String s){
            out.println(s);
        }

  	// char[] c;
  	// int len;
  	// int res;
  
	void solve()
	{
		Scanner st = new Scanner(System.in);
    	// String s = "";
    	// s = st.nextLine();
    	// tmp[0]=1;
		while(true){
			int arr[] = new int[5];
    		int[] tmp = new int[53];
 
			for(int i=0;i<5;i++){
				arr[i]=ni();
				tmp[arr[i]]=1;
			}
			// out.println(""+arr[0]+" "+arr[1]+" "+arr[2]+" "+arr[3]+" "+arr[4]);
			if(arr[0]==0) return;
			for(int i=0;i<3;i++){
				for(int j=i+1;j<3;j++){
					if(arr[i]>arr[j]){
						int tt = arr[i];
						arr[i]=arr[j];
						arr[j]=tt;
					}
				}
			}

			if(arr[3]>arr[4]){
				int tt = arr[3];
				arr[3]=arr[4];
				arr[4]=tt;
			}

			int min=Integer.MAX_VALUE;
			if(arr[3]>arr[2]){
				for(int i=1;i<=52;i++){
					if(tmp[i]==0){
						if(min>i)min=i;
						break;
					}
				}
				// continue;
			}
			if(arr[3]>arr[1]){
				int fl=0;
				for(int i=arr[1]+1;i<=52;i++){
					if(tmp[i]==0){
						// out.println(""+i);
						if(min>i) min=i;
						fl=1;
						break;
					}
				}
				// if(fl==0) out.println("-1");
				// continue;	
			}
			if(arr[4]>arr[2]){
				int fl=0;
				for(int i=arr[2]+1;i<=52;i++){
					if(tmp[i]==0){
						// out.println(""+i);
						if(min>i) min =i;
						fl=1;
						break;
					}
				}
				// if(fl==0) out.println("-1");
				// continue;	
			}	
			if(min!=Integer.MAX_VALUE) out.println(""+min);
			else out.println("-1");


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
	private long nl()
	{
		long num = 0;
		int b;
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
