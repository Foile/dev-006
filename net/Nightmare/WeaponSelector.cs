namespace Nightmare {
    public class WeaponSelector {
        private Weapon weapon;

        public Weapon Generate(string name, Game game) {
            var weaponGenerator = new WeaponGenerator();
            var flag = true;

            if (name == "Any") {
                return weaponGenerator.Generate(game.Character);
            }

            do {
                weapon = weaponGenerator.Generate(game.Character);
                if (weapon.Mace) {
                    flag = name.ToLower() == "mace";
                }
                if (weapon.Sword) {
                    flag = name.ToLower() == "sword";
                }
                if (weapon.Dagger) {
                    flag = name.ToLower() == "dagger";
                }
                if (weapon.Staff) {
                    flag = name.ToLower() == "staff";
                }
                if (weapon.Bow) {
                    flag = name.ToLower() == "bow";
                }
            } while (!flag);

            return weapon;
        }
    }
}