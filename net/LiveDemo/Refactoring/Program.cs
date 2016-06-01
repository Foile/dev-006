using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Refactoring
{
    class Program
    {
        static void Main(string[] args)
        {
            Order order = new Order(new Customer("Вася"));
        }
    }
}
