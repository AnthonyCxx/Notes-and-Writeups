using System;
using System.Text;
using System.Text.RegularExpressions;

namespace TextFilterer
{
    class Program
    {   
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.Unicode;

            string text = "長いnagai１日だったdattaのでnodeおo疲れtsukareでしょうdeshou」「いいえiie、全然zenzen";
            string removalPattern = @"[a-zA-Z]";

            Console.WriteLine(Remove(text, removalPattern));
        }

        public static string Remove(string input, string pattern)
        {
            return Regex.Replace(input, pattern, "");
        }
    }
}
