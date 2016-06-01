using System;

namespace Nightmare {
    public class WeaponGenerator {
        public Weapon Generate(Character character) {
            var random = new Random();
            var weapon = new Weapon();

            var value = random.Next(5);
            switch (value) {
                case 0:
                    weapon.Mace = true;
                    break;
                case 1:
                    weapon.Sword = true;
                    break;
                case 2:
                    weapon.Dagger = true;
                    break;
                case 3:
                    weapon.Staff = true;
                    break;
                case 4:
                    weapon.Bow = true;
                    break;
            }

            value = (int)(random.Next(10)*character.Level);
            weapon.Attack = value;

            return weapon;
        }
    }
}