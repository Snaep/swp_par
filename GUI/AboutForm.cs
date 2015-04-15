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
    public partial class AboutForm : Form {
        public AboutForm() {
            InitializeComponent();
        }

        private void AboutForm_Paint( object sender, PaintEventArgs e ) {
            Rectangle r = new Rectangle(this.Width / 4, 0, this.Width / 2, this.Width / 2);
            //e.Graphics.DrawImage( someimage, r );
        }
    }
}
