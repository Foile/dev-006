using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StepByStep
{
    public class Customer
    {
        private List<Rental> _rentals = new List<Rental>();
        private String _name;

        public Customer(String name)
        {
            _name = name;
        }

        public void addRental(Rental arg)
        {
            _rentals.Add(arg);
        }

        public List<StepByStep.Rental> Rental
        {
            get
            {
                return _rentals;
            }
        }

        public void statement()
        {
            double totalAmount = 0;
            int frequentRenterPoints = 0;
            String result = "Учет аренды для" + _name + "\n";

            IEnumerator<Rental> rentals = _rentals.GetEnumerator();
            while (rentals.MoveNext())
            {                
                Rental each = rentals.Current;                
                //добавить очки для активного арендатора
                frequentRenterPoints++;
                //бонус за аренду новинки на два дня
                if (each.Movie.getPriceCode() == Movie.NEW_RELEASE && each.getDaysRented() > 1)
                    frequentRenterPoints++;
                result += "\t" + each.Movie.Title+ "\t" + each.getCharge() + "\n";
                totalAmount += each.getCharge();
            }
            //добавить нижний колонтитул
            result += "Сумма задолженности составляет" +totalAmount + "\n";
            result += "Вы заработали " + frequentRenterPoints + "очков за активность";
        }
    }
}
