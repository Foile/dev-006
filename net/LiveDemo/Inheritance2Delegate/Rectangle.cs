using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Inheritance2Delegate
{
    class Rectangle 
    {
        private Shape shape;

        public Rectangle(Shape aShape)
        {
            shape = aShape;
        }
        public  void draw()
        {
            shape.draw();//вызов метода базового класса
            Console.WriteLine("Rectangle");
        }
    }
}
