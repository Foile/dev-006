using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Decorator
{
    class Xor : IStream
    {
        private IStream stream;

        public Xor(IStream aStream)
        {
            stream = aStream;
        }
        public string GetBuffer(string aBuffer)
        {
            return "^" + stream.GetBuffer(aBuffer);
        }
    }
}
