using System.Collections.Generic;
using System.Linq;

namespace Nightmare {
    public abstract class Flying : Enemy {
        protected Flying() {
            BaseAttack = 50;
            Defence = 200;
        }
    }

}