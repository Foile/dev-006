using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeField2State
{
    class Program
    {
        static void Main(string[] args)
        {
            Carrier Stepan = new Carrier();
            for(int year = 1;year <= 12; year++)
            {
                Console.WriteLine("{0} year of work with salary {1}",
                    year, Stepan.GetSalary());
            }
        }
    }
}
