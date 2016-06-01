using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TemplateMethod
{
    abstract class Employee
    {
        public String Title { get; private set; }
        public int TabNumber { get; private set; }

        public abstract double SalesLevel();
        public abstract double StageOfWork();
        public abstract double LikeBonus();
        public abstract double Sales();
        public double CalcuteBonus()
        {
            return (SalesLevel() * StageOfWork() + 
                Sales()) * LikeBonus();
        }
    }
}
