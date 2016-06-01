using System;
using System.Windows.Forms;

namespace Nightmare {
    public partial class Form1 : Form {
        public Users User;
        private Character character;
        private Game game;

        public Form1() {
            InitializeComponent();
            var loginForm = new LoginForm(this);
            loginForm.Show();
            loginForm.Closed += (sender, args) => { label1.Text = "Welcome " + User.Login; };
        }

        public Player MainStatistic { get; set; }

        private void button14_Click(object sender, EventArgs e) {
            var newGame = new NewGame(this);
            newGame.Show();

            newGame.Closing += (o, args) => {
                character = new Character();
                character.Player = MainStatistic;

                textBox1.Text = character.Player.Stats[0].ToString();
                textBox2.Text = character.Player.Stats[1].ToString();
                textBox3.Text = character.Player.Stats[2].ToString();
                textBox4.Text = character.Player.Stats[3].ToString();
                textBox5.Text = character.Player.Stats[4].ToString();
                textBox6.Text = character.Player.Stats[5].ToString();
                textBox7.Text = character.Player.Stats[6].ToString();

                PlayerClass.Text = character.Player.Class;

                game = new Game();
                game.LevelUp(character, this);
            };
        }

        private void button13_Click(object sender, EventArgs e) {
            var dices = game.Dices(character.Player);
            var printDices = character.PrintDices(dices);
            label14.Text = printDices;
        }

        public void NewLevel() {
            addStr.Visible = true;
            remStr.Visible = true;
            addPer.Visible = true;
            remPer.Visible = true;
            addEnd.Visible = true;
            remEnd.Visible = true;
            addChr.Visible = true;
            remChr.Visible = true;
            addInt.Visible = true;
            remIntel.Visible = true;
            plusAdility.Visible = true;
            delAgl.Visible = true;
            addLck.Visible = true;
            remLck.Visible = true;

            pointsLabel.Visible = points.Visible = true;

            points.Text = character.Player.LevelPoints.ToString();

            character.Level++;
            Level.Text = "Level " + character.Level;
        }

        private void addStr_Click(object sender, EventArgs e) {
            if (int.Parse(points.Text) > 0) {
                var i = int.Parse(textBox1.Text);
                textBox1.Text = (i + 1).ToString();
                points.Text = (int.Parse(points.Text) - 1).ToString();
            }
        }

        private void remStr_Click(object sender, EventArgs e) {
            if (int.Parse(points.Text) < 5) {
                var i = int.Parse(textBox1.Text);
                textBox1.Text = (i - 1).ToString();
                points.Text = (int.Parse(points.Text) + 1).ToString();
            }
        }

        private void addPer_Click(object sender, EventArgs e) {
            if (int.Parse(points.Text) > 0) {
                var i = int.Parse(textBox2.Text);
                textBox2.Text = (i + 1).ToString();
                points.Text = (int.Parse(points.Text) - 1).ToString();
            }
        }

        private void remPer_Click(object sender, EventArgs e) {
            if (int.Parse(points.Text) < 5) {
                var i = int.Parse(textBox2.Text);
                textBox2.Text = (i - 1).ToString();
                points.Text = (int.Parse(points.Text) + 1).ToString();
            }
        }

        private void addEnd_Click(object sender, EventArgs e) {
            if (int.Parse(points.Text) > 0) {
                var i = int.Parse(textBox3.Text);
                textBox3.Text = (i + 1).ToString();
                points.Text = (int.Parse(points.Text) - 1).ToString();
            }
        }

        private void remEnd_Click(object sender, EventArgs e) {
            if (int.Parse(points.Text) < 5) {
                var i = int.Parse(textBox3.Text);
                textBox3.Text = (i - 1).ToString();
                points.Text = (int.Parse(points.Text) + 1).ToString();
            }
        }

        public void EndLevel()
        {
            addStr.Visible = false;
            remStr.Visible = false;
            addPer.Visible = false;
            remPer.Visible = false;
            addEnd.Visible = false;
            remEnd.Visible = false;
            addChr.Visible = false;
            remChr.Visible = false;
            addInt.Visible = false;
            remIntel.Visible = false;
            plusAdility.Visible = false;
            delAgl.Visible = false;
            addLck.Visible = false;
            remLck.Visible = false;

            pointsLabel.Visible = points.Visible = false;
        }
    }
}