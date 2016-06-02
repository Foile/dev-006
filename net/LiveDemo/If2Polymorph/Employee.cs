using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace If2Polymorph
{
    class Employee
    {
        public int Workhours {get;set;}
       public int GetBonus(int yearOfJob)
        {
            int result=0;
            switch(typeOfEmployee)
            {
                case 1:
                     result = Workhours * 10;
                     break;
                case 2:
                     result = Workhours * 5 + 2;
                     break;
                case 3:
                     result = Workhours * 10 / 2;
                     break;                     
            }
           result += Workhours*2 * typeOfEmployee;
           return result;
        }
    }
}
