package homework1_3;
import java.util.Scanner;

public class homework2 {
	public static void main(String [] args)
	{
		int space=0;
		int num=0;
		int word=0;
		int other=0;
		Scanner input=new Scanner(System.in);
		System.out.println("�����ַ�����");
		String str=input.nextLine();
		for(int i=0;i<str.length();i++)
		{
			if(str.charAt(i)==32)
			{
				space++;
			}
			else if(str.charAt(i)>=48&&str.charAt(i)<=57)
			{
				num++;
			}
			else if(str.charAt(i)>=65&&str.charAt(i)<=90)
			{
				word++;
			}
			else if(str.charAt(i)>=97&&str.charAt(i)<=122)
			{
				word++;
			}
			else 
			{
				other++;
			}
		}
		System.out.println("��"+space+"���ո�"+word+"����ĸ��"+num+"������,"+other+"�������ַ�");
		input.close();
	}
	
}
