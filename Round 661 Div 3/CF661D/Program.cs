using System;
using System.Collections.Generic;

namespace CF661D
{
    class Program
    {
        static void Main(string[] args)
        {
            int t, n, i, p;
            string str;
            List<int> ansPos;
            List<string> all;
            Queue<int> posZero, posOne;

            t = Convert.ToInt32(Console.ReadLine());
            while (t-- > 0) {
                n = Convert.ToInt32(Console.ReadLine());
                str = Console.ReadLine();
                all = new List<string>();
                ansPos = new List<int>();
                posZero = new Queue<int>();
                posOne = new Queue<int>();

                for (i = 0; i < n; i++) {
                    if (str[i] == '0') {
                        if (posOne.Count > 0) {
                            p = posOne.Dequeue();
                            all[p] += "0";
                        }
                        else {
                            p = all.Count;
                            all.Add("0");
                        }

                        ansPos.Add(p + 1);
                        posZero.Enqueue(p);
                    }
                    else {
                        if (posZero.Count > 0) {
                            p = posZero.Dequeue();
                            all[p] += "1";
                        }
                        else {
                            p = all.Count;
                            all.Add("1");
                        }

                        ansPos.Add(p + 1);
                        posOne.Enqueue(p);
                    }
                }

                Console.WriteLine(all.Count);
                foreach (var x in ansPos) {
                    Console.Write(x + " ");
                }
                Console.WriteLine();
            }
        }
    }
}
