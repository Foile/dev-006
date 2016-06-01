using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Decorator
{
    class Program
    {
        static void Main(string[] args)
        {
           IStream stream = new Compressor
               (new Xor(new Base64(new MemStream())));
            Console.WriteLine(stream.GetBuffer("qwerty"));
            IStream stream2 = new Xor
              (new Compressor(new Base64(new MemStream())));
            Console.WriteLine(stream2.GetBuffer("qwerty"));

            IStream base64stream = new Base64(new MemStream());
            Console.WriteLine(base64stream.GetBuffer("@@@@@@"));
        }
    }
}
