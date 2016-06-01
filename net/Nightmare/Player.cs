using System.Collections.Generic;

namespace Nightmare {
    public class Player : Users {
        public Dictionary<string, List<int>> classes = new Dictionary<string, List<int>> {
            {"Warrior", new List<int>   {8, 6, 7, 9, 7, 9, 8}},
            {"Paladin", new List<int>   {9, 5, 8, 11, 5, 6, 2}},
            {"Wizard", new List<int>    {3, 9, 4, 6, 11, 5, 5}},
            {"Rouge", new List<int>     {6, 11, 8, 4, 8, 9, 6}},
            {"Barbarian", new List<int> {11, 5, 6, 3, 5, 6, 5}}
        };

        public Dictionary<string, List<decimal>> life = new Dictionary<string, List<decimal>> {
            {"Warrior", new List<decimal> {1, 1}},
            {"Paladin", new List<decimal> {1, 1.2m}},
            {"Wizard", new List<decimal> {0.3m, 0.6m}},
            {"Rouge", new List<decimal> {0.7m, 1.7m}},
            {"Barbarian", new List<decimal> {1.5m, 0.9m}}
        };

        public List<int> Stats;
        public int Life;
        public int Stamina;
        public string Class;
        public int LevelPoints  { get; set; }
        public int MaxLife { get; set; }
        public int MaxStamina { get; set; }


        // Set player class 
        public void SetClass(string name) {
            Class = name;
            Stats = classes[name];

            Life = MaxLife = (int)(100*life[name][0]);
            Stamina = MaxStamina = (int)(100*life[name][1]);
        }
    }
}