using CodeField2State;

namespace NullObject
{
    class Manager : EmployeeType
    {
        public Manager() : base(EmployeeType.MANAGER.Role,30)
        {
                
        }

        public override int GetSalary()
        {
            return 100*WorkHours;
        }

        public override EmployeeType Promotion()
        {
            return new Director();
        }
    }
}
