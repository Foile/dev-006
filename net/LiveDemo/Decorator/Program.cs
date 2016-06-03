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
               (new Xor(new Base64(new MemStream("qwerty"))));
            Console.WriteLine(stream.GetBuffer());
            IStream stream2 = new Xor
              (new Compressor(new Base64(new MemStream("qwerty"))));
            Console.WriteLine(stream2.GetBuffer());

            IStream base64stream = new Base64(new MemStream("qwerty"));
            Console.WriteLine(base64stream.GetBuffer());
        }
    }
}
