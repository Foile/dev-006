using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeField2State
{
    class Director : Employee
    {
        public Director() 
        {

        }

        public override int GetSalary()
        {
            return WorkHours*60;
        }

    }
}
