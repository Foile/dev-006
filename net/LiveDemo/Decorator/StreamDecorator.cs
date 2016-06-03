using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Decorator
{
    class StreamDecorator : IStream
    {
        private IStream _original;

        protected StreamDecorator(IStream next)
        {
            _original = next;
        }
        virtual public string GetBuffer()
        {
            return _original.GetBuffer();
        }
    }
}
