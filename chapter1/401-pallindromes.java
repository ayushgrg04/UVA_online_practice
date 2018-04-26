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
    	HashMap<Character, Character> hm = new HashMap<>();
    	hm.put('A','A');hm.put('E','3');hm.put('H','H');hm.put('I','I');
    	hm.put('J','L');hm.put('L','J');hm.put('M','M');hm.put('O','O');
    	hm.put('S','2');hm.put('T','T');hm.put('U','U');hm.put('V','V');
    	hm.put('W','W');hm.put('X','X');hm.put('Y','Y');hm.put('Z','5');
    	hm.put('1','1');hm.put('2','S');hm.put('3','E');hm.put('5','Z');
    	hm.put('8','8');

    	String s;
    	int fl=0;
    	while(st.hasNext()){
    		
    		s=st.next();
    		// if(s==EOF) return;
    		if(fl!=0) System.out.println();

    		fl=1;
    		char[] cc = new char[s.length()];
    		int len = s.length();
    		for(int i=0;i<len;i++) cc[i]=s.charAt(i);
    		int pal=0, mirr=0;
    		int low=0,high=len-1;
    		while(low<high){
    			if(cc[low]!=cc[high]) break;
    			low++;high--;
    		}
    		if(low>=high) pal=1;

    		int i=0;
    		for(i=0;i<len;i++){
    			char tmp=cc[i];
    			if(hm.containsKey(cc[i]))
    				tmp = hm.get(tmp);
    			else break;
    			if(tmp!=cc[len-1-i])break;
    		}
    		if(i==len) mirr=1;

    		if(pal==0 && mirr==0){
    			System.out.print(s+" -- is not a palindrome.");
    			System.out.println();
    		}
    		else if(pal==1 && mirr==0){
    			System.out.print(s+" -- is a regular palindrome.");
    			System.out.println();
    		}
    		else if(pal==0 && mirr==1){
    			System.out.print(s+" -- is a mirrored string.");
    			System.out.println();
    		}
    		else{
    			System.out.print(s+" -- is a mirrored palindrome.");
    			System.out.println();
    		}
    		

    	}
    	System.out.println();
		

    }


    void pA(char[][] arr, int n, int m){
    	for(int i=0;i<n;i++){
    		for(int j=0;j<m;j++)
    			out.print(""+arr[i][j]);
    		out.println("");
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
