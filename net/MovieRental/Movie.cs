using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StepByStep
{
    public class Movie
    {
        private int _priceCode;
        private String _title;
        public const int REGULAR = 0;
        public const int NEW_RELEASE = 1;
        public const int CHILDRENS = 2;

        public Movie(String title, int price)
        {
            _title = title;
            _priceCode = price;
        }

        public int getPriceCode()
        {
            return _priceCode;
        }

        public void setPriceCode(int arg)
        {
            _priceCode = arg;
        }

        public String Title
        {
            get
            {
                return _title;
            }
        }
    }
}