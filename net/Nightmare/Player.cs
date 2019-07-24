using System.Collections.Generic;

namespace Nightmare {
    public class Player : Users {
        public List<Profession> classes = new List<Profession>
        {
            new Warrior(),
            new Paladin(),
            new Wizard(),
            new Rouge(),
            new Barbarian(),
        };

        public Stats Stats;
        public int Life;
        public int Stamina;
        public Profession Class;
        public int LevelPoints  { get; set; }
        public int MaxLife { get; set; }
        public int MaxStamina { get; set; }


        // Set player class 
        public void SetClass(Profession profession) {
            Class = profession;
            Stats = profession.Stats;

            Life = MaxLife = (int)(100 * profession.HpModificator);
            Stamina = MaxStamina = (int)(100 * profession.SpModificator);
        }
    }
}