using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ReplaceDataValueToObject
{
    class Program
    {
        static void Main(string[] args)
        {
            Currency currency = 
                new Currency("USD",111);
            Currency currency2 = new Currency("USD",111);
            if (currency.Equals(currency2))
            {
                Console.WriteLine("USD");
                Console.WriteLine(currency.GetHashCode());
                Console.WriteLine(currency2.GetHashCode());
            }
            else
            {
                Console.WriteLine("Ooops!");
            }
            if (currency == currency2)
            {
                Console.WriteLine("Ok!");
            }
            else
            {
                Console.WriteLine("Ooops!");
            }
        }
    }
}
