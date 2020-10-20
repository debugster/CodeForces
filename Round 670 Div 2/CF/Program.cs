using System;
using System.Collections.Generic;

namespace CF
{
    class Program
    {
        public static int Cmp(long x, long y)
        {
            return y.CompareTo(x);
        }
        
        static void Main(string[] args)
        {
            int t, n, i, c;
            long a, zero, ans, mx;
            List<long> pos, neg;
            string[] all;

            t = Convert.ToInt32(Console.ReadLine());
            while (t > 0) {
                // Console.WriteLine(t);
                
                n = Convert.ToInt32(Console.ReadLine());
                pos = new List<long>();
                neg = new List<long>();
                zero = 0;
                all = Console.ReadLine().Split();
                foreach (var num in all) {
                    a = Convert.ToInt64(num);
                    // Console.WriteLine(a);
                    if (a > 0) {
                        pos.Add(a);
                    }
                    else if (a < 0) {
                        neg.Add(a);
                    }
                    else {
                        zero++;
                    }
                }

                pos.Sort(Cmp);
                neg.Sort();

                if (n == 5) {
                    if (zero > 0) {
                        ans = 0;
                    }
                    else {
                        ans = 1;
                        foreach (var x in pos) {
                            ans *= x;
                        }
                        foreach (var x in neg) {
                            ans *= x;
                        }
                    }
                }
                else {
                    ans = -1000000000000000000;
                    mx = -1000000000000000000;

                    if (pos.Count >= 3 && neg.Count >= 2) {
                        mx = 1;
                        for (i = 0; i < 3; i++) {
                            mx *= pos[i];
                        }
                        for (i = 0; i < 2; i++) {
                            mx *= neg[i];
                        }
                    }
                    else if (zero > 0) {
                        mx = 0;
                    }
                    ans = Math.Max(mx, ans);

                    if (pos.Count >= 1 && neg.Count >= 4) {
                        mx = pos[0];
                        for (i = 0; i < 4; i++) {
                            mx *= neg[i];
                        }
                    }
                    else if (zero > 0) {
                        mx = 0;
                    }
                    ans = Math.Max(mx, ans);

                    if (pos.Count >= 5) {
                        mx = 1;
                        for (i = 0; i < 5; i++) {
                            mx *= pos[i];
                        }
                    }
                    ans = Math.Max(mx, ans);

                    if (pos.Count == 0) {
                        if (zero > 0) {
                            ans = 0;
                        }
                        else {
                            ans = 1;
                            for (i = neg.Count - 1, c = 1; c <= 5; i--, c++) {
                                ans *= neg[i];
                            }
                        }
                    }
                }
                
                Console.WriteLine(ans);
                t--;
            }
        }
    }
}
