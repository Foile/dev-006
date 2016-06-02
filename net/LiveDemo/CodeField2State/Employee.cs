using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeField2State
{
    abstract class Employee
    {
        public int TabNumber { get; set; }
        public String Title { get; set; }
        public int WorkHours { get; set; }
        abstract public int GetSalary();        
    }
}
