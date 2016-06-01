using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TemplateMethod
{
    class Salesman : Employee
    {
        public override double Sales()
        {
            return 100; // сумма продаж, может сложно вычисляться
        }
        public override double StageOfWork()
        {
            return 2;//здесь может сложное вычисление стажа работы
        }
        public override double SalesLevel()
        {
            return 3; //уровень продаж может сложно вычисляться
        }
        public override double LikeBonus()
        {
            return new Random().Next(30);
        }
    }
}
