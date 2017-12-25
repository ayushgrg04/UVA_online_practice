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
    	int t=0;
		
		while(true){
			int n = ni();
			if(n==0) return;
			t++;
			int[] X = new int[2*n];
			int[] Y = new int[2*n];
			for(int i=0;i<2*n;i++){
				ns();
				X[i] = ni();
				Y[i] = ni(); 
			}

			double[][] dis = new double[2*n][2*n];
			for(int i=0;i<2*n;i++){
				for(int j=i+1;j<2*n;j++){
					int z = X[i]-X[j];
					int y = Y[i]-Y[j];
					dis[i][j] = Math.sqrt((z*z) + (y*y));
					dis[j][i] = dis[i][j];
				}
			}

			int[] dp = new int[2*n];
			double res = minD(0, n, dis, dp, 0, 1000000000, 0);
			res = res + 0.005;
			res = ((int)(res*100))/100.00;
			out.print("Case "+t+": ");
			out.printf("%.2f\n", res);
		}     
    }
         
         
    

    

    int min(int a, int b) {
        return (a < b) ? a : b;
    }
    
    public double minD(int z, int n,double[][] dis, int[] dp, double t_dis, double sum, int tmp){
		if(tmp==2*n) {
			// System.out.println(""+t_dis);
			if(sum >  t_dis) sum = t_dis;
			return sum;
		}
		double td = 1000000000;
		int i=z;
		for( i=0;i<2*n;i++){
			if(dp[i]==0){break;}
		}
			
			for(int j=i+1;j<2*n;j++){
				if(dp[j]==1) continue;
				
				if(t_dis + dis[i][j] >= sum) continue;
				t_dis += (dis[i][j]);
				dp[i]=1;
				dp[j]=1;
				sum = minD(i+1, n, dis, dp, t_dis, sum, tmp+2);
				t_dis -= (dis[i][j]);
				dp[i]=0;
				dp[j]=0;
			}
			
		

		return sum;

	}   
        
        
	
	public static int[] radixSort(int[] f)
	{
		int[] to = new int[f.length];
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(f[i]&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[f[i]&0xffff]++] = f[i];
			int[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(f[i]>>>16)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[f[i]>>>16]++] = f[i];
			int[] d = f; f = to;to = d;
		}
		return f;
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

