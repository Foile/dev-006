using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TemplateMethod
{
    class Engineer : Employee
    {
        public override double Sales()
        {
            return 0;
        }
        public override double StageOfWork()
        {
            return 1;
        }
        public override double SalesLevel()
        {
            return 0;
        }
        public override double LikeBonus()
        {
            return new System.Random().Next(1000)+100;
        }
    }
}
