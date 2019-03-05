package homework1_3;
import java.util.Scanner;

public class homework3 {
	public static void main(String []args)
	{
		int b;//输入的整数
		int count=0;//数组下标
		int [] a=new int[10];
		System.out.println("输入一个整数：");
		Scanner input=new Scanner(System.in);
		b=input.nextInt();//输入一个整数
		for(int i=2;i<=b;i++)
		{
			if(b%i==0) {
				a[count]=i;
				count++;
				b=b/i;
				i--;//防止相同的质因数只出现一次
			}
		}
		if(count==1)
		{
			System.out.println("这是一个质数");
		
		}
		else
		{
			for(int i=0;i<count;i++)
			{
				System.out.print(a[i]+" ");
				
			}
		}
		input.close();
		
		
		
	}
}
