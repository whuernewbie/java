package homework1_3;
import java.util.Scanner;

public class homework3 {
	public static void main(String []args)
	{
		int b;//���������
		int count=0;//�����±�
		int [] a=new int[10];
		System.out.println("����һ��������");
		Scanner input=new Scanner(System.in);
		b=input.nextInt();//����һ������
		for(int i=2;i<=b;i++)
		{
			if(b%i==0) {
				a[count]=i;
				count++;
				b=b/i;
				i--;//��ֹ��ͬ��������ֻ����һ��
			}
		}
		if(count==1)
		{
			System.out.println("����һ������");
		
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
