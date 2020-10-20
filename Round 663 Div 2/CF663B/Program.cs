using System;
using System.Collections.Generic;

namespace CF663B
{
    class Program
    {
        static void Main(string[] args)
        {
            int t, n, m, i, ans;
            List<string> grid;
            string[] line;

            t = Convert.ToInt32(Console.ReadLine());
            while (t-- > 0) {
                // Console.WriteLine(t);
                line = Console.ReadLine().Split();
                n = Convert.ToInt32(line[0]);
                m = Convert.ToInt32(line[1]);
                grid = new List<string>();
                for (i = 0; i < n; i++) {
                    grid.Add(Console.ReadLine());
                }

                ans = 0;
                for (i = 0; i < n - 1; i++) {
                    if (grid[i][m - 1] != 'D') {
                        ans++;
                    }
                }
                for (i = 0; i < m - 1; i++) {
                    if (grid[n - 1][i] != 'R') {
                        ans++;
                    }
                }
                Console.WriteLine(ans);
            }
        }
    }
}
