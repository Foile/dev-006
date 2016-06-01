using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StepByStep
{
    public class Rental
    {
        private Movie _movie;
        private int _daysRented;

        public Rental(Movie movie, int daysRented)
        {
            throw new NotImplementedException();
        }
    
        public Movie Movie
        {
            get
            {
                return _movie;
            }
            set
            {
                _movie = value;;
            }
        }

        public int getDaysRented()
        {
            return _daysRented;
        }

        public double getCharge()
        {
            double result=0;
//определить сумму для каждой строки
            switch (Movie.getPriceCode())
            {
                case Movie.REGULAR:
                    result += 2;
                    if (getDaysRented() > 2)
                    {
                        result += (getDaysRented() - 2)*15;
                    }
                    break;
                case Movie.NEW_RELEASE:
                    result += getDaysRented()*3;
                    break;
                case Movie.CHILDRENS:
                    result += 15;
                    if (getDaysRented() > 3)
                    {
                        result += (getDaysRented() - 3)*15;
                    }
                    break;
            }
            return result;
        }
    }
}
