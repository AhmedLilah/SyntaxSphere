namespace ConsoleApp2
{
	internal class Program
	{
		static int add(int x, int y)
		{
			return x + y;
		}

		static void println<T>(T str) { 
			Console.WriteLine(str);
		}

		static float mul(float x, float y) { 
			return x * y;
		}

		static void Main(string[] args)
		{
			Console.WriteLine("Hello, World!");
			int x = 0;
			int y = 5;
			int result = add(x, y);
			println(result);

			float X=6.0f, Y=5.0f;
			println(mul(X, Y));

			int[] arr = { 1 , 2, 3, 4, 5, 6, 7};

			for (int i = 0; i < arr.Length; i++) {
				println(arr[i]);
			}
		}
	}
}