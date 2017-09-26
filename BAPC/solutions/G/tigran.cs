// @EXPECTED_RESULTS@: CORRECT
/*
 *  By: Tigran
 *  Method: Gewoon doen
 */

using System;

class MessageSigning
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        while (n-- > 0)
        {
            string message = Console.ReadLine();
            int[] count = new int[26];
            bool isValid = true;

            for (int i = 0; i < message.Length; i++)
            {
                count[message[i] - 'A']++;
                if (count[message[i] - 'A'] == 3)
                {
                    if (i + 1 >= message.Length) isValid = false;
                    else if (message[i] != message[i + 1]) isValid = false;
                    count[message[i] - 'A'] = 0;
                    i++;
                }
            }
            Console.WriteLine(isValid ? "OK" : "FAKE");
        }
    }
}
