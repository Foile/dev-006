using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nightmare
{
    public class Stats
    {
        public Stats(int strength, int perception, int endurance, int charisma, int intelligence, int agility, int luck)
        {
            Strength = strength;
            Perception = perception;
            Endurance = endurance;
            Charisma = charisma;
            Intelligence = intelligence;
            Agility = agility;
            Luck = luck;
        }

        public int Strength { get; }
        public int Perception { get; }
        public int Endurance { get; }
        public int Charisma { get; }
        public int Intelligence { get; }
        public int Agility { get; }
        public int Luck { get; }
    }
}
