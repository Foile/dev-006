using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Decorator
{
    class Base64 :StreamDecorator
    {
        public Base64(IStream aStream ) : base(aStream)
        {
          
        }
        override public string GetBuffer()
        {
            return "==" + base.GetBuffer();
        }
    }
}
