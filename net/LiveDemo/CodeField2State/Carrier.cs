using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeField2State
{
    class Carrier
    {
        private Employee _employee;
        int Stage;
        public Carrier()
        {
            Stage = 0;
            _employee = new SalesMan() { WorkHours = 30 };
        }
        public int GetSalary()
        {
            int salary =  _employee.GetSalary();
            ChangeStage();
            return salary;
        }
        private void ChangeStage()
        {
            Stage++;
            switch(Stage)
            {
                case 3 :
                    _employee = new Engineer() { WorkHours = 100 };
                    break;
                case 5:
                    _employee = new Manager() { WorkHours = 50 };
                    break;
                case 7:
                    _employee = new Director() { WorkHours = 20 };
                    break;
            }
        }
    }
}
