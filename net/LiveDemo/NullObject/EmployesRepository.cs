using CodeField2State;

namespace NullObject
{
    //имитация репозитория объектов в базе данных
    class EmployesRepository
    {
        private int count = 0;
        public Employee GetEmployee()
        {
            switch (count)
            {
                case 0:
                    count++;
                    return Employee.Create(EmployeeType.DIRECTOR);
                case 1:
                    count++;
                    return Employee.Create(EmployeeType.ENGINEER);
                case 2:
                case 3:
                    count++;
                    return Employee.Create(EmployeeType.UNKNOWN);
                case 4:
                    count = 0;
                    return Employee.Create(EmployeeType.SALESMAN);
                default:
                    return Employee.Create(EmployeeType.UNKNOWN);
            }
        }
    }
}
