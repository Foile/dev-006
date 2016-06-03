using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Decorator
{
    class Compressor : StreamDecorator
    {
         public Compressor(IStream aStream) : base(aStream)
        {
            
        }

        public override String GetBuffer()
        {           
            return  "**" +base.GetBuffer() + "**";
        }
    }
}
