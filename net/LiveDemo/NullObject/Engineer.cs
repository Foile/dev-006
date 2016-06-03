using CodeField2State;

namespace NullObject
{
    class Engineer : EmployeeType
    {
        public Engineer() :base(EmployeeType.ENGINEER.Role,20)
        {
                
        }
        public override int GetSalary()
        {
            return 20*WorkHours;
        }

        public override EmployeeType Promotion()
        {
            return new Manager();
        }
    }
}
