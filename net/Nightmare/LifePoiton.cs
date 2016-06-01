namespace Nightmare {
    public class LifePoiton : Item {
        public void Use(Character character) {
            new ExpierenceService().FillLife(character);
        }
    }
}