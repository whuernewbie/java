package choo1homework;

public class Employee{
   // ���ʵ������������ɼ�
   public String name;
   // ˽�б��������ڸ���ɼ�
   private double salary;
   //�ڹ������ж�name��ֵ
   public Employee (String empName){
      name = empName;
   }
   //�趨salary��ֵ
   public void setSalary(double empSal){
      salary = empSal;
   }  
   // ��ӡ��Ϣ
   public void printEmp(){
      System.out.println("���� : " + name );
      System.out.println("нˮ : " + salary);
   }
 
   public static void main(String args[]){
      Employee empOne = new Employee("Tom");
      empOne.setSalary(3000);
      empOne.printEmp();
   }
}

