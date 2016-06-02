using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace If2Polymorph
{
    class Program
    {
        static void Main(string[] args)
        {
            Employee Ivan = new Employee() { Workhours = 5};
            Console.WriteLine(Ivan.GetBonus(1));
            Console.WriteLine(Ivan.GetBonus(2));
            Console.WriteLine(Ivan.GetBonus(3));
        }
    }
}
