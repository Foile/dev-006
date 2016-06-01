using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Decorator
{
    class Compressor : IStream
    {
        private IStream stream;


        public Compressor(IStream aStream)
        {
            stream = aStream;
        }

        public String GetBuffer(string aBuffer)
        {           
            return  "**" +stream.GetBuffer(aBuffer) + "**";
        }
    }
}
