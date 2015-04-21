using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GUI {
    public partial class ParserForm : Form {
        public ParserForm() {
            InitializeComponent();
            this.textBox2.Text = Clipboard.GetText();
        }

        private void textBox_TextChanged( object sender, EventArgs e ) {
            if(this.textBox1.Text != "" && this.textBox2.Text != "") {
                try {
                    this.grid = Sudoku.Parse( this.textBox2.Text, this.textBox1.Text );
                    if( this.grid != null ) this.pictureBox1.Image = this.grid.ToImage();
                } catch { }
            }
        }



        internal static Sudoku GetGrid() {
            ParserForm pf = new ParserForm();
            pf.ShowDialog();
            return pf.grid;
        }

        internal Sudoku grid { get; set; }
    }
}
