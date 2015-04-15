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
    public partial class Form1 : Form {
        public Form1() {
            InitializeComponent();

            this.toolStripTextBox1.Text = "9";
            this.defaultLength = 9;
            this.openFile = null;
        }

        private string openFile;
        private int defaultLength;
        private Sudoku sGridPreset, sGridSolved;

        #region MenuStrip
        #region MENU
        private void neuGenerierenToolStripMenuItem_Click( object sender, EventArgs e ) {
            this.sGridPreset = new Sudoku( this.defaultLength );
            this.openFile = null;
            this.PlaceSudoku();
        }

        private void oeffnenToolStripMenuItem_Click( object sender, EventArgs e ) {
            this.openFileDialog1.ShowDialog();
        }

        private void speichernToolStripMenuItem_Click( object sender, EventArgs e ) {
            if( this.openFile == null ) this.saveFileDialog1.ShowDialog();
            else this.sGridPreset.SaveToFile( this.openFile );
        }

        private void speichernUnterStripMenuItem2_Click( object sender, EventArgs e ) {
            this.saveFileDialog1.ShowDialog();
        }

        //copy
        private void toolStripMenuItem1_Click( object sender, EventArgs e ) {
            if(this.sGridPreset == null) return;
            
            Clipboard.SetText( this.sGridPreset.ToString() );
        }

        //paste
        private static char[] delimiter = new char[]{ ' ', '\t', '|', ',', '.', ':', ';', '-', '_' };
        private void toolStripMenuItem2_Click( object sender, EventArgs e ) {
            Sudoku grid = null;
            foreach( char d in Form1.delimiter ) {
                try {
                    grid = Sudoku.Parse( Clipboard.GetText(), d );
                    if( grid != null ) break;
                } catch {
                }
            }
            if( grid == null ) MessageBox.Show( "Fehler beim lesen der Eingabe.", "Fehler" );
            else {
                this.sGridPreset = grid;
                this.PlaceSudoku();
            }
        }

        private void beendenToolStripMenuItem_Click( object sender, EventArgs e ) {
            //kill solver process
            //delete solver output file if exists
            //exit
            this.Close();
        }
        #endregion

        #region SUDOKU
        private void toolStripTextBox1_KeyDown( object sender, KeyEventArgs e ) {
            if( e.KeyCode == Keys.Enter ) {
                try {
                    int input = int.Parse( this.toolStripTextBox1.Text );
                    int sqinp = ( int )Math.Sqrt( input );

                    if( input != sqinp * sqinp ) throw new Exception();

                    this.defaultLength = input;

                    this.sGridPreset = new Sudoku( this.defaultLength );
                    this.PlaceSudoku();
                } catch {
                    this.toolStripTextBox1.Text = "" + this.defaultLength;
                }
            }
        }

        //schwierigkeit
        private void leichtToolStripMenuItem_Click( object sender, EventArgs e ) {
            this.normalToolStripMenuItem.Checked = false;
            this.schwerToolStripMenuItem.Checked = false;
            this.leichtToolStripMenuItem.Checked = true;
        }

        private void normalToolStripMenuItem_Click( object sender, EventArgs e ) {
            this.normalToolStripMenuItem.Checked = true;
            this.schwerToolStripMenuItem.Checked = false;
            this.leichtToolStripMenuItem.Checked = false;
        }

        private void schwerToolStripMenuItem_Click( object sender, EventArgs e ) {
            this.normalToolStripMenuItem.Checked = false;
            this.schwerToolStripMenuItem.Checked = true;
            this.leichtToolStripMenuItem.Checked = false;
        }


        private void generierenToolStripMenuItem_Click( object sender, EventArgs e ) {
            string dir = this.toolStripTextBox1.Text + 'x' + this.toolStripTextBox1.Text + '_';
            if( this.normalToolStripMenuItem.Checked ) dir += 'n';
            else if( this.leichtToolStripMenuItem.Checked ) dir += 'l';
            else dir += 's';

            var files = new System.IO.DirectoryInfo( dir ).GetFiles();

        }

        private void lösenToolStripMenuItem_Click( object sender, EventArgs e ) {

        }
        #endregion

        #region LÖSUNG
        private void strategienToolStripMenuItem_Click( object sender, EventArgs e ) {

        }

        private void parallelisierungToolStripMenuItem_Click( object sender, EventArgs e ) {

        }
        #endregion
   
        #region INFO

        private void überToolStripMenuItem_Click( object sender, EventArgs e ) {
            //show AboutForm Dialog
            new AboutForm().ShowDialog();
        }

        #endregion



        #endregion

        private void PlaceSudoku() {
            this.pictureBox1.Image = this.sGridPreset.ToImage( 30 );
            this.toolStripTextBox1.Text = this.sGridPreset.Length + "";
            this.RePlaceSudoku();
        }

        private void RePlaceSudoku() {
            int x, y;

            if( this.pictureBox1.Image == null ) return;

            if( this.pictureBox1.Image.Width < this.panel1.Width ) x = ( panel1.Width - this.pictureBox1.Width ) / 2;
            else x = 0;

            if( this.pictureBox1.Image.Height < this.panel1.Height ) y = ( panel1.Height - this.pictureBox1.Height ) / 2;
            else y = 0;

            this.pictureBox1.Location = new Point( x, y );
        }

        private void panel1_SizeChanged( object sender, EventArgs e ) {
            this.RePlaceSudoku();
        }
             
        private void openFileDialog1_FileOk( object sender, CancelEventArgs earg ) {
            try {
                this.sGridSolved = null;
                this.sGridPreset = new Sudoku( this.openFileDialog1.FileName );
                this.openFile = this.openFileDialog1.FileName;
                this.PlaceSudoku();
            } catch( Exception e ) {
                MessageBox.Show( e.ToString(), e.Source, MessageBoxButtons.OK, MessageBoxIcon.Error );
            }
        }

        private void saveFileDialog1_FileOk( object sender, CancelEventArgs e ) {
            this.sGridPreset.SaveToFile( this.saveFileDialog1.FileName );
        }

    }
}
