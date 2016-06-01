using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PropertyQuestion
{
    class Program
    {
        static void Main(string[] args)
        {
            var foo = new Foo();
            foo.Sample = 5;
            foo.print();

        }
    }
}
