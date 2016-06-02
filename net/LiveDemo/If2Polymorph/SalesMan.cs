using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace If2Polymorph
{
    class SalesMan : Employee
    {
        
        public override int GetBonus(int yearOfJob)
        {
            int result;
            result = Workhours * KNOWLEDGE_LEVEL + DANGEROUS_JOB;
            result = ExtraBonus(yearOfJob, result);
            return result;
        }
    }
}
