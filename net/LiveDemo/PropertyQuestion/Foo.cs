using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PropertyQuestion
{
    class Foo
    {
        private int sample;

        public int Sample { get; set; }

        public void print()
        {
            Console.WriteLine(sample);
            Console.WriteLine(Sample);
        }
    }

}
