using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Decorator
{
    class MemStream : IStream
    {
        

        public String GetBuffer(String aBuffer)
        {
            return aBuffer;
        }
    }
}
