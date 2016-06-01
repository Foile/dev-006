using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeField2Strategy
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
