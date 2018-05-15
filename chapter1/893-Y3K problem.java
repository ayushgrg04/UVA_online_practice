import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;

class solution{
	public static void main(String args[]){
		Scanner std = new Scanner(System.in);
		while(true){
			// System.out.println("ayusy");
			int n = std.nextInt();
			int da = std.nextInt();
			int mnt= std.nextInt();
			int yr = std.nextInt();

			if(n==0 && da==0 && mnt==0 && yr==0 ) break;;

			Calendar date = Calendar.getInstance();
			date.set(yr, mnt-1, da);
			date.add(Calendar.DAY_OF_MONTH, n);

			da = date.get(Calendar.DAY_OF_MONTH);
			mnt = date.get(Calendar.MONTH)+1;
			yr = date.get(Calendar.YEAR);

			System.out.println(""+da+" "+mnt+" "+yr); 
		}
	}
}