package choo1homework;
class A{
	static int i;
	void change(int i1)
	{
		i=i1;
	}
}
public class Test01 {
	public static void main(String args[])
	{
		A.i=10;
		A a=new A();
		A b=new A();
		System.out.println(A.i+","+b.i);
		a.change(40);
		System.out.println(A.i+","+a.i+","+b.i);
		b.i+=10;
		System.out.println(A.i+","+a.i+","+b.i);
		
	}
}
