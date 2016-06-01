using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Inheritance2Delegate
{
    class EllipseInRectangle
    {
        private Rectangle rectangle;

        public EllipseInRectangle(Rectangle aRectangle)
        {
            rectangle = aRectangle;
        }

        public void draw()
        {
            rectangle.draw();
            Console.WriteLine("EllipseInRectangle");
        }
    }
}
