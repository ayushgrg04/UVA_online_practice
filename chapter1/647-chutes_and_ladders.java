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
		// int T=ni();
		// int[] pl = new int[10000001];
		int[] dice = new int[1001];
		int i1=0;
		int n;
		while(true){
			dice[i1]= ni();
			if(dice[i1]==0) break;
			i1++;
		}

		while(true){
			//first part
			int playr = ni();
			if(playr==0) break;
			int[] pl = new int[playr];
			// for(int i=0;i<playr;i++) pl[i]=1;
		
			// second part
			HashMap<Integer, Integer> hm = new HashMap<>();
			while(true){
				int n1 = ni(), n2=ni();
				if(n1==0 && n2==0) break;
				hm.put(n1, n2);
			}


			//third part

			while(true){
				int n1 = ni();
				if(n1==0) break;
				if(n1<0) hm.put(-n1, -1);
				else hm.put(n1, -2);
			}

			int p=0;
			int[] miss = new int[playr];
			for(int i=0;i<1001;i++,p++){
				int dd = dice[i];
				int py = p%playr;
				while(miss[py]==1){
					miss[py]=0;
					p++;
					py = p%playr;
				}

				int pos = pl[py]+dd;
				if(hm.containsKey(pos)){
					int gh = hm.get(pos);
					if(gh==-1){
						miss[py]=1;
					}
					else if(gh==-2){
						p--;
					}
					else{
						pos = gh;
					}
					
				}

				if(pos==100){
					out.println(""+(py+1));
					break;

				}
				else if(pos>100){
					pos=pl[py];
				}

				pl[py]=pos;
				// out.println(""+pl[py]+" "+ dd+" "+py);

			}

		}


		

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
