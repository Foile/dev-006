using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TemplateMethod
{
    class Program
    {
        static void Main(string[] args)
        {
            Salesman Ivan = new Salesman();
            Engineer Stepan = new Engineer();

            Console.WriteLine(Ivan.CalcuteBonus());
            Console.WriteLine(Stepan.CalcuteBonus());
        }
    }
}
