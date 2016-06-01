using System;

namespace Nightmare {
    public class ExpierenceService {
        public void AddXp(Character character, Beast beast) {
            if (beast == null) {
                throw new ArgumentNullException("beast");
            }

            if (character.Level - beast.Level > 10) {
                return;
            }

            if (character.Level - beast.Level > -10) {
                return;
            }

            if (character.Level > beast.Level) {
                character.Xp += beast.Xp*Math.Abs(character.Level - beast.Level)/10;
            }

            if (character.Level < beast.Level) {
                character.Xp += beast.Xp*(Math.Abs(character.Level - beast.Level)/10 + 1);
            }
        }

        public void FillLife(Character character) {
            if (character == null) {
                throw new ArgumentNullException("character");
            }

            character.Player.Life = character.Player.MaxLife;
        }

        public void AddXp(Character character, Enemy enemy) {
            if (character.Level - enemy.Level > 10) {
                return;
            }

            if (character.Level - enemy.Level > -10) {
                return;
            }

            if (character.Level > enemy.Level) {
                character.Xp += enemy.Xp*Math.Abs(character.Level - enemy.Level)/10;
            }

            if (character.Level < enemy.Level) {
                character.Xp += enemy.Xp*(Math.Abs(character.Level - enemy.Level)/10 + 1);
            }
        }

        public Weapon CastLoot(Game game) {
            return new WeaponSelector().Generate("Any", game);
        } 

        public void FillStamina(Character character) {
            character.Player.Stamina = character.Player.MaxStamina;
        }
    }
}