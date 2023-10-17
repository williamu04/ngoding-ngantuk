using System;
namespace ConsoleApp { 
    class Program { 
        static void Main(string[] args) { 
            int n; n = int.Parse(Console.ReadLine());
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == 0 || i == n - 1 || j == 0 || j == n - 1 || Math.Abs(i - n / 2) + Math.Abs(j - n / 2) >= n / 2) {
                        Console.Write("* ");
                    }
                    else {
                    Console.Write("  ");
                    }
                }
                Console.WriteLine();
            }
        }
    }
}