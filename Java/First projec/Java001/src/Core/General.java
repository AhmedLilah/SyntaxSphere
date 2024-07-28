package Core;

import java.util.Scanner;

public class General
{
    public static void func()
    {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the first number: ");
        int a = input.nextInt();
        System.out.print("Enter the second number: ");
        int b = input.nextInt();
        System.out.println("The sum is: " + (a+b));
    }
}