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
        // StringBuffer res;
 

        int len;
		        
        void pln(String s){
            out.println(s);
        }

	void solve()
	{
		Scanner st = new Scanner(System.in);
    	// String s = "";
    	// s = st.nextLine();
    	int i;
    	int[] S=new int[14];int[] H=new int[14];int[] D=new int[14];int[] C=new int[14];
    	int sl=0,hl=0,dl=0, cl=0;
    	int score=0;
    	String s;
    	int[][] arr = new int[4][14];
    	int[] stop = new int[4];


    	while(st.hasNext()){
    		// arr[0][0]=arr[1][0]=arr[2][0]=arr[3][0]=0;
    		for(i=0;i<4;i++)
    			for(int j=0;j<14;j++)
    				arr[i][j]=0;
    		score=0;
    		
    		for(i=0;i<13;i++){
    			s=st.next();
    			int t1, t2;
    			if(s.charAt(1)=='S') t1=0;
    			else if(s.charAt(1)=='H') t1=1;
    			else if(s.charAt(1)=='D') t1=2;
    			else t1=3;
    			if(s.charAt(0)=='A'){ t2=1;score+=4;}
    			else if(s.charAt(0)=='T'){ t2=10; }
    			else if(s.charAt(0)=='J'){ t2=11; score+=1;}
    			else if(s.charAt(0)=='Q') {t2=12;score+=2;}
    			else if(s.charAt(0)=='K') {t2=13;score+=3;}
    			else t2=(int) (s.charAt(0)-'0');
    			// out.println("t1 t2 "+t1+" "+t2+" ");
    			arr[t1][t2]++;
    			arr[t1][0]++;


    		}
    		stop[0]=stop[1]=stop[2]=stop[3]=0;

    		int fsc=score;

    		if(arr[0][13]==1 && arr[0][0]==1) fsc--;
    		else if(arr[0][13]==1 && arr[0][0]>1 ) stop[0]=1;
    		if(arr[1][13]==1 && arr[1][0]==1) fsc--;
    		else if(arr[1][13]==1 && arr[1][0]>1)stop[1]=1;
    		if(arr[2][13]==1 && arr[2][0]==1) fsc--;
    		else if(arr[2][13]==1 && arr[2][0]>1)stop[2]=1;
    		if(arr[3][13]==1 && arr[3][0]==1) fsc--;
    		else if(arr[3][13]==1 && arr[3][0]>1)stop[3]=1;

    		if(arr[0][12]==1 && arr[0][0]<=2) fsc--;
    		else if(arr[0][12]==1 && arr[0][0]>2)stop[0]=1;
    		if(arr[1][12]==1 && arr[1][0]<=2) fsc--;
    		else if(arr[1][12]==1 && arr[1][0]>2)stop[1]=1;
    		if(arr[2][12]==1 && arr[2][0]<=2) fsc--;
    		else if(arr[2][12]==1 && arr[2][0]>2)stop[2]=1;
    		if(arr[3][12]==1 && arr[3][0]<=2) fsc--;
    		else if(arr[3][12]==1 && arr[3][0]>2)stop[3]=1;

    		for(i=0;i<4;i++){
    			if(arr[i][11]==1 && arr[i][0]<=3) fsc--;
    			if(arr[i][1]==1) stop[i]=1;

    		}
    		int tsc = fsc;

    		for(i=0;i<4;i++){
    			if(arr[i][0]==0 || arr[i][0]==1) tsc+=2;
    			if(arr[i][0]==2) tsc++;
    		}
    		// System.out.println("tsc fsc"+tsc+" "+fsc);

    		if(fsc>=16 && ((stop[0] & stop[1] & stop[2] & stop[3])==1)){
    			System.out.println("BID NO-TRUMP");
    		}
    		else if(tsc>=14){
    			int max=arr[0][0];
    			int res=0;
    			for(i=1;i<4;i++)
    				if(arr[i][0]>max){ max = arr[i][0];res=i;}
    			if(res==0) System.out.println("BID S");
    			else if(res==1) System.out.println("BID H");
    			else if(res==2) System.out.println("BID D");
    			else System.out.println("BID C");

    		}
    		else{
    			System.out.println("PASS");
    		}

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
