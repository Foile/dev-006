using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace If2Polymorph
{
    abstract class Employee
    {
       protected const int DIFFICULT_JOB = 10;
       protected const int DANGEROUS_JOB = 2;
       protected const int TIME_FOR_OFFICE = 2;
       protected const int KNOWLEDGE_LEVEL = 5;
       public int Workhours {get;set;}
       abstract public int GetBonus(int yearOfJob);
       protected int ExtraBonus(int yearOfJob, int result)
        {
            result += Workhours * TIME_FOR_OFFICE * yearOfJob;
            return result;
        }
    }
}
