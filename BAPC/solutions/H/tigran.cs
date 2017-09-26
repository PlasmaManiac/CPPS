// @EXPECTED_RESULTS@: CORRECT
/*
 *  By: Tigran
 *  Method: Gewoon doen
 */

using System;

class CarEquipment
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        while (n-- > 0)
        {
            int totalPrice = int.Parse(Console.ReadLine());
            int nn = int.Parse(Console.ReadLine());

            while (nn-- > 0)
            {
                string[] s = Console.ReadLine().Split();
                totalPrice += int.Parse(s[0]) * int.Parse(s[1]);
            }
            Console.WriteLine(totalPrice);
        }
    }
}
