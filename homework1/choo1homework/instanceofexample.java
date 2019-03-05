package choo1homework;

class Vehicle{}

public class instanceofexample extends Vehicle{
	
	public static void main(String[] args)
	{
		Vehicle a =new instanceofexample();
		boolean result = a instanceof instanceofexample;
		System.out.println( result);
		
	}
}
