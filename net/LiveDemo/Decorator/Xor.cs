using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Decorator
{
    class Xor : StreamDecorator
    {
         public Xor(IStream aStream) : base(aStream)
        {
            
        }
        override public string GetBuffer()
        {
            return "^" + base.GetBuffer();
        }
    }
}
