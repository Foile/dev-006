using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Inheritance2Delegate
{
    class Program
    {
        static void Main(string[] args)
        {
            EllipseInRectangle ellipseInRectangle = 
                new EllipseInRectangle(new Rectangle(new Shape()));
            ellipseInRectangle.draw();
        }
    }
}
