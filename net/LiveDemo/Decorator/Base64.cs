using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Decorator
{
    class Base64 : IStream
    {
        private IStream stream;

        public Base64(IStream aStream )
        {
            stream = aStream;
        }
        public string GetBuffer(string aBuffer)
        {
            return "==" + stream.GetBuffer(aBuffer);
        }
    }
}
