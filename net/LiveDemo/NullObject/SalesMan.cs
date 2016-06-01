namespace NullObject
{
    class SalesMan : EmployeeType
    {
        public SalesMan() : base(EmployeeType.SALESMAN.Role,100)
        {
                
        }
        public override int GetSalary()
        {
            return 30*WorkHours;
        }

        public override EmployeeType Promotion()
        {
            return new Engineer();
        }
    }
}
