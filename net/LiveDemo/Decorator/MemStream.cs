using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Decorator
{
    class MemStream : IStream
    {
        private String _Buffer;
        public MemStream(String Buffer)
        {
            _Buffer = Buffer;
        }
        virtual public String GetBuffer()
        {
            return _Buffer;
        }
    }
}
