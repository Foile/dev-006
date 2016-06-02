using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeField2State
{
    class Manager : Employee
    {
        public Manager() 
        {
                
        }

        public override int GetSalary()
        {
            return 100*WorkHours;
        }

    }
}
