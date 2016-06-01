using System.Collections.Generic;
using System.Linq;

namespace Nightmare {
    public class Character {
        public List<Item> Bag = new List<Item>();
        /// <summary>
        /// The player
        /// </summary>
        public Player Player { get; set; }
        /// <summary>
        /// The Level of player
        /// </summary>
        public decimal Level { get; set; }
        /// <summary>
        /// Current experience
        /// </summary>
        public decimal Xp { get; set; }

        public Character() {
            Level = 1;
        }

        public string PrintDices(List<int> dices) {
            return string.Join(":", dices);
        }

        public List<Attack> Attack() {
            var weapons = new List<Weapon>();
            var shields = new List<Shield>();
            var wears = new List<Wear>();

            foreach (var item in Bag) {
                if (item.Type == "W") {
                    var weapon = ((Weapon) item);
                    if (!weapon.Equiped == false) {
                        weapons.Add(weapon);
                    }
                }
                if (item.Type == "S") {
                    var shield = ((Shield) item);
                    if (!shield.Equiped == false) {
                        shields.Add(shield);
                    }
                }
                if (item.Type == "Wr") {
                    var wear = ((Wear) item);
                    if (wear.Equiped == false) {
                        wears.Add(wear);
                    }
                }
            }


            var attack = new Attack {
                // power consist of a number different variable and parameters. The main of them and the basement is 
                // the Attack parameter. Then it should be summarized with bonus power depends on level.
                // Finally it adds attack abilities from wears. 
                Power = (int) (weapons.Sum(i => i.Attack) + weapons.Sum(i => i.Attack)*Level*0.5m + wears.Sum(i => i.Attack) + wears.Sum(i => i.Attack)*Level*0.2m),
                Defence = (int) (shields.Sum(i => i.Defence) + shields.Sum(i => i.Defence)*Level*0.5m + wears.Sum(i => i.Defence) + wears.Sum(i => i.Defence)*Level*0.2m),
                Special = 0
            };

            return new List<Attack> {attack};
        }

        public void Equip(Weapon weapon) {
            var result = weapon.CanWearFor(Player);
            if (result) {
                weapon.Equiped = true;
            }
        }

        // Fill Life
        public void FillLife(Character character) {
            character.Player.Life = character.Player.MaxLife;
        }

        public void FillStamina(Character character) {
            character.Player.Stamina = character.Player.MaxStamina;
        }

        public void Equip(Wear wear) {
            var result = wear.CanWearFor(Player);
            if (result) {
                wear.Equiped = true;
            }
        }

        public void Equip(Shield shield) {
            var result = shield.CanWearFor(Player);
            if (result) {
                shield.Equiped = true;
            }
        }
    }
}