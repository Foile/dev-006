using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using NullObject;

namespace CodeField2State
{
    class Director : EmployeeType
    {
        public Director() : base(EmployeeType.DIRECTOR.Role, 200)
        {

        }

        public override int GetSalary()
        {
            return WorkHours*60;
        }

    }
}
