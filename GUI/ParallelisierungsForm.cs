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
    public partial class ParallelisierungsForm : Form {
        public ParallelisierungsForm() {
            InitializeComponent();
        }

        //TODO:implement.
        internal string GetParameter() {
            //no parallelization
            return "-par=0 ";
        }
    }
}
