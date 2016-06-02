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
            Employee Ivan = new Engineer() { Workhours = 5};
            Employee Stepan = new SalesMan() {Workhours = 5};
            Employee IvanIvanovich = new Director() {Workhours = 5};
            Console.WriteLine(Ivan.GetBonus(1));
            Console.WriteLine(Stepan.GetBonus(2));
            Console.WriteLine(IvanIvanovich.GetBonus(3));
        }
    }
}
