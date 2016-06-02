using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace If2Polymorph
{
    class Director : Employee
    {
        
        public override int GetBonus(int yearOfJob)
        {
            int result;
            result = Workhours * DIFFICULT_JOB / TIME_FOR_OFFICE;
            result = ExtraBonus(yearOfJob, result);
            return result;
        }
    }
}
