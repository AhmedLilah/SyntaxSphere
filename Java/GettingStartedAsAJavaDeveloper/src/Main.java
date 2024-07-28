import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        int number = 6;
        double doubleNumber = 435.52345;
        float floatNumber = 323454524352.4134124f;
        short shortNumber = (short) 41234;
        System.out.println("This is fucken Dracula them");
        System.out.println("Hello world!");
        System.out.println(addFunction((int)doubleNumber, number));
        Scanner scanner = new Scanner(System.in);
        String input = scanner.next();
        System.out.println(input);
        for (int i = 0; i <= 100; ++i) {
            System.out.print("Process progress bar [");
            for ( int j = 0; j < i; ++j) {
                System.out.print("#");
            }
            for ( int j = (100-i); j > 0; --j) {
                System.out.print("-");
            }
            System.out.print("] "+ i*100/100 + "%.");
            Thread.sleep(100);
            System.out.print("\r");
        }
    }
    public static int addFunction (int a, int b)
    {
        return a + b;
    }
}