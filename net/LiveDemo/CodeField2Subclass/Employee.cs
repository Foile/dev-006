using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace CodeField2Subclass
{
    abstract  class Employee
    {
        public const int ENGINEER = 0;
        public const int SALESMAN = 1;
        public const int MANAGER = 2;
        

        public int Role { get; private set; }
        public int WorkHours { get; private set; }

        protected Employee(int aType,int aHours)
        {
            Role = aType;
            WorkHours = aHours;
        }

        public abstract int GetSalary();
        //{//на самом деле здесь очень очень сложные расчеты для каждого типа работника
        //    //switch (Role)
        //    //{
        //    //    case ENGINEER:
        //    //        return 200*WorkHours;
        //    //    case SALESMAN:
        //    //        return 100*WorkHours;
        //    //    case MANAGER:
        //    //        return 300*WorkHours;
        //    //    default:
        //            throw new NotImplementedException("Неверный код типа работника");
        //    //}
        //}

        public static Employee Create(int type,int aHours)
        {
            switch (type)
            {
                case ENGINEER:
                    return new Engineer(aHours);
                case MANAGER:
                    return new Manager(aHours);
                case SALESMAN:
                    return new SalesMan(aHours);
                default:
                    throw new NotImplementedException("неверный тип работника");
                
            }
        }
    }
}
